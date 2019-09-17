/*
 * module.h
 *
 *  Created on: Sep 14, 2019
 *      Author: roalanis
 */

#ifndef MODULE_H_
#define MODULE_H_

namespace ccjuice {

template<typename L> class ModuleVisitor;

template<typename T>
class Module : public ModuleVisitor<typename T::ProviderList>{

};

}

#endif /* MODULE_H_ */
