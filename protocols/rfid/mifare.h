#pragma once
#include <string>

namespace protocols
{
    class Mifare
    {
        public:
        virtual bool empty(void) {return true;}
        virtual std::string read_block(void) { return std::string(" ");}
    };
}