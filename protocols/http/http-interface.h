#pragma once
#include <string>

namespace protocols
{
    class HTTPInterface
    {
        public:
        virtual ~HTTPInterface(void) {}
        virtual void open_session(void) {}
        virtual void post(std::string const & data) {}
        virtual void close_session(void) {}
    };
}
