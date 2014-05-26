/*
 * read.h
 *
 *  Created on: Feb 4, 2013
 *      Author: bhikadiy
 */
#ifndef READ_H_
#define READ_H_


#include "includes.h"
#include "Img.h"

class reader
{
	 std::vector<Img> &img, &test;
public:
	reader();
	reader(std::vector<Img>&i, std::vector<Img>&t):img(i),test(t){};
	void image_read(std::vector<std::string>);
	void test_read(std::vector<std::string>);
	void push_data(std::string,unsigned int);
	void push_test(std::string,unsigned int);
	virtual ~reader();
};

#endif /* READ_H_ */
