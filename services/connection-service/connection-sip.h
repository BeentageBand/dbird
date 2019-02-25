#pragma once
#include <vector>
#include <string>
#include "connection-interface.h"
#include "sip/sip-interface.h"
#include "checkin-bundle-parser.h"

namespace service
{
    class Connection_SIP : public Connection_Interface
    {
        private:
        size_t const PACKAGE_SIZE_BYTES = 100;
        protocols::SIP_Interface * sip;
        bird::Checkin_Bundle_Parser * checkin_bundle_parser;
        public:
        Connection_SIP(protocols::SIP_Interface & sip, bird::Checkin_Bundle_Parser & checkin_bundle_parser)
        : sip(&sip), checkin_bundle_parser(&checkin_bundle_parser)
        {}

        virtual ~Connection_SIP(void){}

        void send_checkin_bundles(std::vector<bird::Checkin_Bundle> & checkin_bundles)
        {
            std::string sip_data = this->checkin_bundle_parser->parse_to_string(checkin_bundles);
            //TODO handle error
            this->sip->write(sip_data);
        }
    };
}