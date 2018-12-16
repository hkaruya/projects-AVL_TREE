#include"NodeError.h"
using namespace std;

NodeError::NodeError(const string& error_message):domain_error(error_message.c_str()){}
