#pragma once
#include <vector>
#include "checkin-bundle.h"

namespace service
{
    class ConnectionInterface
    {
        public:
        virtual ~ConnectionInterface(void){}
        virtual void send_checkin_bundles(std::vector<bird::CheckinBundle> & checkin_bundles) = 0;
    };
}
