/*
 * typelist.h
 *
 *  Created on: Sep 8, 2019
 *      Author: roalanis
 */

#ifndef TYPELIST_H_
#define TYPELIST_H_

namespace meta {

template <typename ...Types> struct List{};

struct Null_T{};

template <typename L1, typename L2> struct Concat;

template<>
struct Concat<List<Null_T>, List<Null_T> > {
	typedef List<Null_T> NewList;
};

template<typename ...L1>
struct Concat<List<L1...>, List<Null_T> > {
	typedef List<L1...> NewList;
};

template<typename ...L2>
struct Concat<List<Null_T>, List<L2...> > {
	typedef List<L2...> NewList;
};

template<typename ...L1, typename ...L2>
struct Concat<List<L1...>, List<L2...>> {
	typedef List<L1..., L2...> NewList;
};

}

#endif /* TYPELIST_H_ */
