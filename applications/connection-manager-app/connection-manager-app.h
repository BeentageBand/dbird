#pragma once
#include "bird-mids.h"
#include "ipc/message.h"
#include "meta/enum-list.h"
#include "server-service/server-interface.h"
#include "worker/message-handler.h"

namespace application
{
    typedef meta::EL<CONNECTION_MGR_STATUS_MID, meta::Null> Connection_Manager_App_EL;
    class Connection_Manager_App :  public worker::Message_Handler
    {
        private:
        service::Server_Interface * server_service;
        public:
        Connection_Manager_App(service::Server_Interface & server_service)
        : server_service(&server_service)
        {}

        virtual ~Connection_Manager_App(void) {}

        void on_start(void)
        {
            std::cout << "connection-manager-app::"<< __func__ << std::endl;
            this->server_service->bootup();
        }

        void on_loop(void)
        {
            std::cout << "connection-manager-app::"<< __func__ << std::endl;
            this->server_service->update();
        }

        void on_message(ipc::Message const & msg)
        {
            std::cout << "connection-manager-app::"<< __func__ << std::endl;
            this->handle_message(msg);
        }

        void handle_message(ipc::Message const & msg)
        {
            std::cout << "connection-manager-app::"<< __func__ << std::endl;
            this->server_service->handle_status(msg);
        }

        void on_stop(void)
        {
            std::cout << "connection-manager-app::"<< __func__ << std::endl;
            this->server_service->shutdown();
        }
    };
}