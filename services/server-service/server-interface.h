#pragma once
#include "ipc/message.h"

namespace service
{
    class Server_Interface
    {
        public:
        virtual ~Server_Interface(void) {}

        virtual void bootup(void) = 0;
        virtual void update(void) = 0;
        virtual void handle_status(ipc::Message const & msg) = 0;
        virtual void shutdown(void) = 0;
    };
}