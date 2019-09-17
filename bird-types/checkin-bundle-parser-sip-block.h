#pragma once
#include <string>
#include <vector>
#include "checkin-bundle.h"
#include "checkin-bundle-parser.h"

namespace bird
{
    class CheckinBundleParserSIPBlock : public CheckinBundleParser
    {
    	static char const DELIMITER = ',';

        public:
        CheckinBundle parse_to_checkin_bundle(std::string const & data)
        {
        	return to_checkin_bundle(data);
        }

        std::vector<CheckinBundle> parse_to_checkin_bundles(std::string const & data)
		{
        	std::string token;
        	std::vector<CheckinBundle> checkin_bundles;
        	std::istringstream iss(data);
        	while(std::getline(iss, token))
        	{
        		checkin_bundles.push_back(this->to_checkin_bundle(token));
        	}
        	return checkin_bundles;
		}

        std::string parse_to_string(std::vector<CheckinBundle> const & checkin_bundles)
        {
        	std::stringstream ss;
            for(auto & checkin_bundle : checkin_bundles)
            {
            	ss << this->to_line(checkin_bundle) << std::endl;
            }
            return ss.str();
        }

        private:
        CheckinBundle to_checkin_bundle(std::string const & data)
        {
        	std::istringstream iss(data);
        	std::string account_id;
        	std::string timestamp;

        	std::getline(iss, account_id, DELIMITER);
        	std::getline(iss, timestamp);
        	return CheckinBundle(account_id, timestamp);
        }

        std::string to_line(CheckinBundle const & checkin_bundle)
        {
        	std::string line(checkin_bundle.get_account_id());
        	line.push_back(DELIMITER);
        	line.append(checkin_bundle.get_timestamp());
        	return line;
        }
    };
}
