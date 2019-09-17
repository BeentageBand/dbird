#pragma once
#include "sip-interface.h"

namespace protocols
{
    class SIPNet : public SIPInterface
    {
        public:

        bool empty(void)
        {
        	return true;
        }

        std::string read(void)
        {
        	return std::string();
        }

        void write(std::string const & data)
        {

        }
    };
} // namespace nam protocols
