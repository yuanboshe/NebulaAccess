/*******************************************************************************
 * Project:  AccessServer
 * @file     CmdFromClient.cpp
 * @brief 
 * @author   Bwar
 * @date:    2015年10月21日
 * @note
 * Modify history:
 ******************************************************************************/
#include "CmdFromClient.hpp"


namespace im
{

CmdFromClient::CmdFromClient()
    : pStepFromClient(NULL)
{
}

CmdFromClient::~CmdFromClient()
{
}

bool CmdFromClient::AnyMessage(
                    const oss::tagMsgShell& stMsgShell,
                    const MsgHead& oInMsgHead,
                    const MsgBody& oInMsgBody)
{
    LOG4CPLUS_DEBUG_FMT(GetLogger(), "%s()", __FUNCTION__);
    pStepFromClient = new StepFromClient(stMsgShell, oInMsgHead, oInMsgBody);
    if (pStepFromClient == NULL)
    {
        LOG4CPLUS_ERROR_FMT(GetLogger(), "error %d: new StepFromClient() error!", oss::ERR_NEW);
        return(false);
    }

    if (RegisterCallback(pStepFromClient))
    {
        if (oss::STATUS_CMD_RUNNING == pStepFromClient->Emit(ERR_OK))
        {
            return(true);
        }
        DeleteCallback(pStepFromClient);
        return(false);
    }
    else
    {
        delete pStepFromClient;
        pStepFromClient = NULL;
        return(false);
    }
}

} /* namespace im */
