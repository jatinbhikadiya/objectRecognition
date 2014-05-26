/*
 * read.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: bhikadiy
 */

#include "reader.h"



void reader::image_read(std::vector<std::string> path)
{
	 unsigned int index = 0;
	    for (index = 0; index <path.size(); index++)
	    {
	        push_data(path.at(index),index);
	    	//std::cout<<index<<std::endl;
	    }
	  /*  std::vector<Img>::const_iterator it;
	    for (it = img.begin(); it != img.end() ; it++)
	    {
	    	(*it).showme();
	    }*/

}

void reader::test_read(std::vector<std::string> path)
{
	unsigned int index = 0;
	for (index = 0; index <path.size() ; index++)
	{
		push_test(path.at(index),index);
		//std::cout<<index<<std::endl;

	}

	/*std::vector<Img>::iterator it;
	for (it = templates.begin(); it != templates.end() ; it++)
	{
		(*it).showme();
	}*/

}

void reader:: push_data(std::string path, unsigned int i)
{
	Img temp;
	img.push_back(temp);
	img.at(i).readme(path);
}

void reader:: push_test(std::string path, unsigned int i)
{
	Img temp;
	test.push_back(temp);
	test.at(i).readme(path);
}

reader::~reader() {
	// TODO Auto-generated destructor stub
}

