#include "gmock/gmock.h"
#include "services-gmock.h"
#include "push-data-app/push-data-app.h"

using namespace application;
using namespace ::testing;
using namespace bird;
using namespace std;

class PushDataAppGTest :  public Test
{
    public:
    NiceMock<DataAccessMock> data_access_service;
    NiceMock<ConnectionServiceMock> connection_service;
    PushDataApp push_data;

    public:
    PushDataAppGTest(void)
    : data_access_service(),
    connection_service(),
    push_data(data_access_service, connection_service)
    {}

};


/**
 * Given app 
 * When on_message
 * Then execute server_service->handle_status
 */
TEST_F(PushDataAppGTest, on_message)
{
    ipc::Message msg(0,1);
    vector<CheckinBundle> checkin_bundles;
    checkin_bundles.push_back(CheckinBundle("account_id", "timestamp"));
    EXPECT_CALL(this->data_access_service, get_all_checkin_bundles()).WillOnce(Return(checkin_bundles));
    EXPECT_CALL(this->connection_service, send_checkin_bundles(_)).Times(1);
    this->push_data.on_message(msg);
}
