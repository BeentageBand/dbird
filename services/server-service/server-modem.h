#pragma once
#include "ipc/message.h"
#include "modem/modem-interface.h"
#include "server-interface.h"

namespace service
{
   class Server_Modem : public Server_Interface 
   {
       private:
       protocols::Modem_Interface * modem;
       public:
       Server_Modem(protocols::Modem_Interface & modem)
       : modem(&modem)
       {}
       void bootup(void) 
       {

       }
       void update(void) 
       {

       }
       void handle_status(ipc::Message const & msg) 
       {

       }
       void shutdown(void)
       {

       }
   };
} // service