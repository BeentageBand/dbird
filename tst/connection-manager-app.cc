#include "gtest/gtest.h"
#include "connection-manager-app/connection-manager-app.h"

using namespace application;
using namespace ::testing;


class ConnectionManagerAppGTest :  public Test
{
    public:
        NiceMock<ServerMock> server_service;
        Connection_Manager_App connection_manager;
    public:
    ConnectionManagerAppGTest(void)
    : server_service(), connection_manager(server_service)
    {}

    void setup(void)
    {}
};

class 
/**
 * Given app 
 * When on_start
 * Then execute server_service->bootup
 */
TEST_F(Connection_Manager_App, on_start)
{
    EXPECT_CALL(this->server_service, bootup()).WillOnce();
    this->connection_manager.on_start();
}

/**
 * Given app 
 * When on_loop
 * Then execute server_service->udpate
 */
TEST_F(Connection_Manager_App, on_start)
{
    EXPECT_CALL(this->server_service, update()).WillOnce();
    this->connection_manager.on_loop();
}


/**
 * Given app 
 * When on_message
 * Then execute server_service->handle_status
 */
TEST_F(Connection_Manager_App, on_start)
{
    Message msg(0, 1);
    EXPECT_CALL(this->server_service, handle_status(msg)).WillOnce();
    this->connection_manager.on_message(msg);
}
