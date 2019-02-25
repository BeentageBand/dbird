#pragma once
#include <deque>
#include "checkin-bundle.h"
#include "checkin-bundle-access.h"

namespace persistency
{
    class Checkin_Bundle_Access_FS : public Checkin_Bundle_Access
    {
        private:
        std::deque<bird::Checkin_Bundle> queue;
        public:
        bool empty(void)
        {
            return this->queue.empty();
        }

        void push(bird::Checkin_Bundle & checkin_bundle)
        {
            this->queue.push_front(checkin_bundle);
        }

        bird::Checkin_Bundle pop(void)
        {
            bird::Checkin_Bundle checkin_bundle("", "");  
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