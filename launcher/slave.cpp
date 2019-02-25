#include "checkin-bundle-parser.h"
#include "checkin-bundle-parser-json.h"
#include "checkin-bundle-parser-mifare-block.h"
#include "connection-service/connection-http.h"
#include "data-access-service/data-access-persistency.h"
#include "data-reader-service/data-reader-mifare.h"
#include "persistency/checkin-bundle-access-fs.h"
#include "push-data-app/push-data-app.h"
#include "read-data-app/read-data-app.h"

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
    Checkin_Bundle_Access_FS checkin_bundle_access_fs;
    Checkin_Bundle_Parser_JSON checkin_bundle_parser_json;
    Checkin_Bundle_Parser_Mifare_Block checkin_bundle_parser_mifare_block;
    HTTP http;
    Mifare mifare;

    //Services
    Connection_HTTP connection_service(http, checkin_bundle_parser_json);
    Data_Access_Persistency data_access_service(checkin_bundle_access_fs);
    Data_Reader_Mifare data_reader_service(mifare, checkin_bundle_parser_mifare_block);

    //Applications
    Push_Data_App push_data_app(data_access_service, connection_service);
    Read_Data_App read_data_app(data_access_service, data_reader_service);

    Worker workers[] = {Worker(push_data_app), Worker(read_data_app)};

    //Run
    for(auto & worker : workers)
    {
        worker.runnable();
    }
    return 0;
}