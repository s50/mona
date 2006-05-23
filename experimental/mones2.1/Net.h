#pragma once
#include <sys/types.h>
namespace mones {

enum MSG_NET{
    //'NET' IS 0X4E4554
    MSG_NET_CONFIG =0X4E455400,
    MSG_NET_STATUS,
    MSG_NET_GETFREEPORT,
    MSG_NET_OPEN,
    MSG_NET_CLOSE,
    MSG_NET_WRITE,
    MSG_NET_READ,
};

enum PROTOCOL{
    TYPEICMP = 0X01,
    TYPEIGMP = 0X02,
    TYPETCP  = 0X06,
    TYPEUDP  = 0X11,
};

enum PORT{
    TCPMUX         =1,
    ECHO           =7,
    DISCARD        =9,
    SYSTAT         =11,
    DAYTIME        =13,
    NETSTAT        =15,
    CHARGEN        =19,
    FTPDATA        =20,
    FTP            =21,
    SSH            =22,
    TELNET         =23,
    SMTP           =25,
    TIME           =37,
    NAME           =42,
    WHOIS          =43,
    DOMAIN         =53,
    BOOTPS         =67,
    BOOTPC         =68,
    KERBEROS       =88,
    HOSTNAMES      =101,
    POP2           =109,
    POP3           =110,
    SUNRPC         =111,
    IMAP           =143,
    LDAP           =389,
    SUBMISSION     =587,
    LDAPS          =636,
};
};
