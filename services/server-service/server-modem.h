#pragma once
#include "ipc/message.h"
#include "server-interface.h"

namespace service
{
   class Server_Modem : public Server_Interface 
   {
       public:
       Server_Modem()
       {}
       void bootup(void) {}
       void update(void) {}
       void handle_status(ipc::Message const & msg) {}
       void shutdown(void) {}
   };
} // service