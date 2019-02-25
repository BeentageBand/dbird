#pragma once
#include <string>
#include "checkin-bundle.h"
#include "checkin-bundle-parser.h"

namespace bird
{
    class Checkin_Bundle_Parser_SIP_Block : public Checkin_Bundle_Parser
    {
        public:
        Checkin_Bundle parse_to_checkin_bundle(std::string const & data)
        {
            return Checkin_Bundle("account_id", "00/00/00-00:00:00");
        }

        std::string parse_to_string(std::vector<Checkin_Bundle> const & checkin_bundles)
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