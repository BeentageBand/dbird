/*
 * provide.h
 *
 *  Created on: Sep 7, 2019:w
 *      Author: roalanis
 */

#ifndef PROVIDE_H_
#define PROVIDE_H_

#include <memory>

namespace ccjuice {
template<typename T> class Inject;
template<typename ...T> class Provide;

template<typename I, typename T>
class Provide<I, T> {

public:
	I & provide(Inject<T> & injection) {
		return *injection.build();
	}
};

template<typename T>
class Provide<T> {
public:
	T & provide(Inject<T> & injection) {
		return *injection.build();
	}
};

}

#endif /* PROVIDE_H_ */
