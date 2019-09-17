#pragma once
#include <vector>
#include <string>
#include "connection-interface.h"
#include "sip/sip-interface.h"
#include "checkin-bundle-parser.h"

namespace service
{
    class ConnectionSIP : public ConnectionInterface
    {
        private:
        size_t const PACKAGESIZEBYTES = 100;
        protocols::SIPInterface * sip;
        bird::CheckinBundleParser * checkin_bundle_parser;
        public:
        ConnectionSIP(protocols::SIPInterface & sip, bird::CheckinBundleParser & checkin_bundle_parser)
        : sip(&sip), checkin_bundle_parser(&checkin_bundle_parser)
        {}

        virtual ~ConnectionSIP(void){}

        void send_checkin_bundles(std::vector<bird::CheckinBundle> & checkin_bundles)
        {
            std::string sip_data = this->checkin_bundle_parser->parse_to_string(checkin_bundles);
            //TODO handle error
            if(!sip_data.empty())
                this->sip->write(sip_data);
        }
    };
}
