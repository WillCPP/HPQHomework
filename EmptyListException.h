#pragma once
#include <string>
using namespace std;
class EmptyListException
{
public:
	EmptyListException() {}
	~EmptyListException() {}


	string Message = "Could not remove node from list. List is empty.";
};