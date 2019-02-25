#pragma once
#include "ipc/message.h"
namespace worker
{
    class Bundle
    {
        public:
        Bundle(void){}
        virtual ~Bundle(void){}
        virtual void on_start(void) = 0;
        virtual void on_message(ipc::Message const & msg) = 0;
        virtual void on_loop(void) = 0;
        virtual void on_stop(void) = 0;
    };
}