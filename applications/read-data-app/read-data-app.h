#pragma once
#include <iostream>
#include "bird-mids.h"
#include "checkin-bundle.h"
#include "data-access-service/data-access-interface.h"
#include "data-reader-service/data-reader-interface.h"
#include "meta/enum-list.h"
#include "worker/message-handler.h"

namespace application
{
    typedef meta::EL<CLK_TIMER_TOUT_MID, meta::Null> Read_Data_TL;

    class Read_Data_App : public worker::Message_Handler
    {
        private:
        service::Data_Access_Interface * data_access_service;
        service::Data_Reader_Interface * data_reader_service;

        public:
        Read_Data_App(service::Data_Access_Interface & data_access_service,
                      service::Data_Reader_Interface & data_reader_service)
        : data_access_service(&data_access_service), data_reader_service(&data_reader_service)
        {}

        void on_message(ipc::Message const & msg)
        {
            this->handle_message(msg);
        }

        void handle_message(ipc::Message const & msg)
        {
            std::cout << "push-data-app::" << __func__ << std::endl;
            std::vector<bird::Checkin_Bundle> all_checkin_bundles = 
                                            this->data_reader_service->get_all_checkin_bundles();
            if(all_checkin_bundles.empty()) return ;
            // TODO: Handle error
            this->data_access_service->put_checkin_bundles(all_checkin_bundles);
        }
    };

}