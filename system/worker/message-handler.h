#pragma once
#include "ipc/message.h"
#include "meta/enum-list.h"
#include "worker.h"

namespace worker
{
    class Message_Handler : public Bundle
    {
        public:
        Message_Handler(void)
        : Bundle()
        {}

        virtual ~Message_Handler(void){}

        void on_start(void) {}

        virtual void on_message(ipc::Message const & msg) {}

        void on_loop(void) {}

        void on_stop(void) {}
    };
}
