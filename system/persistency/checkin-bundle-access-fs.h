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
        static std::string const FILENAME = "checkin-bundle";
        static std::string const ACCOUNT_KEY = "account";
        static std::string const TIME_KEY = "timestamp";

        DAL * dal;
        bird::CheckinBundleParserJSON * json_parser;
        std::deque<bird::CheckinBundle> queue;

        public:
        CheckinBundleAccessFS(DAL & dal, bird::CheckinBundleParserJSON & json_parser)
        : dal(&dal),
		  json_parser(),
		  queue() {}

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
				Json::Value commit_data = checkin_bundle_to_json();
				dal->put_json(commit_data, FILENAME);
        	}

        }

        private:

        void update_queue(void)
        {
        	if (!this->queue.empty()) return;

        	Json::Value json = this->dal->get_json(FILENAME);

        	if (json.isArray())
        	{
        		for (auto & json_cb : json)
        		{
        			Json::Value account_json = json_cb.get(ACCOUNT_KEY.c_str(), "");
        			Json::Value time_json = json_cb.get(TIME_KEY.c_str(), "");
        			bird::CheckinBundle new_checkin_bundle(account_json.asString(), time_json.asString());
        			this->queue.push_back(new_checkin_bundle);
        		}
        	}
        }

        Json::Value && checkin_bundle_to_json()
        {
        	Json::Value json_value;
        	for (auto & cb : this->queue)
        	{
        		json_value.append(json_cb);

        	}
        	return json_value;
        }

    };
}
