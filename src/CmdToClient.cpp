/*******************************************************************************
 * Project:  AccessServer
 * @file     CmdToClient.cpp
 * @brief 
 * @author   Bwar
 * @date:    2015年10月20日
 * @note
 * Modify history:
 ******************************************************************************/
#include "CmdToClient.hpp"


namespace im
{

CmdToClient::CmdToClient()
    : pStepToClient(NULL)
{
}

CmdToClient::~CmdToClient()
{
}

bool CmdToClient::AnyMessage(
                    const oss::tagMsgShell& stMsgShell,
                    const MsgHead& oInMsgHead,
                    const MsgBody& oInMsgBody)
{
    LOG4CPLUS_DEBUG_FMT(GetLogger(), "%s()", __FUNCTION__);
    pStepToClient = new StepToClient(stMsgShell, oInMsgHead, oInMsgBody);
    if (pStepToClient == NULL)
    {
        LOG4CPLUS_ERROR_FMT(GetLogger(), "error %d: new StepToClient() error!", oss::ERR_NEW);
        return(false);
    }

    if (RegisterCallback(pStepToClient))
    {
        if (oss::STATUS_CMD_RUNNING == pStepToClient->Emit(ERR_OK))
        {
            return(true);
        }
        DeleteCallback(pStepToClient);
        return(false);
    }
    else
    {
        delete pStepToClient;
        pStepToClient = NULL;
        return(false);
    }
}

} /* namespace oss */
