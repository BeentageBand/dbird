/*
 * component.h
 *
 *  Created on: Sep 14, 2019
 *      Author: roalanis
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_
#include <memory>
#include "typelist.h"
#include "inject.h"

namespace ccjuice {

template<typename C> class ComponentVisitor;

template<typename T>
class ComponentVisitor<meta::List<T>> {
	Inject<T> inject;
public:

	void build(std::shared_ptr<T> & t) {
		inject.build(t);
	}
};

template<typename T, typename ...L>
class ComponentVisitor<meta::List<T, L...> >
: public ComponentVisitor<meta::List<L...> > {
	Inject<T> inject;
public:

	void build(std::shared_ptr<T> & t) {
		inject.build(t);
	}
};

template<typename T>
class Component
		: public ComponentVisitor<typename T::ComponentList> {
};

}

#endif /* COMPONENT_H_ */
