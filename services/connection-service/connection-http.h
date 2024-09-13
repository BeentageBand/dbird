#pragma once
#include <vector>
#include <string>
#include "connection-interface.h"
#include "http-interface.h"

namespace service
{
    class ConnectionHTTP : public ConnectionInterface
    {
        private:
        size_t const PACKAGESIZEBYTES = 100;
        protocols::HTTPInterface * http;
        bird::CheckinBundleParser * checkin_bundle_parser;
        public:
        ConnectionHTTP(protocols::HTTPInterface & http, bird::CheckinBundleParser & checkin_bundle_parser)
        : http(&http), checkin_bundle_parser(&checkin_bundle_parser)
        {}

        virtual ~ConnectionHTTP(void){}

        void send_checkin_bundles(std::vector<bird::CheckinBundle> & checkin_bundles)
        {
            //TODO find right json
            std::string json = this->checkin_bundle_parser->parse_to_string(checkin_bundles);
            if (!json.empty())
            {
                this->http->open_session();
                this->http->post(json);
                //TODO handle error
                this->http->close_session();
            }
        }
    };
}
