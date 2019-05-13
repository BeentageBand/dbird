#pragma once
#include "gmock/gmock.h"
#include "service-service/server-interface.h"

class ServerMock : public Server_Interface 
{
    public:
       GMOCK_METHOD0(boot, void (void));
       GMOCK_METHOD0(update, void update(void));
       GMOCK_METHOD1(handle_status, void (ipc::Message const & msg));
       GMOCK_METHOD0(shutdown, void (void));
};
