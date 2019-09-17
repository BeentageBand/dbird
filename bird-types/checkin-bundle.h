#pragma once
#include <string>

namespace bird
{
    class CheckinBundle
    {
        private:
        std::string account_id;
        std::string timestamp;

        public:
        CheckinBundle(std::string const & account_id, std::string const & timestamp)
        : account_id(account_id), timestamp(timestamp)
        {}

        virtual ~CheckinBundle(void){}
        
        inline std::string const & get_account_id(void) const {return this->account_id;}
        inline std::string const & get_timestamp(void) const {return this->timestamp;}

        inline bool operator==(CheckinBundle const & other) const
        {
            if (&other == this) return true;
            return this->account_id == other.get_account_id() &&
                this->timestamp == other.get_timestamp();
        }
        
        inline bool operator!=(CheckinBundle const & other) const { return !(*this == other);}
    };
}
