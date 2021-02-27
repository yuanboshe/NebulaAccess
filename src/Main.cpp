#include "labor/Manager.hpp"
#include "util/proctitle_helper.h"

int main(int argc, char *argv[]) {
  signal(SIGPIPE, SIG_IGN);
  ngx_init_setproctitle(argc, argv);
  if (argc == 2) {
    neb::Manager oManager(argv[1]);
    oManager.Run();
  } else {
    std::cerr << "param error! usage: " << argv[0] << "${config_file}"
              << std::endl;
    exit(-1);
  }
  return (0);
}
