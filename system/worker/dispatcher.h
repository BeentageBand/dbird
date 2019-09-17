#pragma once
#include <vector>
#include <utility>
#include "bundle.h"
#include "unistd.h"
namespace worker
{
    class Dispatcher : public Bundle
    {
        private:
        typedef std::pair<int, Bundle *> BundleClient;
        std::vector<BundleClient> bundles;
        int bundle_id;
        public:
        Dispatcher(void)
        : bundles(), bundle_id()
        {}

        virtual ~Dispatcher(void)
        {
            this->bundles.clear();
        }

        void append(Bundle & bundle)
        {
            std::cout << "Dispatcher::" << __func__ << " client " << this->bundle_id << std::endl;
            this->bundles.push_back(std::make_pair(this->bundle_id, &bundle));
            ++this->bundle_id;
        }

        void on_start(void)
        {
            for(auto & bundle : this->bundles)
            {
                std::cout << "Dispatcher::" << __func__ << " client " << bundle.first << std::endl;
                bundle.second->on_start();
            }
        }

        void on_message(ipc::Message const & msg)
        {
            for(auto & bundle : this->bundles)
            {
                std::cout << "Dispatcher::" << __func__ << " client " << bundle.first << std::endl;
                bundle.second->on_message(msg);
            }
        }

        void on_loop(void)
        {
            for(auto & bundle : this->bundles)
            {
                std::cout << "Dispatcher::" << __func__ << " client " << bundle.first << std::endl;
                bundle.second->on_loop();
            }
            sleep(1);
        }

        void on_stop(void)
        {
            for(auto & bundle : this->bundles)
            {
                std::cout << "Dispatcher::" << __func__ << " client " << bundle.first << std::endl;
                bundle.second->on_stop();
            }
        }
    };
}
