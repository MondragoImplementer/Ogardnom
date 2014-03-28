#ifndef TESTHELPER_H_
#define TESTHELPER_H_

#include <string>

class TestHelper {
public:
	TestHelper();
	virtual ~TestHelper();

	static bool FileExists(const std::string& name);
};

#endif /* TESTHELPER_H_ */
