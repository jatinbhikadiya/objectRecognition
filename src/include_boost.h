/*
 * include_boost.h
 *
 *  Created on: Feb 8, 2013
 *      Author: bhikadiy
 */

#ifndef INCLUDE_BOOST_H_
#define INCLUDE_BOOST_H_
#define BOOST_FILESYSTEM_NO_DEPRECATED
#define BOOST_FILESYSTEM_VERSION 3
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
namespace fs = boost::filesystem;

#endif /* INCLUDE_BOOST_H_ */
