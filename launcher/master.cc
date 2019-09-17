#include "checkin-bundle-parser-json.h"
#include "checkin-bundle-parser-sip-block.h"
#include "connection-manager-app/connection-manager-app.h"
#include "connection-service/connection-http.h"
#include "data-access-service/data-access-persistency.h"
#include "data-reader-service/data-reader-sip.h"
#include "persistency/checkin-bundle-access-fs.h"
#include "push-data-app/push-data-app.h"
#include "read-data-app/read-data-app.h"
#include "server-service/server-master-slave.h"
#include "server-service/server-modem.h"
#include "sip/sip-net.h"
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
	DAL dal;

    // Modules
    CheckinBundleParserJSON checkin_bundle_parser_json;
    CheckinBundleParserSIPBlock checkin_bundle_parser_sip_block;
    CheckinBundleAccessFS checkin_bundle_access_fs(dal, checkin_bundle_parser_json);
    HTTPInterface http;
    SIPNet sip_net;
    ModemInterface modem;

    //Services
    ConnectionHTTP connection_service(http, checkin_bundle_parser_json);
    DataAccessPersistency data_access_service(checkin_bundle_access_fs);
    DataReaderSIP data_reader_service(sip_net, checkin_bundle_parser_sip_block);
    ServerMasterSlave server_master_slave_service(sip_net);
    ServerModem server_modem_service(modem);

    //Applications
    ConnectionManagerApp connection_mgr_modem_app(server_modem_service);
    ConnectionManagerApp connection_mgr_mst_slv_app(server_master_slave_service);
    PushDataApp push_data_app(data_access_service, connection_service);
    ReadDataApp read_data_app(data_access_service, data_reader_service);

    Worker workers[] = {Worker(push_data_app), Worker(read_data_app)};

    //Dispatching
    Dispatcher dispatcher;
    dispatcher.append(connection_mgr_modem_app);
    dispatcher.append(connection_mgr_mst_slv_app);
    dispatcher.append(push_data_app);
    dispatcher.append(read_data_app);
    
    //Run
    Worker worker(dispatcher);
    worker.runnable();
    return 0;
}
