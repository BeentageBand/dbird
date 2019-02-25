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
        inline int get_mid(void){ return this->mid;}
        inline int get_tid(void){ return this->tid;}
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

        inline Payload const & get_payload(void) const { return this->payload;}
    };
}