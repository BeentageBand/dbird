#pragma once
#include <string>

namespace bird
{
    class Checkin_Bundle
    {
        private:
        std::string account_id;
        std::string timestamp;

        public:
        Checkin_Bundle(std::string const & account_id, std::string const & timestamp)
        : account_id(account_id), timestamp(timestamp)
        {}

        virtual ~Checkin_Bundle(void){}
        
        inline std::string const & get_account_id(void) const {return this->account_id;}
        inline std::string const & get_timestamp(void) const {return this->timestamp;}
    };
}