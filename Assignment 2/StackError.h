#pragma once
#include <iostream>
#include <string>
#include "StackError.h"

using namespace std;

class StackError
{
public:
    StackError(const string& message);
    string getMessage() const;
    void setMessage(const string& message);

private:
    string errMessage;
};

