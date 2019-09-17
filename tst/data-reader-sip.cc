#include "gmock/gmock.h"
#include "data-reader-service/data-reader-sip.h"
#include "bird-types-gmock.h"
#include "protocols-gmock.h"

using namespace ::testing;
using namespace bird;
using namespace protocols;
using namespace service;
using namespace std;

class DataReaderSIPGTest : public Test
{
public:
    NiceMock<SIPMock> sip_protocol;
    NiceMock<CheckinBundleParserMock> checkin_bundle_parser;
    DataReaderSIP data_reader_sip_service;

public:
    DataReaderSIPGTest(void)
: sip_protocol(),
  checkin_bundle_parser(),
  data_reader_sip_service(sip_protocol, checkin_bundle_parser)
{}
};

/**
 * Given get_checkin_bundle
 * when parser_data is not empty
 * call sip.write
 */
TEST_F(DataReaderSIPGTest, get_all_checkin_bundles_when_not_empty)
{
    string checkin_data("account_id timestamp");
    CheckinBundle checkin_bundle("account_id", "timestamp");
    EXPECT_CALL(this->sip_protocol, empty()).WillOnce(Return(false));
    EXPECT_CALL(this->sip_protocol, read()).WillOnce(Return(checkin_data));
    EXPECT_CALL(this->checkin_bundle_parser, parse_to_checkin_bundle(_))
        .WillOnce(Return(checkin_bundle));
    EXPECT_CALL(this->sip_protocol, empty()).WillOnce(Return(true));
    vector<CheckinBundle> given_checkin_bundles = this->data_reader_sip_service
	    .get_all_checkin_bundles();
    ASSERT_FALSE(given_checkin_bundles.empty());
    ASSERT_STRCASEEQ("account_id", given_checkin_bundles[0].get_account_id().c_str());
    ASSERT_STRCASEEQ("timestamp", given_checkin_bundles[0].get_timestamp().c_str());
}

/**
 * Given get_checkin_bundle
 * when parser_data is empty
 * call nothing
 */
TEST_F(DataReaderSIPGTest, get_checkin_bundles_when_empty)
{
    vector<CheckinBundle> checkin_bundles;
    string checkin_data;
    EXPECT_CALL(this->checkin_bundle_parser, parse_to_string(checkin_bundles)).WillOnce(Return(checkin_data));
    EXPECT_CALL(this->sip_protocol, write(checkin_data)).Times(0);
    vector<CheckinBundle> given_checkin_bundles = this->data_reader_sip_service.get_all_checkin_bundles();
    ASSERT_TRUE(given_checkin_bundles.empty());
}



