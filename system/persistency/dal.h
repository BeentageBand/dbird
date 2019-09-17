/*
 * dal.h
 *
 *  Created on: Sep 16, 2019
 *      Author: roalanis
 */

#ifndef DAL_H_
#define DAL_H_
#include <fstream>

namespace persistency {
class DAL {

public:
	DAL(void)
{}

	virtual ~DAL(void) {}

	virtual std::string get_file_data(const std::string &filename)
	{
		std::ifstream ifs;
		std::string data;
		ifs.open(filename, std::fstream::in);
		ifs >> data;
		ifs.close();
		return data;
	}

	virtual void put_file_data(std::string const & data, const std::string &filename)
	{
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::app);
		ofs << data;
		ofs.close();
	}
};


}


#endif /* DAL_H_ */
