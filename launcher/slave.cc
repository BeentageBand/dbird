#include "checkin-bundle-parser-sip-block.h"
#include "connection-manager-app/connection-manager-app.h"
#include "connection-service/connection-sip.h"
#include "data-access-service/data-access-persistency.h"
#include "data-reader-service/data-reader-sip.h"
#include "persistency/checkin-bundle-access-volatile.h"
#include "persistency/dal.h"
#include "push-data-app/push-data-app.h"
#include "read-data-app/read-data-app.h"
#include "server-service/server-master-slave.h"
#include "sip/sip-net.h"
#include "sip/sip-mifare.h"
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
    CheckinBundleAccessVolatile checkin_bundle_access_volatile;
    CheckinBundleParserSIPBlock checkin_bundle_parser_sip_block;
    SIPMifare sip_mifare;
    SIPNet sip_net;
    DAL dal;

    //Services
    ConnectionSIP connection_service(sip_mifare, checkin_bundle_parser_sip_block);
    DataAccessPersistency data_access_service(checkin_bundle_access_volatile);
    DataReaderSIP data_reader_service(sip_mifare, checkin_bundle_parser_sip_block);
    ServerMasterSlave server_service(sip_net);

    //Applications
    ConnectionManagerApp connection_manager_app(server_service);
    PushDataApp push_data_app(data_access_service, connection_service);
    ReadDataApp read_data_app(data_access_service, data_reader_service);

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
