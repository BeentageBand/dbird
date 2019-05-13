#pragma once
#include <string>

namespace protocols
{
    class SIP_Interface
    {
        public:
        virtual ~SIP_Interface(void){}

        virtual bool empty(void) = 0;
        virtual std::string read(void) = 0;
        virtual void write(std::string const & data) = 0;
    };
}