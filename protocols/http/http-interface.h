#pragma once
#include <string>

namespace protocols
{
    class HTTP_Interface
    {
        public:
        virtual ~HTTP_Interface(void) {}
        virtual void open_session(void) {}
        virtual void post(std::string const & data) {}
        virtual void close_session(void) {}
    };
}