#include "../msgcenter/LoginMsgProcessor.h"
#include "../msgcenter/LogoutMsgProcessor.h"
#include "../msgcenter/MsgCenter.h"

#define MDJSS_MSG_REGISTER(x, y) \
{\
    (CMsgCenter::getInstance())->doregister((ushort)x, CMsgProcessor::getInstance<y>());\
}

void msgCenter_init()
{
    MDJSS_MSG_REGISTER(MDJSS_MSGTYPE_LOGIN_E, CLoginMsgProcessor);
    MDJSS_MSG_REGISTER(MDJSS_MSGTYPE_LOGOUT_E, CLogoutMsgProcessor);
}


