/*
 * TestHelper.cpp
 *
 *  Created on: Mar 28, 2014
 *      Author: sul
 */

#include "TestHelper.h"
#include <sys/stat.h>

TestHelper::TestHelper() {
	// TODO Auto-generated constructor stub

}

TestHelper::~TestHelper() {
	// TODO Auto-generated destructor stub
}

bool TestHelper::FileExists(const std::string& name)
{
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}
