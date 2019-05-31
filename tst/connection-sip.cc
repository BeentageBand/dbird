#include "gmock/gmock.h"
#include "connection-service/connection-sip.h"
#include "bird-types-gmock.h"
#include "protocols-gmock.h"

using namespace ::testing;
using namespace bird;
using namespace protocols;
using namespace service;
using namespace std;

class ConnectionSIPGTest : public Test
{
    public:
    NiceMock<SIPMock> sip_protocol;
    NiceMock<CheckinBundleParserMock> checkin_bundle_parser;
    Connection_SIP connection_sip_service;

    public:
    ConnectionSIPGTest(void)
    : sip_protocol(),
    checkin_bundle_parser(),
    connection_sip_service(sip_protocol, checkin_bundle_parser)
    {}
};

/**
 * Given send_checkin_bundle
 * when parser_data is not empty
 * call sip.write
 */
TEST_F(ConnectionSIPGTest, send_checkin_bundles_when_not_empty)
{
    vector<Checkin_Bundle> checkin_bundles;
    string checkin_data("account_id timestamp");
    checkin_bundles.push_back(Checkin_Bundle("account_id", "timestamp"));
    EXPECT_CALL(this->checkin_bundle_parser, parse_to_string(checkin_bundles)).WillOnce(Return(checkin_data));
    EXPECT_CALL(this->sip_protocol, write(checkin_data)).Times(1);
    this->connection_sip_service.send_checkin_bundles(checkin_bundles);
}

/**
 * Given send_checkin_bundle
 * when parser_data is empty
 * call nothing
 */
TEST_F(ConnectionSIPGTest, send_checkin_bundles_when_empty)
{
    vector<Checkin_Bundle> checkin_bundles;
    string checkin_data;
    EXPECT_CALL(this->checkin_bundle_parser, parse_to_string(checkin_bundles)).WillOnce(Return(checkin_data));
    EXPECT_CALL(this->sip_protocol, write(checkin_data)).Times(0);
    this->connection_sip_service.send_checkin_bundles(checkin_bundles);
}
