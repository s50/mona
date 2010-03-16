#ifndef _SERVER_NET_
#define _SERVER_NET_

enum
{
    MSG_NET_SOCKET_RECV   = 0x69271156,    // NET:RCV
    MSG_NET_SOCKET_SEND      = 0x6927268e, // NET:SND
    MSG_NET_GET_ADDR_INFO = 0x6926600e,    // NET:GAD
    /* deprecated */
    MSG_NET_TCP_CONNECT   = 0x69262736, // NET:CON
    MSG_NET_TCP_SEND      = 0x6927268e, // NET:SND
    MSG_NET_TCP_RECEIVE   = 0x69271156, // NET:RCV
    MSG_NET_TCP_IS_CLOSED = 0x6926812e, // NET:ICL
    MSG_NET_WEB_GET       = 0x6927634e  // NET:WGT
};

#endif
