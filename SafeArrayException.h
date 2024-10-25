#pragma once
#include <iostream>
#include <string>
#include "SafeArrayException.h"

using namespace std; 


class SafeArrayException
{
public:
    SafeArrayException(const string& message);
    string getMessage() const;
    void setMessage(const string& message);

private:
    string errMessage;
};

