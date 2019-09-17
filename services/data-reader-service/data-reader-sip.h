#pragma once
#include <string>
#include <vector>
#include "checkin-bundle-parser.h"
#include "data-reader-interface.h"
#include "sip/sip-interface.h"

namespace service
{
    class DataReaderSIP : public DataReaderInterface
    {
        private:
        protocols::SIPInterface * sip;
        bird::CheckinBundleParser * checkin_bundle_parser;
        public:
        DataReaderSIP(protocols::SIPInterface & sip,
                           bird::CheckinBundleParser & checkin_bundle_parser)
        : sip(&sip), checkin_bundle_parser(&checkin_bundle_parser)
        {}

        virtual ~DataReaderSIP(void){}

        std::vector<bird::CheckinBundle> get_all_checkin_bundles(void)
        {
            std::vector<bird::CheckinBundle> all_checkin_bundles;

            while(!this->sip->empty())
            {
                std::string data = this->sip->read();
                bird::CheckinBundle checkin_bundle = this->checkin_bundle_parser->parse_to_checkin_bundle(data);
                //TODO Handle error
                all_checkin_bundles.push_back(checkin_bundle);
            }
            return all_checkin_bundles;
        }
    };
}
