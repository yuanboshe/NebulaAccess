#ifndef CMDHELLO_HPP_
#define CMDHELLO_HPP_

#include <actor/cmd/Cmd.hpp>
#include <fstream>
#include <string>
#include <unistd.h>

namespace acc {
class CmdHello : public neb::Cmd, public neb::DynamicCreator<CmdHello, int32> {
public:
  explicit CmdHello(int32 iCmd);

  ~CmdHello() override;

  bool Init() override;

  bool AnyMessage(std::shared_ptr<neb::SocketChannel> pChannel,
                          const MsgHead &oMsgHead, const MsgBody &oMsgBody) override;
};
} // namespace acc

#endif /* CMDHELLO_HPP_ */
