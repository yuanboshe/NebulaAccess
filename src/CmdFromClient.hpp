/*******************************************************************************
 * Project:  AccessServer
 * @file     CmdFromClient.hpp
 * @brief 
 * @author   Bwar
 * @date:    2015年10月21日
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_CMDFROMCLIENT_CMDFROMCLIENT_HPP_
#define SRC_CMDFROMCLIENT_CMDFROMCLIENT_HPP_

#include "cmd/Cmd.hpp"
#include "StepFromClient.hpp"

namespace im
{

class CmdFromClient: public oss::Cmd
{
public:
    CmdFromClient();
    virtual ~CmdFromClient();

    virtual bool AnyMessage(
                    const oss::tagMsgShell& stMsgShell,
                    const MsgHead& oInMsgHead,
                    const MsgBody& oInMsgBody);

    StepFromClient* pStepFromClient;
};

} /* namespace im */

#endif /* SRC_CMDFROMCLIENT_CMDFROMCLIENT_HPP_ */
