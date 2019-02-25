#pragma once
#include <string>

namespace protocols
{
    class HTTP
    {
        public:
        virtual void open_session(void) {}
        virtual void post(std::string const & data) {}
        virtual void close_session(void) {}
    };
}