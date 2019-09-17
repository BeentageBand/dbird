/*
 * dal.h
 *
 *  Created on: Sep 16, 2019
 *      Author: roalanis
 */

#ifndef DAL_H_
#define DAL_H_
#include "json/json.h"

namespace persistency {
class DAL {

public:
	DAL(void)
{}

	virtual ~DAL(void) {}

	virtual Json::Value get_json(const std::string &filename)
	{
		std::ifstream ifs;
		ifs.open(filename, std::fstream::in);
		Json::Value json;
		ifs >> json;
		ifs.close();
		return json;
	}

	virtual void put_json(const Json::Value &json, const std::string &filename)
	{
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::app);
		ofs << json;
		ofs.close();
	}
};


}


#endif /* DAL_H_ */
