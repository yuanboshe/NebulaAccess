#include "CmdHello.hpp"
#include <pb/neb_sys.pb.h>
#include <util/json/CJsonObject.hpp>

namespace acc {

CmdHello::CmdHello(int32 iCmd) : neb::Cmd(iCmd) {}

CmdHello::~CmdHello() = default;

bool CmdHello::Init() { return (true); }

bool CmdHello::AnyMessage(std::shared_ptr<neb::SocketChannel> pChannel,
                          const MsgHead &oMsgHead, const MsgBody &oMsgBody) {
  LOG4_DEBUG("cmd %d, seq %u", oMsgHead.cmd(), oMsgHead.seq());
  if (1111 == oMsgHead.cmd()) {
    MsgBody oOutMsgBody;
    oOutMsgBody.set_data("Test OK!");
    SendTo(pChannel, oMsgHead.cmd() + 1, oMsgHead.seq(), oOutMsgBody);
  }
  else
  {
    MsgBody oOutMsgBody;
    oOutMsgBody.set_data("Wrong cmd!");
    SendTo(pChannel, oMsgHead.cmd() + 1, oMsgHead.seq(), oOutMsgBody);
  }
  return (true);
}

} // namespace acc
