/*!
    \file  ProcessManager.h
    \brief ProcessManager

    ProcessManager, management of maltitask.

    Copyright (c) 2002 HigePon
    WITHOUT ANY WARRANTY

    \author  HigePon
    \version $Revision$
    \date   create:2002/11/19 update:$Date$
*/
#ifndef _MONA_PROCESSMANAGER_
#define _MONA_PROCESSMANAGER_

#include <monaKernel.h>

#define GDTNUM 7 /*! number of entry gdt */

/*!
    process management
*/
class ProcessManager {

  public:
    ProcessManager();
    void setTSS(TSS*, word, word, void (*f)(), dword, byte*, word, byte*, word);
    void setDT(GDT*, dword, dword, byte);
    void switchProcess();
    inline void switchProcess(dword) const;
    void printInfo();
    static ProcessManager& instance() {
        static ProcessManager theInstance;
        return theInstance;
    }
  private:
    void sgdt();
    inline void ltr(word) const;
    inline void lldt(word) const;
    inline void setNTflag1() const;
    GDT* gdt_;
    word taskidx_;
};

#endif
