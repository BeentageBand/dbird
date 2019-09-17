#include "gmock/gmock.h"
#include "checkin-bundle.h"
#include "system-gmock.h"
#include "data-access-service/data-access-persistency.h"

using namespace ::testing;
using namespace bird;
using namespace service;
using namespace std;

class DataAccessPersistencyGTest : public Test
{
    public:
    NiceMock<CheckinBundleAccessMock> checkin_bundle_access;
    DataAccessPersistency data_access_persistency_service;

    public:
    DataAccessPersistencyGTest(void)
    : checkin_bundle_access(),
    data_access_persistency_service(checkin_bundle_access)
    {}
};

TEST_F(DataAccessPersistencyGTest, get_all_checkin_bundles)
{
    CheckinBundle checkin_bundle("account_id", "timestamp");
    InSequence s1;
    EXPECT_CALL(this->checkin_bundle_access, empty()).Times(5).WillRepeatedly(Return(false));
    EXPECT_CALL(this->checkin_bundle_access, pop()).WillRepeatedly(Return(checkin_bundle));

    vector<CheckinBundle> all_checkin_bundles = this->data_access_persistency_service.get_all_checkin_bundles();

    for (auto & given_bundle : all_checkin_bundles)
    {
        EXPECTEQ(checkin_bundle.get_account_id(), given_bundle.get_account_id());
        EXPECTEQ(checkin_bundle.get_timestamp(), given_bundle.get_timestamp());
    }
}

TEST_F(DataAccessPersistencyGTest, put_checkin_bundles)
{
    vector<CheckinBundle> checkin_bundles;
    checkin_bundles.push_back(CheckinBundle("account_id", "timestamp"));
    checkin_bundles.push_back(CheckinBundle("account_id", "timestamp"));

    EXPECT_CALL(this->checkin_bundle_access, push(_)).Times(2);
    EXPECT_CALL(this->checkin_bundle_access, commit()).Times(1);

    this->data_access_persistency_service.put_checkin_bundles(checkin_bundles);
}
