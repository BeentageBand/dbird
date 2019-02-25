#pragma once
#include "type-list.h"

namespace meta
{
    template<int THIS, typename NEXT_TL>
    struct EL
    {
        enum {This = THIS};
        NEXT_TL list;
    };

    template<typename ELS> struct EL_Size;

    template<>
    struct EL_Size<Null>
    {
        enum {Size = 0};
    };

    template<int THIS, typename NEXT_TL>
    struct EL_Size<EL<THIS, NEXT_TL>>
    {
        private:
        enum {Next_Size = EL_Size<NEXT_TL>::Size};
        public:
        enum {Size = Next_Size + 1};
    };

    template<int I, typename ELS> struct EL_At;

    template<int I>
    struct EL_At<I, Null>
    {
        enum {At = -1};
        typedef Null At_TL;
    };

    template<int THIS, typename NEXT_TL>
    struct EL_At<0, EL<THIS, NEXT_TL>>
    {
        enum {At = THIS};
        typedef EL<THIS, NEXT_TL> At_TL;
    };

    template<int I, int THIS, typename NEXT_TL>
    struct EL_At<I, EL<THIS, NEXT_TL>>
    {
        private:
        enum {Next_I = I - 1};
        public:
        enum {At = EL_At<Next_I, NEXT_TL>::At};
        typedef typename EL_At<Next_I, NEXT_TL>::At_TL At_TL;
    };

    template<int FOUND, typename ELS> struct EL_Find;

    template<int FOUND>
    struct EL_Find<FOUND, Null>
    {
        enum {Find = -1};
        typedef Null Find_TL;
    };

    template<int FOUND, typename NEXT_TL>
    struct EL_Find<FOUND, EL<FOUND, NEXT_TL>>
    {
        enum {Find = FOUND};
        typedef EL<FOUND, NEXT_TL> Find_TL;
    };

    template<int FOUND, int THIS, typename NEXT_TL>
    struct EL_Find<FOUND, EL<THIS, NEXT_TL>>
    {
        enum {Find = EL_Find<FOUND, NEXT_TL>::Find};
        typedef typename EL_Find<FOUND, NEXT_TL>::Find_TL Find_TL;
    };
}