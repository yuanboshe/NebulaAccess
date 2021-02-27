#ifndef CMDSWITCH_HPP_
#define CMDSWITCH_HPP_

#include "StepSwitch.hpp"
#include <actor/cmd/Cmd.hpp>

namespace acc {
class CmdSwitch : public neb::Cmd,
                  public neb::DynamicCreator<CmdSwitch, int32> {

public:
  explicit CmdSwitch(int32 iCmd);

  ~CmdSwitch() override;

  bool Init() override;

  bool AnyMessage(std::shared_ptr<neb::SocketChannel> pChannel,
                          const MsgHead &oMsgHead, const MsgBody &oMsgBody) override;

public:
  std::shared_ptr<StepSwitch> pStepSwitch;
};
} // namespace acc

#endif // CMDSWITCH_HPP_
