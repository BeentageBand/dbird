#include "gmock/gmock.h"
#include <vector>
#include "services-gmock.h"
#include "read-data-app/read-data-app.h"

using namespace application;
using namespace bird;
using namespace ::testing;
using namespace std;

class ReadDataAppGTest : public Test
{
    public:
    NiceMock<DataAccessMock> data_access_service;
    NiceMock<DataReaderMock> data_reader_service;
    Read_Data_App read_data;

    public:
    ReadDataAppGTest(void)
    : data_access_service(),
    data_reader_service(),
    read_data(data_access_service, data_reader_service)
    {}

};


/**
 * Given app 
 * When on_loop
 * Then execute server_service->udpate
 */
TEST_F(ReadDataAppGTest, on_loop)
{
    vector<Checkin_Bundle> checkin_bundles;
    checkin_bundles.push_back(Checkin_Bundle("account_id", "timestamp"));
    EXPECT_CALL(this->data_reader_service, get_all_checkin_bundles()).WillOnce(Return(checkin_bundles));
    EXPECT_CALL(this->data_access_service, put_checkin_bundles(checkin_bundles)).Times(1);
    this->read_data.on_loop();
}
