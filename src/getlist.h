/*
 * getlist.h
 *
 *  Created on: Feb 8, 2013
 *      Author: bhikadiy
 */

#ifndef GETLIST_H_
#define GETLIST_H_

#include "includes.h"
#include "include_boost.h"
class getlist {
public:
	getlist();
	std::vector<std::string> get_file_list(std::string a);
	void append_dir(std::string);
	virtual ~getlist();
};

#endif /* GETLIST_H_ */
