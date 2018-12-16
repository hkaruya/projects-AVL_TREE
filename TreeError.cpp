#include "TreeError.h"
using namespace std;

TreeError::TreeError(const string& error_message):runtime_error(error_message.c_str()){}
