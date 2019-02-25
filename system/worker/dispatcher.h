#pragma once
#include "bundle.h"
#include "meta/subscribable.h"

namespace worker
{
    class Dispatcher : public Bundle
    {
        private:
        meta::Subscribable<Bundle *> bundles;
        public:
        Dispatcher(void)
        : bundles()
        {}

        virtual ~Dispatcher(void){}

        void subscribe(Bundle & bundle)
        {
            this->bundles->subscribe(bundle);
        }

        void unsubscribe(Bundle & bundle)
        {
            this->bundles->unsubscribe(bundle);
        }

        void on_start(void)
        {

        }

    };
}