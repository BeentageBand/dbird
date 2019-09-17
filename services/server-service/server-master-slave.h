#pragma once
#include "server-interface.h"
#include "sip/sip-interface.h"

namespace service
{
    class ServerMasterSlave : public ServerInterface
    {
        private:
        protocols::SIPInterface * sip;
        public:
        ServerMasterSlave(protocols::SIPInterface & sip)
        : sip(&sip)
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
}
