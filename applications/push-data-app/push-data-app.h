#pragma once
#include <iostream>
#include <vector>
#include "bird-mids.h"
#include "checkin-bundle.h"
#include "connection-service/connection-interface.h"
#include "data-access-service/data-access-interface.h"
#include "meta/enum-list.h"
#include "worker/message-handler.h"

namespace application
{
    typedef meta::EL<CLK_TIMER_TOUT_MID, meta::Null> Push_Data_TL;

    class Push_Data_App : public worker::Message_Handler
    {
        private:
        service::Data_Access_Interface * data_access_service; 
        service::Connection_Interface * connection_service;

        public:
        Push_Data_App(service::Data_Access_Interface & data_access_service, 
                      service::Connection_Interface & connection_service)
        : data_access_service(&data_access_service), connection_service(&connection_service)
        {}

        void on_message(ipc::Message const msg)
        {
            this->handle_message(msg);
        }

        void handle_message(ipc::Message const & msg)
        {
            std::cout << "push-data-app::" << __func__ << std::endl;
            std::vector<bird::Checkin_Bundle> all_checkin_bundles = 
                                            this->data_access_service->get_all_checkin_bundles();
            if(all_checkin_bundles.empty()) return ;
            // TODO: Handle error
            this->connection_service->send_checkin_bundles(all_checkin_bundles);
        }
    };
}