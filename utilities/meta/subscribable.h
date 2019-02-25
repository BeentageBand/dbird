#pragma once

namespace meta
{
    template<typename OBJECT>
    class Subscribable
    {
        private:
        std::vector<OBJECT> subscription;
        public:
        Subscribable(void)
        : subscription()
        {}

        virtual ~Subscribable(void){}

        bool subscribe(OBJECT & object)
        {
            this->subscription.push_back(object);
        }

        template<typename T, typename FUNCTION>
        void foreach(T & host, handle)
        {
            for(auto & each : this->subscription)
            {
                host.*(handle)(each);
            }
        }

        bool unsubscribe(OBJECT & object)
        {
            this->subscription.push_back(object);
        }
    };
}