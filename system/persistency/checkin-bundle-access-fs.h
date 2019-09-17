#pragma once
#include <deque>
#include <fstream>
#include "checkin-bundle.h"
#include "checkin-bundle-parser-json.h"
#include "checkin-bundle-access.h"
#include "dal.h"

namespace persistency
{
    class CheckinBundleAccessFS : public CheckinBundleAccess
    {
        static std::string const FILENAME;

        DAL * dal;
        bird::CheckinBundleParserJSON * json_parser;
        std::vector<bird::CheckinBundle> queue;

        public:
        CheckinBundleAccessFS(DAL & dal, bird::CheckinBundleParserJSON & json_parser)
        : dal(&dal), json_parser(&json_parser), queue() {}

        bool empty(void)
        {
        	update_queue();
        	return this->queue.empty();
        }

        void push(bird::CheckinBundle & checkin_bundle)
        {
        	update_queue();
        	this->queue.push_back(checkin_bundle);

        }

        bird::CheckinBundle pop(void)
        {
            bird::CheckinBundle checkin_bundle("", "");
            update_queue();

            if(! this->queue.empty())
            {
                checkin_bundle = this->queue.back();
                this->queue.pop_back();
            }
            return checkin_bundle;
        }

        void commit(void)
        {
        	if (!this->queue.empty())
        	{
        		std::string file_data = this->json_parser->parse_to_string(this->queue);
        		this->dal->put_file_data(file_data, FILENAME);
        	}

        }

        private:

        void update_queue(void)
        {
        	if (!this->queue.empty()) return;

        	std::string file_data = dal->get_file_data(FILENAME);
        	this->queue = this->json_parser->parse_to_checkin_bundles(file_data);
        }
    };

    std::string const CheckinBundleAccessFS::FILENAME = "checkin-bundle";
}
