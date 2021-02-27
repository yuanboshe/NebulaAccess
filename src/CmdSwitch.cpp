#include "CmdSwitch.hpp"

namespace acc {

CmdSwitch::CmdSwitch(int32 iCmd) : neb::Cmd(iCmd), pStepSwitch(nullptr) {}

CmdSwitch::~CmdSwitch() = default;

bool CmdSwitch::Init() { return true; }

bool CmdSwitch::AnyMessage(std::shared_ptr<neb::SocketChannel> pChannel,
                           const MsgHead &oMsgHead, const MsgBody &oMsgBody) {
  pStepSwitch = std::dynamic_pointer_cast<StepSwitch>(
      MakeSharedStep("acc::StepSwitch", pChannel, oMsgHead, oMsgBody));
  if (pStepSwitch) {
    if (neb::CMD_STATUS_RUNNING == pStepSwitch->Emit(neb::ERR_OK)) {
      LOG4_TRACE("pStepSwitch running");
      return true;
    }
  }

  return false;
}
} // namespace acc