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
    typedef meta::EL<CLK_TIMER_TOUT_MID, meta::Null> ReadDataTL;

    class ReadDataApp : public worker::MessageHandler
    {
        private:
        service::DataAccessInterface * data_access_service;
        service::DataReaderInterface * data_reader_service;

        public:
        using worker::MessageHandler::on_loop;

        ReadDataApp(service::DataAccessInterface & data_access_service,
                      service::DataReaderInterface & data_reader_service)
        : data_access_service(&data_access_service), data_reader_service(&data_reader_service)
        {}

        void on_message(ipc::Message const & msg)
        {
            std::cout << "read-data-app::" << __func__ << std::endl;
        }

        void on_loop(void)
        {
            std::cout << "read-data-app::" << __func__ << std::endl;
            std::vector<bird::CheckinBundle> all_checkin_bundles =
                                            this->data_reader_service->get_all_checkin_bundles();
            if(all_checkin_bundles.empty()) return ;
            // TODO: Handle error
            this->data_access_service->put_checkin_bundles(all_checkin_bundles);
            //Do what message handle does
            worker::MessageHandler::on_loop();
        }
    };

}
