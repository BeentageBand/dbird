#pragma once
#include <string>
#include <vector>
#include "checkin-bundle-parser.h"
#include "data-reader-interface.h"
#include "sip/sip-interface.h"

namespace service
{
    class Data_Reader_SIP : public Data_Reader_Interface
    {
        private:
        protocols::SIP_Interface * sip;
        bird::Checkin_Bundle_Parser * checkin_bundle_parser;
        public:
        Data_Reader_SIP(protocols::SIP_Interface & sip,
                           bird::Checkin_Bundle_Parser & checkin_bundle_parser)
        : sip(&sip), checkin_bundle_parser(&checkin_bundle_parser)
        {}

        virtual ~Data_Reader_SIP(void){}

        std::vector<bird::Checkin_Bundle> get_all_checkin_bundles(void)
        {
            std::vector<bird::Checkin_Bundle> all_checkin_bundles;

            while(!this->sip->empty())
            {
                std::string data = this->sip->read();
                bird::Checkin_Bundle checkin_bundle = this->checkin_bundle_parser->parse_to_checkin_bundle(data);
                //TODO Handle error
                all_checkin_bundles.push_back(checkin_bundle);
            }
            return all_checkin_bundles;
        }
    };
}
