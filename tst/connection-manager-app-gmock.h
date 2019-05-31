#pragma once
#include "gmock/gmock.h"
#include "server-service/server-interface.h"

class ServerMock : public service::Server_Interface 
{
    public:
       MOCK_METHOD0(bootup, void ());
       MOCK_METHOD0(update, void ());
       MOCK_METHOD1(handle_status, void (ipc::Message const & msg));
       MOCK_METHOD0(shutdown, void ());
};
