#pragma once
#include <vector>
#include "checkin-bundle.h"
namespace service
{
    class DataAccessInterface
    {
        public:
    	virtual ~DataAccessInterface(void) {}
        virtual std::vector<bird::CheckinBundle> get_all_checkin_bundles(void) = 0;
        virtual void put_checkin_bundles(std::vector<bird::CheckinBundle> & checkin_bundles) = 0;
    };
}
