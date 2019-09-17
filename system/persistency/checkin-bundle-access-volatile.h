#pragma once
#include <deque>
#include "checkin-bundle.h"
#include "checkin-bundle-access.h"

namespace persistency
{
    class CheckinBundleAccessVolatile : public CheckinBundleAccess
    {
        private:
        std::deque<bird::CheckinBundle> queue;
        public:
        bool empty(void)
        {
            return this->queue.empty();
        }

        void push(bird::CheckinBundle & checkin_bundle)
        {
            this->queue.push_front(checkin_bundle);
        }

        bird::CheckinBundle pop(void)
        {
            bird::CheckinBundle checkin_bundle("", "");
            if(! this->queue.empty())
            {
                checkin_bundle = this->queue.back();
                this->queue.pop_back();
            }
            return checkin_bundle;
        }
        void commit(void) {}
    };
}
