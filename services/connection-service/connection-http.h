#pragma once
#include <vector>
#include <string>
#include "connection-interface.h"
#include "http/http-interface.h"

namespace service
{
    class Connection_HTTP : public Connection_Interface
    {
        private:
        size_t const PACKAGE_SIZE_BYTES = 100;
        protocols::HTTP_Interface * http;
        bird::Checkin_Bundle_Parser * checkin_bundle_parser;
        public:
        Connection_HTTP(protocols::HTTP_Interface & http, bird::Checkin_Bundle_Parser & checkin_bundle_parser)
        : http(&http), checkin_bundle_parser(&checkin_bundle_parser)
        {}

        virtual ~Connection_HTTP(void){}

        void send_checkin_bundles(std::vector<bird::Checkin_Bundle> & checkin_bundles)
        {
            //TODO find right json
            std::string json = this->checkin_bundle_parser->parse_to_string(checkin_bundles);
            this->http->open_session();
            this->http->post(json);
            //TODO handle error
            this->http->close_session();
        }
    };
}