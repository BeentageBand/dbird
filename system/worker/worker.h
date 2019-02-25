#pragma once
#include "bundle.h"
#include "ipc/message.h"

namespace worker
{
    class Worker
    {
        private:
        Bundle * bundle;
        public:
        Worker(Bundle & bundle)
        : bundle(&bundle)
        {}
        virtual ~Worker(void){}

        void runnable(void)
        {
            this->bundle->on_start();

            do
            {
                ipc::Message msg(CLK_TIMER_TOUT_MID, 0); //Retriever from a node
                this->bundle->on_message(msg);
                this->bundle->on_loop();
                if(-1 == msg.get_mid()) break;
            } while (true);

            this->bundle->on_stop();
        }
    };
}