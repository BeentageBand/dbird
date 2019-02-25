#pragma once
#include "server-interface.h"
#include "sip/sip-interface.h"

namespace service
{
    class Server_Master_Slave : public Server_Interface
    {
        private:
        protocols::SIP_Interface * sip;
        public:
        Server_Master_Slave(protocols::SIP_Interface & sip)
        : sip(&sip)
        {}

        void bootup(void) 
        {
        }

        void update(void)
        {
        }
        void handle_status(ipc::Message const & msg)
        {}
        void shutdown(void) 
        {}
    };
}