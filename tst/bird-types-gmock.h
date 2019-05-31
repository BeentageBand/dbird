#pragma-once
#include "gmock/gmock.h"
#include "checkin-bundle-parser.h"

class CheckinBundleParserMock : public bird::Checkin_Bundle_Parser
{
    public:
    MOCK_METHOD1(parse_to_checkin_bundle, bird::Checkin_Bundle (std::string const & data));
    MOCK_METHOD1(parse_to_string, std::string (std::vector<bird::Checkin_Bundle> const & checkin_bundles));
};
