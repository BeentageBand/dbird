/*
 * inject.h
 *
 *  Created on: Sep 8, 2019
 *      Author: roalanis
 */

#ifndef INJECT_H_
#define INJECT_H_

#include <memory>
#include "typelist.h"
#include "provide.h"

namespace ccjuice {

template<typename O, typename L> class InjectionVisitor;

template<typename O>
class InjectionVisitor<O, meta::Null_T> {
public:
	void build(std::shared_ptr<O> & t) {
		t.reset(new O);

	}
};

template<typename O, typename T1>
class InjectionVisitor<O, meta::List<T1>> {
	T1 t1;
public:
	void build(std::shared_ptr<O> & t) {
		t.reset(new O(this->t1));

	}
};

template<typename O, typename T1, typename T2>
class InjectionVisitor<O, meta::List<T1,T2>> {
	T1 t1;
	T2 t2;
public:
	void build(std::shared_ptr<O> & t) {
		t.reset(new O(this->t1, this->t2));

	}
};

template<typename T>
class Inject : public InjectionVisitor<T, typename T::InjectionList> {

};
}

#endif /* INJECT_H_ */
