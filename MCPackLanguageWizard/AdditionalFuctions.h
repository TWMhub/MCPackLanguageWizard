#ifndef ADDITIONALFUNCTIONS_H
#define ADDITIONALFUNCTIONS_H
#include "McWizard.h"

namespace depozit_wizard {
	//lib info
	std::string getLibInfo();
	void printLibInfo();

	//helpful methods
	std::wstring strToWstr(const std::string&);
	std::string wstrToStr(const std::wstring&);
	std::wstring typeToWstring(const Type&);

	
}

#endif // !ADDITIONALFUNCTIONS_H

