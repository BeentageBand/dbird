#pragma once
#include "checkin-bundle.h"

namespace persistency 
{
    class CheckinBundleAccess
    {
        public:
    	virtual ~CheckinBundleAccess(void) {}
        virtual bool empty(void) = 0;
        virtual void push(bird::CheckinBundle & checkin_bundle) = 0;
        virtual bird::CheckinBundle pop(void) = 0;
        virtual void commit(void) = 0;
    };
}
