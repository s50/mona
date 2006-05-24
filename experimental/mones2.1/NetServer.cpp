#include "NetServer.h"
using namespace mones;
using namespace MonAPI;

NetServer::NetServer() : 
     observerThread(0xffffffff),nic(NULL), started(false), loopExit(false)
{

}

NetServer::~NetServer()
{

}

bool NetServer::initialize()
{
    syscall_get_io();
    this->nic = NicFactory::create();
    if(this->nic == NULL){
        printf("NicFactory error\n");
        return false;
    }
    syscall_set_irq_receiver(this->nic->getIRQ(), SYS_MASK_INTERRUPT); // with mask Interrrupt by higepon
    this->nic->enableNetwork();
    dword ip= nic->getIP();         
    for(int j=0;j<4;j++)
          printf("%d.",*(((byte*)&ip)+j));
    printf("\n");
    this->observerThread= Message::lookupMainThread();
    this->myID = System::getThreadID();
    return true;
}

dword NetServer::getThreadID() const
{
    return this->myID;
}

void NetServer::ICMPreply(IP* pkt)
{
    Ether* rframe = nic->MakePKT(pkt->srcip);
    //ether header has been already filled.
    if( rframe != NULL){
        ICMP* icmp=rframe->IPHeader->ICMPHeader;
        //FillICMPHeader();
        //create ICMP echo reply.
        icmp->type=0x00;
        icmp->code=0x00;
        icmp->chksum=pkt->ICMPHeader->chksum+8;
        memcpy(icmp->data,pkt->ICMPHeader->data,bswap(pkt->len)-24);
        printf("replying.\n");    
        FillIPHeader(rframe->IPHeader);
        nic->Send(rframe);
    }
}

void NetServer::interrupt(MessageInfo* msg)
{   
    //Don't say anything about in case mona is a router.
    int val = nic->interrupt();
    if( val & Nic::RX_INT ){
        printf("==RX\n");
        Ether* frame =NULL;
        while( frame = nic ->Recv(0) ){
            IP* pkt=frame->IPHeader;
            dumpPacket(pkt);
            if( pkt->prot == TYPEICMP){
                ICMPreply(pkt);
            }
            //Send a Message to client.
            delete frame;
        }
    }
    if(val & Nic::TX_INT){
        printf("==TX\n");
    }
    if( val & Nic::ER_INT){
        printf("==ERROR.\n");    
    }
    return;
}

/*typedef struct {
    dword header;
    dword arg1;
    dword arg2;
    dword arg3;
    dword from;
    char str[128];
    int length;
} MessageInfo; */

void NetServer::messageLoop()
{
    this->started = true;
    for (MessageInfo msg; !loopExit;)
    {
        if (Message::receive(&msg)) continue;

        switch (msg.header){
        case MSG_INTERRUPTED:
            this->interrupt(&msg);   
            break;
        case MSG_NET_GETFREEPORT:
            Message::reply(&msg,1025);
            break;
        case MSG_NET_WRITE:
        {
            monapi_cmemoryinfo* ret = monapi_cmemoryinfo_new();
            if( ret != NULL){
                ret->Handle = msg.arg1;
                ret->Owner  = msg.from;
                ret->Size   = msg.arg2;
                monapi_cmemoryinfo_map(ret);
                byte* buf=new byte[ret->Size+1];
                memcpy(buf,ret->Data,ret->Size); buf[ret->Size]='\0';
                printf("<%s>\n",buf);
                monapi_cmemoryinfo_delete(ret);
                delete buf;
            }
            Message::reply(&msg);            
            break;
        }
        case MSG_NET_READ: 
        {
            byte val[]="string";   
            monapi_cmemoryinfo* mi = monapi_cmemoryinfo_new();  
            if (mi != NULL){    
                monapi_cmemoryinfo_create(mi,7, true);        
                if( mi != NULL ){
                    memcpy(mi->Data,val,mi->Size);mi->Data[6]='\0';
                    Message::reply(&msg, mi->Handle, mi->Size); 
                }
                monapi_cmemoryinfo_delete(mi);
            }else{
                Message::reply(&msg);
            }
            break;
        }
        case MSG_NET_STATUS:
        {
            dword val=45678;   
            monapi_cmemoryinfo* mi = monapi_cmemoryinfo_new();  
            if (mi != NULL){    
                monapi_cmemoryinfo_create(mi, sizeof(NetStatus), true);        
                if( mi != NULL ){
                    memcpy(mi->Data,&val,mi->Size);
                    Message::reply(&msg, mi->Handle, mi->Size); 
                }
                monapi_cmemoryinfo_delete(mi);
            }else{
                Message::reply(&msg);
            }
            break;
        }
        case MSG_NET_OPEN:    
        {
            dword result = 123;//Open(msg.str);
            Message::reply(&msg, result);
            break;
        }
        case MSG_NET_CLOSE:
            Message::reply(&msg);
            break;
        default:
            printf("Server default come %d", msg.header);
            break;
        }
    }
    printf("NetServer exit\n");
}
