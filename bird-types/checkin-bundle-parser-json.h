#pragma once
#include <string>
#include "checkin-bundle.h"
#include "checkin-bundle-parser.h"

namespace bird
{
    class Checkin_Bundle_Parser_JSON : public Checkin_Bundle_Parser
    {
        public:
        Checkin_Bundle parse_to_checkin_bundle(std::string const & data)
        {
            //TODO implement 
            std::string account_id = "account_id";
            std::string timestamp = "00/00/00-00:00:00";
            return Checkin_Bundle(account_id, timestamp);
        }

        std::string parse_to_string(std::vector<Checkin_Bundle> const & checkin_bundles)
        {
            std::string json_data;
            for(auto & checkin_bundle : checkin_bundles)
            {
                json_data.append(checkin_bundle.get_account_id());
                json_data.append(checkin_bundle.get_timestamp());

            }
            return json_data;
        }
    };
}