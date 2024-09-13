#include "gmock/gmock.h"
#include <vector>
#include "bird-types-gmock.h"
#include "protocols-gmock.h"
#include "connection-http.h"

using namespace ::testing;
using namespace bird;
using namespace service;
using namespace std;

class ConnectionHTTPGTest : public Test
{
    public:
    NiceMock<HTTPMock> http_protocol;
    NiceMock<CheckinBundleParserMock> checkin_bundle_parser;
    ConnectionHTTP connection_http_service;

    public:
    ConnectionHTTPGTest(void)
    : http_protocol(),
    checkin_bundle_parser(),
    connection_http_service(http_protocol, checkin_bundle_parser)
    {}

};


/**
 * Given send_checkin_bundle
 * when parser_data is not empty
 * call sip.write
 */
TEST_F(ConnectionHTTPGTest, send_checkin_bundles_when_not_empty)
{
    vector<CheckinBundle> checkin_bundles;
    string checkin_data("account_id timestamp");
    checkin_bundles.push_back(CheckinBundle("account_id", "timestamp"));
    EXPECT_CALL(this->checkin_bundle_parser, parse_to_string(checkin_bundles)).WillOnce(Return(checkin_data));
    EXPECT_CALL(this->http_protocol, open_session()).Times(1);
    EXPECT_CALL(this->http_protocol, post(checkin_data)).Times(1);
    EXPECT_CALL(this->http_protocol, close_session()).Times(1);
    this->connection_http_service.send_checkin_bundles(checkin_bundles);
}

/**
 * Given send_checkin_bundle
 * when parser_data is empty
 * call nothing
 */
TEST_F(ConnectionHTTPGTest, send_checkin_bundles_when_empty)
{
    vector<CheckinBundle> checkin_bundles;
    string checkin_data;
    EXPECT_CALL(this->checkin_bundle_parser, parse_to_string(checkin_bundles)).WillOnce(Return(checkin_data));
    EXPECT_CALL(this->http_protocol, open_session()).Times(0);
    EXPECT_CALL(this->http_protocol, post(checkin_data)).Times(0);
    EXPECT_CALL(this->http_protocol, close_session()).Times(0);
    this->connection_http_service.send_checkin_bundles(checkin_bundles);
}
