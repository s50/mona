/*!
  \file  Monitor
  \brief class Monitor

  Copyright (c) 2004 Higepon
  All rights reserved.
  License=MIT/X License

  \author  HigePon
  \version $Revision$
  \date   create:2004/06/19 update:$Date$
*/

#include <monapi.h>
#include <monapi/CString.h>
#include <monapi/messages.h>

using namespace MonAPI;

#define CHECK_INTERVAL 5000

class Monitor
{
public:
    Monitor();
    virtual ~Monitor();

public:
    bool Initialize();
    void Service();

private:
    uint8_t* ReadConfig(CString file);
    void ParseConfig(CString content);
    void CheckServers();

private:
    HList<CString> paths;
    HList<CString> servers;
    bool firstLoad;
    bool* alive;

};

Monitor::Monitor() : firstLoad(true)
{
}

Monitor::~Monitor()
{

    delete alive;
}

void Monitor::Service()
{
    for (;;)
    {
        CheckServers();
        sleep(CHECK_INTERVAL);
    }
}

bool Monitor::Initialize()
{
    monapi_cmemoryinfo* mi = NULL;
    mi = monapi_file_read_all("/MONITOR.CFG");
    if (mi == NULL)
    {
        printf("Config file read error\n");
        return false;
    }
    ParseConfig((char*)(mi->Data));
    monapi_cmemoryinfo_dispose(mi);
    monapi_cmemoryinfo_delete(mi);

    return true;
}

void Monitor::ParseConfig(CString content)
{
    _A<CString> lines = content.split_lines();

    FOREACH(CString, line, lines)
    {
        if (!line.startsWith("SERVER=")) continue;

        _A<CString> p = line.split("=");
        if (p.get_Length() < 2) continue;

        CString path = p[p.get_Length() - 1];

        _A<CString> q = path.split("/");

        CString name = q[q.get_Length() - 1];

        this->paths.add(path);
        this->servers.add(name);
    }
    END_FOREACH

    alive = new bool[servers.size()];

    return;
}

void Monitor::CheckServers()
{
    char buf[256];
    PsInfo info;

    for (int i = 0; i < servers.size(); i++)
    {
        alive[i] = false;
    }

    syscall_set_ps_dump();

    while (syscall_read_ps_dump(&info) == 0)
    {
        CString name = info.name;

        for (int i = 0; i < servers.size(); i++)
        {
            if (servers.get(i) == name)
            {
                alive[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < servers.size(); i++)
    {
        if (alive[i]) continue;
        if (!firstLoad && servers[i] == "OLDSHELL.EX5") continue;

        // sorry we can not use printf before process server starts.
        syscall_print("loading ");
        syscall_print((const char*)paths.get(i));
        syscall_print("....");
        syscall_print(monapi_call_process_execute_file((const char*)paths.get(i), MONAPI_FALSE) == 0? "OK\n" : "NG\n");
        MessageInfo msg;
        for (;;)
        {
            if (Message::receive(&msg)) continue;
            if (msg.header == MSG_SERVER_START_OK) break;
        }

    }

    if (firstLoad) firstLoad = false;
}

int main(int argc, char* argv[])
{
    Monitor monitor;

    monitor.Initialize();

    if (MONAPI_FALSE == monapi_notify_server_start("INIT"))
    {
        exit(-1);
    }

    monitor.Service();

    return 0;
}
