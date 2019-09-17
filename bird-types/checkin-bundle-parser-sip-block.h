#pragma once
#include <string>
#include "checkin-bundle.h"
#include "checkin-bundle-parser.h"

namespace bird
{
    class CheckinBundleParserSIPBlock : public CheckinBundleParser
    {
        public:
        CheckinBundle parse_to_checkin_bundle(std::string const & data)
        {
            return CheckinBundle("account_id", "00/00/00-00:00:00");
        }

        std::string parse_to_string(std::vector<CheckinBundle> const & checkin_bundles)
        {
            std::string data;
            for(auto & checkin_bundle : checkin_bundles)
            {
                data.append(checkin_bundle.get_account_id()); 
                data.append(checkin_bundle.get_timestamp());
            }
            return data;
        }
    };
}
