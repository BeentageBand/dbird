#pragma once
#include "ipc/message.h"

namespace service
{
    class ServerInterface
    {
        public:
        virtual ~ServerInterface(void) {}

        virtual void bootup(void) = 0;
        virtual void update(void) = 0;
        virtual void handle_status(ipc::Message const & msg) = 0;
        virtual void shutdown(void) = 0;
    };
}
