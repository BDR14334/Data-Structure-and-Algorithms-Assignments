#include "StackError.h"

StackError::StackError(const string& message)
{
    errMessage = message;
}

string StackError::getMessage() const
{
    return errMessage;
}

void StackError::setMessage(const string& message)
{
    errMessage = message;
}
