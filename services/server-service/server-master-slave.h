#pragma once
#include "server-interface.h"

namespace service
{
    class Server_Master_Slave : public Server_Interface
    {
        public:
        Server_Master_Slave()
        {}
        void bootup(void) {}
        void update(void) {}
        void handle_status(ipc::Message const & msg) {}
        void shutdown(void) {}
    };
}