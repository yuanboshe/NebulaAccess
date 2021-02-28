/*******************************************************************************
 * Project:  AccessServer
 * @file     CmdToClient.hpp
 * @brief 
 * @author   Bwar
 * @date:    2015年10月20日
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_CMDTOCLIENT_CMDTOCLIENT_HPP_
#define SRC_CMDTOCLIENT_CMDTOCLIENT_HPP_

#include "cmd/Cmd.hpp"
#include "StepToClient.hpp"

namespace im
{

class CmdToClient: public oss::Cmd
{
public:
    CmdToClient();
    virtual ~CmdToClient();

    virtual bool AnyMessage(
                    const oss::tagMsgShell& stMsgShell,
                    const MsgHead& oInMsgHead,
                    const MsgBody& oInMsgBody);

    StepToClient* pStepToClient;
};

} /* namespace im */

#endif /* SRC_CMDTOCLIENT_CMDTOCLIENT_HPP_ */
