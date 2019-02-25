#include "checkin-bundle-parser-sip-block.h"
#include "connection-manager-app/connection-manager-app.h"
#include "connection-service/connection-sip.h"
#include "data-access-service/data-access-persistency.h"
#include "data-reader-service/data-reader-sip.h"
#include "persistency/checkin-bundle-access-volatile.h"
#include "push-data-app/push-data-app.h"
#include "read-data-app/read-data-app.h"
#include "server-service/server-master-slave.h"
#include "worker/dispatcher.h"

using namespace bird;
using namespace application;
using namespace persistency;
using namespace protocols;
using namespace service;
using namespace std;
using namespace worker;

int main(void)
{
    //System 
    //TODO system implementation

    // Modules
    Checkin_Bundle_Access_Volatile checkin_bundle_access_volatile;
    Checkin_Bundle_Parser_SIP_Block checkin_bundle_parser_sip_block;
    SIP_Interface sip;

    //Services
    Connection_SIP connection_service(sip, checkin_bundle_parser_sip_block);
    Data_Access_Persistency data_access_service(checkin_bundle_access_volatile);
    Data_Reader_SIP data_reader_service(sip, checkin_bundle_parser_sip_block);
    Server_Master_Slave server_service(sip);

    //Applications
    Connection_Manager_App connection_manager_app(server_service);
    Push_Data_App push_data_app(data_access_service, connection_service);
    Read_Data_App read_data_app(data_access_service, data_reader_service);

    Worker workers[] = {Worker(push_data_app), Worker(read_data_app)};

    //Dispatching
    Dispatcher dispatcher;
    dispatcher.append(connection_manager_app);
    dispatcher.append(push_data_app);
    dispatcher.append(read_data_app);
    
    //Run
    Worker worker(dispatcher);
    worker.runnable();
    return 0;
}