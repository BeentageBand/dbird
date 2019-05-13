#pragma once
#include <iostream>
#include <deque>
#include "sip-interface.h"

namespace protocols
{
    class SIP_Mifare : public protocols::SIP_Interface
    {
        private:
        std::deque<std::string> block_queue;
        public:
        bool empty(void)
        {
            return block_queue.empty();
        }

        std::string read(void)
        {
            std::string block = this->block_queue.back();
            this->block_queue.pop_back();
            return block;
        }

        void write(std::string const & data)
        {
            this->block_queue.push_front(data);
        }
    };
}