#pragma once
#include "persistency/checkin-bundle-access.h"
#include "data-access-interface.h"

namespace service
{
    class DataAccessPersistency : public  DataAccessInterface
    {
        private:
        persistency::CheckinBundleAccess * checkin_bundle_access;

        public:
        DataAccessPersistency(persistency::CheckinBundleAccess & checkin_bundle_access)
        : checkin_bundle_access(&checkin_bundle_access)
        {}

        std::vector<bird::CheckinBundle> get_all_checkin_bundles(void)
        {
            std::vector<bird::CheckinBundle> all_checkin_bundles;
            while(! this->checkin_bundle_access->empty())
                all_checkin_bundles.push_back(this->checkin_bundle_access->pop());
            this->checkin_bundle_access->commit();
            //TODO Handle error
            return all_checkin_bundles;
        }

        void put_checkin_bundles(std::vector<bird::CheckinBundle> & checkin_bundles)
        {
            for (auto & checkin_bundle : checkin_bundles)
                this->checkin_bundle_access->push(checkin_bundle);
            this->checkin_bundle_access->commit();
        }
    };
}
