#pragma once
#include "gmock/gmock.h"
#include "connection-service/connection-interface.h"
#include "data-access-service/data-access-interface.h"

class ConnectionServiceMock : public service::Connection_Interface
{
    public:
    MOCK_METHOD1(send_checkin_bundles, void (std::vector<bird::Checkin_Bundle> & checkin_bundles));
};

class DataAccessMock : public service::Data_Access_Interface
{
    public:
    MOCK_METHOD0(get_all_checkin_bundles, std::vector<bird::Checkin_Bundle> ());
    MOCK_METHOD1(put_checkin_bundles, void (std::vector<bird::Checkin_Bundle> & checkin_bundles));
};
