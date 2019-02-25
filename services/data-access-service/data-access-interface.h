#pragma once
#include <vector>
#include "checkin-bundle.h"
namespace service
{
    class Data_Access_Interface
    {
        public:
        virtual std::vector<bird::Checkin_Bundle> get_all_checkin_bundles(void) = 0;
        virtual void put_checkin_bundles(std::vector<bird::Checkin_Bundle> & checkin_bundles) = 0;
    };
}