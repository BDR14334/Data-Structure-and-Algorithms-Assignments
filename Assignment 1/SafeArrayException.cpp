#include "SafeArrayException.h"


SafeArrayException::SafeArrayException(const string& message)
{
    errMessage = message;
}

string SafeArrayException::getMessage() const
{
    return errMessage;
    // TODO: insert return statement here
}

void SafeArrayException::setMessage(const string& message)
{
    errMessage = message;
}
