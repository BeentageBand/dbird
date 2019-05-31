#pragma once

namespace ipc
{
    class Message
    {
        protected:
        int const mid;
        int const tid;

        public:
        Message(int const mid, int const tid)
        : mid(mid), tid(tid)
        {}

        virtual ~Message(void){}
        inline int get_mid(void) const { return this->mid;}
        inline int get_tid(void) const { return this->tid;}

        inline bool operator==(Message const & other) const
        {
            if (&other == this) return true;
            return this->mid == other.get_mid() &&
                this->tid == other.get_tid();
        }

        inline bool operator!=(Message const & other) const { return !(*this == other); }
    };

    
    template<typename Payload>
    class Message_With_Payload : public Message
    {
        private:
        Payload const payload;

        public:
        Message_With_Payload(int const mid, int const tid, Payload const & payload)
        : Message(mid, tid), payload(payload)
        {}

        inline Payload & get_payload(void) const { return this->payload;}

        inline bool operator==(Message_With_Payload const & other) const
        {
            if (&other == this) return true;
            return this->mid == other.get_mid() &&
                this->tid == other.get_tid();
        }

        inline bool operator!=(Message_With_Payload const & other) const { return !(*this == other); }
    };
}
