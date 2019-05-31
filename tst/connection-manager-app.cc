#include "gmock/gmock.h"
#include "services-gmock.h"
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
    : server_service(),
    connection_manager(server_service)
    {}

};

/**
 * Given app 
 * When on_start
 * Then execute server_service->bootup
 */
TEST_F(ConnectionManagerAppGTest, on_start)
{
    EXPECT_CALL(this->server_service, bootup()).Times(1);
    this->connection_manager.on_start();
}

/**
 * Given app 
 * When on_loop
 * Then execute server_service->udpate
 */
TEST_F(ConnectionManagerAppGTest, on_loop)
{
    EXPECT_CALL(this->server_service, update()).Times(1);
    this->connection_manager.on_loop();
}


/**
 * Given app 
 * When on_message
 * Then execute server_service->handle_status
 */
TEST_F(ConnectionManagerAppGTest, on_message)
{
    ipc::Message msg(0, 1);
    EXPECT_CALL(this->server_service, handle_status(_)).Times(1);
    this->connection_manager.on_message(msg);
}
