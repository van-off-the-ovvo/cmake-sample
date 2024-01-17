#include "InterpretLib/InterpretLib.h"


std::string InterpretLib::interpret_add(int a, int b)
{
	return std::to_string(a) + " + " + std::to_string(b) + " = ";
}