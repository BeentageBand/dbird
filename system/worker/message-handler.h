#pragma once
#include "ipc/message.h"
#include "meta/enum-list.h"
#include "worker.h"

namespace worker
{
    class MessageHandler : public Bundle
    {
        public:
        MessageHandler(void)
        : Bundle()
        {}

        virtual ~MessageHandler(void){}

        void on_start(void) {}

        virtual void on_message(ipc::Message const & msg) {}

        void on_loop(void) {}

        void on_stop(void) {}
    };
}
