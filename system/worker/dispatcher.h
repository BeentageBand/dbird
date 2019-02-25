#pragma once
#include <vector>
#include "bundle.h"
namespace worker
{
    class Dispatcher : public Bundle
    {
        private:
        std::vector<Bundle *> bundles;
        public:
        Dispatcher(void)
        : bundles()
        {}

        virtual ~Dispatcher(void){}

        void append(Bundle & bundle)
        {
            this->bundles->push_back(&bundle);
        }

        void on_start(void)
        {
            for(auto & bundle : this->bundles)
            {
                bundle->on_start();
            }
        }

        void on_message(ipc::Message const & msg)
        {
            for(auto & bundle : this->bundles)
            {
                bundle->on_message(msg);
            }
        }

        void on_loop(void)
        {
            for(auto & bundle : this->bundles)
            {
                bundle->on_loop();
            }
        }

        void on_stop(void)
        {
            for(auto & bundle : this->bundles)
            {
                bundle->on_stop();
            }
            this->bundles.clear();
        }
    };
}