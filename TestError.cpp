#include "TestError.h"
using namespace std;

TestError::TestError(const string& error_message):runtime_error(error_message.c_str()){}
