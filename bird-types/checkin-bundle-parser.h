#pragma once
#include <string>
#include <vector>
#include "checkin-bundle.h"

namespace bird
{
    class CheckinBundleParser
    {
        public:
    	virtual ~CheckinBundleParser(void) {}
        virtual CheckinBundle parse_to_checkin_bundle(std::string const & data) = 0;
        virtual std::string parse_to_string(std::vector<CheckinBundle> const & checkin_bundles) = 0;
    };
}
