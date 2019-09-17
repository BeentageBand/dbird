#pragma-once
#include "gmock/gmock.h"
#include "checkin-bundle-parser.h"

class CheckinBundleParserMock : public bird::CheckinBundleParser
{
    public:
    MOCK_METHOD1(parse_to_checkin_bundle, bird::CheckinBundle (std::string const & data));
    MOCK_METHOD1(parse_to_string, std::string (std::vector<bird::CheckinBundle> const & checkin_bundles));
};
