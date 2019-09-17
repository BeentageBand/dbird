#include "injection/standalone-component.h"
#include "worker/dispatcher.h"

using namespace application;
using namespace bird;
using namespace ccjuice;
using namespace meta;
using namespace persistency;
using namespace protocols;
using namespace service;
using namespace std;
using namespace worker;

int main(void)
{
    // Component
    Component<StandaloneComponent> standalone_component;

    //Applications
    std::shared_ptr<Connection_Manager_App> connection_manager_app;
    std::shared_ptr<Push_Data_App> push_data_app;
    std::shared_ptr<Read_Data_App> read_data_app;

    standalone_component.build(connection_manager_app);
    standalone_component.build(push_data_app);
    standalone_component.build(read_data_app);

    //Dispatching
    Dispatcher dispatcher;
    dispatcher.append(*connection_manager_app);
    dispatcher.append(*read_data_app);
    dispatcher.append(*push_data_app);
    
    //Run
    Worker worker(dispatcher);
    worker.runnable();
    return 0;
}
