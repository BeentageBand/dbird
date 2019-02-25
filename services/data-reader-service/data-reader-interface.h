#pragma once
#include <vector>
#include "checkin-bundle.h"

namespace service
{
    class Data_Reader_Interface
    {
        public:
        virtual std::vector<bird::Checkin_Bundle> get_all_checkin_bundles(void) = 0;
    };
}