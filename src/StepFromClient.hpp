/*******************************************************************************
 * Project:  AccessServer
 * @file     StepFromClient.hpp
 * @brief 
 * @author   Bwar
 * @date:    2015年10月21日
 * @note
 * Modify history:
 ******************************************************************************/
#ifndef SRC_CMDFROMCLIENT_STEPFROMCLIENT_HPP_
#define SRC_CMDFROMCLIENT_STEPFROMCLIENT_HPP_

#include "ImError.h"
#include "step/Step.hpp"

namespace im
{

class StepFromClient: public oss::Step
{
public:
    StepFromClient(
                    const oss::tagMsgShell& stMsgShell,
                    const MsgHead& oInMsgHead,
                    const MsgBody& oInMsgBody);
    virtual ~StepFromClient();

    virtual oss::E_CMD_STATUS Emit(int iErrno, const std::string& strErrMsg = "", const std::string& strErrShow = "");
    virtual oss::E_CMD_STATUS Callback(
                    const oss::tagMsgShell& stMsgShell,
                    const MsgHead& oInMsgHead,
                    const MsgBody& oInMsgBody,
                    void* data = NULL);
    virtual oss::E_CMD_STATUS Timeout();
};

} /* namespace im */

#endif /* SRC_CMDFROMCLIENT_STEPFROMCLIENT_HPP_ */
