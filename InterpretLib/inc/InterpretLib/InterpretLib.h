#pragma once

#if defined(_WIN32)
#  if defined(EXPORTING_INTERPRETLIB)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // non windows
#  define DECLSPEC
#endif


#include <string>

namespace InterpretLib {
	std::string DECLSPEC interpret_add(int a, int b);
}