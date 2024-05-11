#ifndef ADDITIONALFUNCTIONS_H
#define ADDITIONALFUNCTIONS_H

namespace depozit {
	//lib info
	std::string getLibInfo();
	void coutLibInfo();

	//helpful methods
	std::wstring strToWstr(const std::string&);
	std::string wstrToStr(const std::wstring&);
	std::wstring typeToWstring(const Type&);
}

#endif // !ADDITIONALFUNCTIONS_H
