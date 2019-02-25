#pragma once
#include "checkin-bundle.h"

namespace persistency 
{
    class Checkin_Bundle_Access
    {
        public:
        virtual bool empty(void) = 0;
        virtual void push(bird::Checkin_Bundle & checkin_bundle) = 0;
        virtual bird::Checkin_Bundle pop(void) = 0;
        virtual void commit(void) = 0;
    };
}