/*
 * manager.h
 *
 *  Created on: Feb 4, 2013
 *      Author: bhikadiy
 */
#ifndef MANAGER_H_
#define MANAGER_H_
#include "includes.h"
#include "reader.h"
#include "BOF.h"
#include "Img.h"
#include "getlist.h"


class manager
{

	std::vector<Img> img_data;
	std::vector<Img> zebra;
	std::vector<Img> leopards;
	std::vector<Img> automobiles;
	std::vector<Img> airplane;
	std::vector<Img> test_data;
	std::vector<std::pair<std::string,int> >set_name_index;
	getlist mylist;
	std::vector<std::string> data_path_list;
	std::vector<std::string> test_path_list;
	bool TEST=1;
	public:

	manager();
	void read_data(char **,int);
	void classifynames();

	void train();
	void display_results();
	virtual ~manager();
};

#endif /* MANAGER_H_ */
