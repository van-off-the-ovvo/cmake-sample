// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#include <MathLib/MathLib.h>
#include<InterpretLib/InterpretLib.h>

using namespace std;

int main()
{
	int a = 3, b = 5;
	cout << InterpretLib::interpret_add(a,b)<< MathLib::add_int(a,b)<< endl;
	return 0;
}
