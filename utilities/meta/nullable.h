#pragma once

namespace meta
{
    <template T>
    class Nullable
    {
        private:
        T * t;
        public:
        static Nullable of(T & t) { return Nullable(t) };
        static Nullable empty(void) { return Nullable(); }

        Nullable(void)
        : t (nullptr)
        {}

        explicit Nullable(T & t)
        : t(&t)
        {}

        virtual ~Nullable(void){}

        inline T & get(void) { return *this->t; } // This may cause segfault
        inline T & or_else(T & else_t)
        {
            return (this->is_present())? this->t : else_t;
        }

        <typename Pred>
        inline Nullable filter(Pred const pred)
        {
            return (this->is_present() && pred(*this->t))? Nullable::of(this->t) : Nullable::empty();
        }
        
        inline bool is_present(void) { return nullptr != this->t; }

        <typename F>
        inline void if_present(F & functor) 
        {
            if(this->is_present())
            {
                functor(*this->t);
            }
        }

    };
}
