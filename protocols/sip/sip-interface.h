#pragma once
#include <string>

namespace protocols
{
    class SIP_Interface
    {
        public:
        virtual ~SIP_Interface(void){}

        virtual bool empty(void) {return false;}
        virtual std::string read(void)
        {
            return std::string("account_id-00/00/00-00:00:00");
        }

        virtual void write(std::string const & data) {}
    };
}