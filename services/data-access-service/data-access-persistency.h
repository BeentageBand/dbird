#pragma once
#include "persistency/checkin-bundle-access.h"
#include "data-access-interface.h"

namespace service
{
    class Data_Access_Persistency : public  Data_Access_Interface
    {
        private:
        persistency::Checkin_Bundle_Access * checkin_bundle_access;

        public:
        Data_Access_Persistency(persistency::Checkin_Bundle_Access & checkin_bundle_access)
        : checkin_bundle_access(&checkin_bundle_access)
        {}

        std::vector<bird::Checkin_Bundle> get_all_checkin_bundles(void) 
        {
            std::vector<bird::Checkin_Bundle> all_checkin_bundles;
            while(! this->checkin_bundle_access->empty())
                all_checkin_bundles.push_back(this->checkin_bundle_access->pop());
            this->checkin_bundle_access->commit();
            //TODO Handle error
            return all_checkin_bundles;
        }

        void put_checkin_bundles(std::vector<bird::Checkin_Bundle> & checkin_bundles)
        {
            for (auto & checkin_bundle : checkin_bundles)
                this->checkin_bundle_access->push(checkin_bundle);
            this->checkin_bundle_access->commit();
        }
    };
}