#ifndef STEPSWITCH_HPP_
#define STEPSWITCH_HPP_

#include "util/json/CJsonObject.hpp"
#include <actor/step/PbStep.hpp>

namespace acc {
class StepSwitch
    : public neb::PbStep,
      public neb::DynamicCreator<
          StepSwitch, std::shared_ptr<neb::SocketChannel>, MsgHead, MsgBody> {
public:
  StepSwitch(std::shared_ptr<neb::SocketChannel> pUpstreamChannel,
             MsgHead oInMsgHead, MsgBody oInMsgBody);
  ~StepSwitch() override;

  neb::E_CMD_STATUS Emit(int iErrno, const std::string &strErrMsg = "",
                                 void *data = nullptr) override;

  neb::E_CMD_STATUS
  Callback(std::shared_ptr<neb::SocketChannel> pUpstreamChannel,
           const MsgHead &oInMsgHead, const MsgBody &oInMsgBody,
           void *data = nullptr) override;

  neb::E_CMD_STATUS Timeout() override;

private:
  std::shared_ptr<neb::SocketChannel> m_pRequestUpstreamChannel;
  MsgHead m_oMsgHead;
  MsgBody m_oMsgBody;
};
} // namespace acc

#endif // STEPSWITCH_HPP_
