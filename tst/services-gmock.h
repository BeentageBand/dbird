#pragma once
#include "gmock/gmock.h"
#include "connection-service/connection-interface.h"
#include "data-access-service/data-access-interface.h"
#include "data-reader-service/data-reader-interface.h"
#include "server-service/server-interface.h"

class ConnectionServiceMock : public service::ConnectionInterface
{
    public:
    MOCK_METHOD1(send_checkin_bundles, void (std::vector<bird::CheckinBundle> & checkin_bundles));
};

class DataAccessMock : public service::DataAccessInterface
{
    public:
    MOCK_METHOD0(get_all_checkin_bundles, std::vector<bird::CheckinBundle> ());
    MOCK_METHOD1(put_checkin_bundles, void (std::vector<bird::CheckinBundle> & checkin_bundles));
};

class DataReaderMock : public service::DataReaderInterface
{
    public:
    MOCK_METHOD0(get_all_checkin_bundles, std::vector<bird::CheckinBundle> ());
};

class ServerMock : public service::ServerInterface
{
    public:
       MOCK_METHOD0(bootup, void ());
       MOCK_METHOD0(update, void ());
       MOCK_METHOD1(handle_status, void (ipc::Message const & msg));
       MOCK_METHOD0(shutdown, void ());
};
