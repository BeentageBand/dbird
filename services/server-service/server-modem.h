#pragma once
#include "ipc/message.h"
#include "modem/modem-interface.h"
#include "server-interface.h"

namespace service
{
   class ServerModem : public ServerInterface
   {
       private:
       protocols::ModemInterface * modem;
       public:
       ServerModem(protocols::ModemInterface & modem)
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
