#include"QueueError.h"
using namespace std;

QueueError::QueueError(const string& error_message):domain_error(error_message.c_str()){}
