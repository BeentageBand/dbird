#pragma once
#include <string>
#include <vector>
#include "checkin-bundle-parser.h"
#include "data-reader-interface.h"
#include "rfid/mifare.h"

namespace service
{
    class Data_Reader_Mifare : public Data_Reader_Interface
    {
        private:
        protocols::Mifare * mifare;
        bird::Checkin_Bundle_Parser * checkin_bundle_parser;
        public:
        Data_Reader_Mifare(protocols::Mifare & mifare,
                           bird::Checkin_Bundle_Parser & checkin_bundle_parser)
        : mifare(&mifare), checkin_bundle_parser(&checkin_bundle_parser)
        {}

        virtual ~Data_Reader_Mifare(void){}
        std::vector<bird::Checkin_Bundle> get_all_checkin_bundles(void)
        {
            std::vector<bird::Checkin_Bundle> all_checkin_bundles;

            while(!this->mifare->empty())
            {
                std::string data = this->mifare->read_block();
                bird::Checkin_Bundle checkin_bundle = this->checkin_bundle_parser->parse_to_checkin_bundle(data);
                //TODO Handle error
                all_checkin_bundles.push_back(checkin_bundle);
            }
            return all_checkin_bundles;
        }
    };
}