#pragma once
#include "gmock/gmock.h"
#include "connection-service/connection-interface.h"
#include "data-access-service/data-access-interface.h"
#include "data-reader-service/data-reader-interface.h"
#include "server-service/server-interface.h"

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

class DataReaderMock : public service::Data_Reader_Interface
{
    public:
    MOCK_METHOD0(get_all_checkin_bundles, std::vector<bird::Checkin_Bundle> ());
};

class ServerMock : public service::Server_Interface 
{
    public:
       MOCK_METHOD0(bootup, void ());
       MOCK_METHOD0(update, void ());
       MOCK_METHOD1(handle_status, void (ipc::Message const & msg));
       MOCK_METHOD0(shutdown, void ());
};
