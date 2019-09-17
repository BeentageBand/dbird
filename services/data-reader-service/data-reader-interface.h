#pragma once
#include <vector>
#include "checkin-bundle.h"

namespace service
{
    class DataReaderInterface
    {
        public:
    	virtual ~DataReaderInterface(void) {}
        virtual std::vector<bird::CheckinBundle> get_all_checkin_bundles(void) = 0;
    };
}
