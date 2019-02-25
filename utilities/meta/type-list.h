#pragma once
#include "xmac.h"

#define DEF_TLIST(...)  EVAL4(WHILE(CHECK, TEMPLATE_TLIST, __VA_ARGS__, meta::Null, dummy))
#define TLIST_PRIMITIVE(a, ...) meta::TL < a, __VA_ARGS__ >
#define TLIST(a, ...) TLIST_PRIMITIVE(a, __VA_ARGS__)
#define TEMPLATE_TLIST(a, ...) TLIST(a, IF( CHECK(__VA_ARGS__) )(TLIST(_, __VA_ARGS__), ) ) 
namespace meta
{
    struct Null{};

    template<typename THIS, typename NEXT_TL>
    struct TL
    {
        typedef THIS This;
        typedef typename NEXT_TL::This Next;
        typedef NEXT_TL Next_TL;
        THIS value;
        NEXT_TL list;
    };

    template<typename TLS> struct TL_Size;

    template<>
    struct TL_Size<Null>
    {
        enum {Size = 0};
    };

    template<typename THIS, typename NEXT_TL>
    struct TL_Size<TL<THIS, NEXT_TL>>
    {
        private:
        enum {Next_Size = TL_Size<NEXT_TL>::Size };
        public:
        enum {Size = Next_Size + 1};
    };

    template<int I, typename TLS> struct TL_At;

    template<int I>
    struct TL_At<I, Null>
    {
        typedef Null At;
        typedef Null At_TL;
    };

    template<typename THIS, typename NEXT_TL>
    struct TL_At<0, TL<THIS, NEXT_TL>>
    {
        typedef THIS At;
        typedef TL<THIS, NEXT_TL> At_TL;
    };

    template<int I, typename THIS, typename NEXT_TL>
    struct TL_At<I, TL<THIS, NEXT_TL>>
    {
        private:
        enum {Next_I = I - 1};
        public:
        typedef typename TL_At<Next_I, NEXT_TL>::At At;
        typedef typename TL_At<Next_I, NEXT_TL>::At_TL At_TL;
    };

    template<typename FOUND, typename TLS> struct TL_Find;

    template<typename FOUND>
    struct TL_Find<FOUND, Null>
    {
        enum {Found = -1};
        typedef Null Find;
        typedef Null Find_TL;
    };

    template<typename FOUND, typename NEXT_TL>
    struct TL_Find<FOUND, TL<FOUND, NEXT_TL>>
    {
        enum {Found = 0};
        typedef FOUND Find;
        typedef TL<FOUND, NEXT_TL> Find_TL;
    };

    template<typename FOUND, typename THIS, typename NEXT_TL>
    struct TL_Find<FOUND, TL<THIS, NEXT_TL>>
    {
        private:
        enum {Next_I = TL_Find<FOUND, NEXT_TL>::Found};
        public:
        enum {Found = Next_I + 1};
        typedef typename TL_Find<FOUND, NEXT_TL>::Find Find;
        typedef typename TL_Find<FOUND, NEXT_TL>::Find_TL Find_TL;
    };


}
