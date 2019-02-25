#pragma once
#include <vector>
#include "checkin-bundle.h"

namespace service
{
    class Connection_Interface
    {
        public:
        virtual ~Connection_Interface(void){}
        virtual void send_checkin_bundles(std::vector<bird::Checkin_Bundle> & checkin_bundles) = 0;
    };
}