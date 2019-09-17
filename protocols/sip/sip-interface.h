#pragma once
#include <string>

namespace protocols
{
    class SIPInterface
    {
        public:
        virtual ~SIPInterface(void){}

        virtual bool empty(void) = 0;
        virtual std::string read(void) = 0;
        virtual void write(std::string const & data) = 0;
    };
}
