#include <string>
#include <iostream>
#include "Poco/ClassLoader.h"

using namespace std;
using Poco::ClassLoader;
using Poco::Manifest;

class Mutable
{
public:
	Mutable();
	~Mutable();

	const string& foo() const {
		if (name.empty()) {
			name = "Mutable";
		}
		return name;
	}
private:
	mutable string name;
};

Mutable::Mutable()
{
}

Mutable::~Mutable()
{
}
typedef ClassLoader<Mutable>	MutableLoader;

int main(int argc, char* argv) {
	MutableLoader	mutableLoader;

	mutableLoader.loadLibrary("foo");

	Mutable m;

	cout << m.foo() << endl;

	cout << "__cplusplus=" << __cplusplus << endl;

	return 0;
}