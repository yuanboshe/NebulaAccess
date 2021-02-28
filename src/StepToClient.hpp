/*******************************************************************************
 * Project:  AccessServer
 * @file     StepToClient.hpp
 * @brief 
 * @author   Bwar
 * @date:    2015年10月21日
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_CMDTOCLIENT_STEPTOCLIENT_HPP_
#define SRC_CMDTOCLIENT_STEPTOCLIENT_HPP_

#include "ImError.h"
#include "step/Step.hpp"

namespace im
{

class StepToClient: public oss::Step
{
public:
    StepToClient(
                    const oss::tagMsgShell& stMsgShell,
                    const MsgHead& oInMsgHead,
                    const MsgBody& oInMsgBody);
    virtual ~StepToClient();

    virtual oss::E_CMD_STATUS Emit(int iErrno, const std::string& strErrMsg = "", const std::string& strErrShow = "");
    virtual oss::E_CMD_STATUS Callback(
                    const oss::tagMsgShell& stMsgShell,
                    const MsgHead& oInMsgHead,
                    const MsgBody& oInMsgBody,
                    void* data = NULL);
    virtual oss::E_CMD_STATUS Timeout();
};

} /* namespace im */

#endif /* SRC_CMDTOCLIENT_STEPTOCLIENT_HPP_ */
