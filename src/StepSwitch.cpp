#include "StepSwitch.hpp"

#include <utility>

namespace acc {

StepSwitch::StepSwitch(std::shared_ptr<neb::SocketChannel> pUpstreamChannel,
                       MsgHead oInMsgHead, MsgBody oInMsgBody)
    : m_pRequestUpstreamChannel(std::move(pUpstreamChannel)), m_oMsgHead(std::move(oInMsgHead)),
      m_oMsgBody(std::move(oInMsgBody)) {}

StepSwitch::~StepSwitch() {}

neb::E_CMD_STATUS StepSwitch::Emit(int iErrno, const std::string &strErrMsg,
                                   void *data) {
  LOG4_DEBUG("%s()", __FUNCTION__);
  if (neb::ERR_OK != iErrno) {
    LOG4_ERROR("error %d: %s!", iErrno, strErrMsg.c_str());
    // Response(iErrno, strErrMsg, strErrMsg);
    return (neb::CMD_STATUS_FAULT);
  }

  SendRoundRobin("LOGIC", m_oMsgHead.cmd(), GetSequence(), m_oMsgBody);

  return neb::CMD_STATUS_RUNNING;
}
neb::E_CMD_STATUS
StepSwitch::Callback(std::shared_ptr<neb::SocketChannel> pUpstreamChannel,
                     const MsgHead &oInMsgHead, const MsgBody &oInMsgBody,
                     void *data) {
  LOG4_TRACE("%s()", __FUNCTION__);

  SendTo(m_pRequestUpstreamChannel, m_oMsgHead.cmd() + 1, m_oMsgHead.seq(),
         oInMsgBody);

  return neb::CMD_STATUS_RUNNING;
}

neb::E_CMD_STATUS StepSwitch::Timeout() { return neb::CMD_STATUS_RUNNING; }

} // namespace acc