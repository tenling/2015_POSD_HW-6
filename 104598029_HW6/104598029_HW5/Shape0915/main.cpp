#include "cppunitlite/TestHarness.h"
#include "utHW3.h"
using namespace std;
int main(int argc, char** argv) {
    TestResult tr;
	TestRegistry::runAllTests(tr);

	return 0;
}
