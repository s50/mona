/*
 *   Copyright (c) 2011  Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _TERMINAL_
#define _TERMINAL_

#include "TextFieldWithHistory.h"
#include <monapi/StringHelper.h>
#include <algorithm>
#include <string>

#define START_UP_FILE "/USER/.STARTUP"

struct TerminalInfo
{
    TerminalInfo() : mainThread(MonAPI::System::getThreadID())
    {
    }
    ~TerminalInfo()
    {
    }
    MonAPI::Stream outStream;
    std::string sharedString;
    uint32_t mainThread;
};

class Terminal : public Frame
{
protected:
    MonAPI::scoped_ptr<TextField> command_;
    MonAPI::scoped_ptr<TextField> output_;
    MonAPI::scoped_ptr<Button> button_;
    MonAPI::scoped_ptr<Scrollbar> scrollbar_;
    TerminalInfo& terminalInfo_;
    MonAPI::Strings lines_;
    uintptr_t currentLineNo_;
    uintptr_t outputNumRows_;

    enum
    {
        OUTPUT_HIGHT = 340,
        OUTPUT_WIDTH = 270,
        COMMAND_INPUT_WIDTH = 250,
        forbidden_comma
    };

public:
    Terminal(TerminalInfo& terminalInfo) :
        command_(new TextFieldWithHistory("/USER/HISTORY2.TXT")),
        output_(new TextField()),
        button_(new Button("go")),
        scrollbar_(new Scrollbar()),
        terminalInfo_(terminalInfo),
        currentLineNo_(0)
    {
        const int EXTRA_WIDTH = 350;
        setBounds(80, 100, 300 + EXTRA_WIDTH, 400);
        setTitle("Terminal");
        command_->setText("help");

        int height = getFontMetrics()->getHeight("H");
        outputNumRows_ = OUTPUT_HIGHT / height - 3;

        command_->setBounds(0, 0, COMMAND_INPUT_WIDTH + EXTRA_WIDTH, 30);
        command_->setFontStyle(Font::FIXED);
        output_->setBounds(0, 30, OUTPUT_WIDTH + EXTRA_WIDTH, OUTPUT_HIGHT);
        button_->setBounds(COMMAND_INPUT_WIDTH + EXTRA_WIDTH, 0, 40, 30);
        scrollbar_->setBounds(OUTPUT_WIDTH + EXTRA_WIDTH, 30, 16, OUTPUT_HIGHT);
        output_->setFontStyle(Font::FIXED);
        output_->setFocused(false);
        output_->setEditable(false);
        output_->setBackground(0x05070035);
        output_->setForeground(0xffffffff);
        add(command_.get());
        add(output_.get());
        add(button_.get());
        add(scrollbar_.get());
        scrollbar_->setMinimum(0);
        scrollbar_->setMaximum(0);
        scrollbar_->setBlocksize(1);
        if (monapi_file_exists(START_UP_FILE)) {
          setTimer(200);
        }
        // I'm logger.
        syscall_set_logger();
    }

    virtual ~Terminal() {}

    Rectangle getButtonAbsoluteBounds()
    {
        Rectangle ret = *(button_->getBounds());
        ret.x += getBounds()->x + insets.left;
        ret.y += getBounds()->y + insets.top;
        return ret;
    }

    void processEvent(Event* event)
    {
        if (event->getType() == Event::TIMER) {
          MonAPI::scoped_ptr<MonAPI::SharedMemory>
              shm(monapi_file_read_all(START_UP_FILE));
          if (shm.get() == NULL) {
              monapi_warn("can't read %s", START_UP_FILE);
          } else {
              MonAPI::Strings lines = MonAPI::StringHelper::split("\n", (const char*)shm->data());
              for (MonAPI::Strings::const_iterator it = lines.begin();
                   it != lines.end(); ++it) {
                if (!sendCommand((*it))) {
                    monapi_warn("start up command %s failed", (*it).c_str());
                }
              }
           }
        }

        bool runsCommand =
            (event->getType() == MouseEvent::MOUSE_RELEASED && event->getSource() == button_.get()) ||
            (event->getType() == KeyEvent::KEY_PRESSED &&
             event->getSource() == command_.get() &&
             ((KeyEvent*)event)->getKeycode() == KeyEvent::VKEY_ENTER);

        if (runsCommand) {
            if (!sendCommand(command_->getText())) {
                output_->setText("send command failed");
            }
        } else if (event->getSource() == scrollbar_.get()) {
            int currentLineNo = scrollbar_->getValue();
            updateOutputView(currentLineNo);
            repaint();
        } else if (event->getType() == Event::CUSTOM_EVENT &&
                   event->header == MSG_UPDATE) {
            appendOutput(terminalInfo_.sharedString);

            if (MonAPI::Message::send(event->from, MSG_OK, event->header) != M_OK) {
                monapi_fatal("sub thread is dead");
            }

            int currentLineNo = scrollbar_->getValue();
            updateOutputView(currentLineNo);
            repaint();
        } else if (event->getType() == Event::CUSTOM_EVENT &&
                   event->header == MSG_TEXT) {
          appendOutput(event->str);
        }

        if (event->getType() == WindowEvent::WINDOW_ACTIVATED) {
            command_->setFocused(true);
        }
    }

protected:

    void clearOutput()
    {
        lines_.clear();
    }

    void appendOutput(const std::string& content)
    {
        MonAPI::Strings lines = MonAPI::StringHelper::split("\n", content);
        for (MonAPI::Strings::const_iterator it = lines.begin(); it != lines.end(); ++it) {
            lines_.push_back(*it);
        }
        // Adjust scrollbar
        scrollbar_->setMaximum(lines_.size() - outputNumRows_);
        scrollbar_->setValue(scrollbar_->getMaximum());
        if (lines_.size() > outputNumRows_) {
            currentLineNo_ = lines_.size() - outputNumRows_;
        } else {
            currentLineNo_ = 0;
        }
    }

    void updateOutputView(int currentLineNo)
    {
        currentLineNo_ = currentLineNo;
        std::string content;
        for (uintptr_t i = 0; i + currentLineNo_ < lines_.size() && i < outputNumRows_; i++) {
            content += lines_[i + currentLineNo_];
            content += "\n";
        }
        output_->setText(content.c_str());
    }

    void restartShellServer()
    {
        const char* SHELL_SERVER = "/servers/shell";
        uint32_t tid;
        if (monapi_name_whereis(SHELL_SERVER, tid) != M_OK) {
            return;
        }
        MessageInfo msg;

        // we ignore the return value of sendReceive, since shell server may be dead already.
        MonAPI::Message::sendReceive(&msg, tid, MSG_TEXT, terminalInfo_.outStream.handle(), 0, 0, "restart");
        std::string command(MonAPI::System::getMoshPath());
        command += " \"/USER/BIN/SHELL.SPS\" restart";
        int result = monapi_process_execute_file_get_tid(command.c_str(),
                                                         MONAPI_TRUE,
                                                         &tid,
                                                         MonAPI::System::getProcessStdinID(),
                                                         terminalInfo_.outStream.handle());
        if (result != 0) {
            monapi_fatal("can't exec Mosh");
        }
        monapi_name_clear_cache(SHELL_SERVER);
    }

    bool sendCommand(const std::string& command)
    {
        if (command == "restart") {
            restartShellServer();
            return true;
        }
        const char* SHELL_SERVER = "/servers/shell";
        uint32_t tid;
        if (monapi_name_whereis(SHELL_SERVER, tid) != M_OK) {
            return false;
        }
        MessageInfo msg;
        intptr_t ret = MonAPI::Message::sendReceive(&msg, tid, MSG_TEXT, terminalInfo_.outStream.handle(), 0, 0, command.c_str());
        if (ret != M_OK) {
            monapi_warn("send command to server<%d> failed error = %d\n", tid, ret);
            return false;
        }

        // Restart shell server for debug
        if (command == "restart") {
            uint32_t tid;
            std::string command(MonAPI::System::getMoshPath());
            command += " \"/USER/BIN/SHELL.SPS\" restart";
            int result = monapi_process_execute_file_get_tid(command.c_str(),
                                                             MONAPI_TRUE,
                                                             &tid,
                                                             MonAPI::System::getProcessStdinID(),
                                                             terminalInfo_.outStream.handle());
            if (result != 0) {
                monapi_fatal("can't exec Mosh");
            }
            monapi_name_clear_cache(SHELL_SERVER);
        }

        return true;
    }
};

#endif // _TERMINAL_
