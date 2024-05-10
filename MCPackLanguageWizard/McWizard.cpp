#include "McWizard.h"

namespace depozit {
	//lib info
	std::string getLibInfo() {
		return R"(
The MCPackLanguageWizard library is used.
it allows you to parse and work with all the texts in minecraft builds that you can translate
)";
	}
	void coutLibInfo() {
		std::cout<<R"(
The MCPackLanguageWizard library is used.
it allows you to parse and work with all the texts in minecraft builds that you can translate
)";
	};

	//helpful methods
	std::wstring strToWstr(const std::string& str) {
		return std::wstring(str.begin(), str.end());
	}

	std::string wstrToStr(const std::wstring& wstr) {
		return std::string(wstr.begin(), wstr.end());
	}

	std::wstring typeToWstring(const Type& type) {
		switch (type) {
		case Type::title:
			return L"title";
			break;
		case Type::subtitle:
			return L"subtitle";
			break;
		case Type::description:
			return L"description";
			break;
		default:
			return L"unknown";
		}
	}

	std::wstring compiledFile::getFileByLine() {
		std::wstring out;
		for (auto line : this->fileByLine) {
			out += line + L"\n";
		}
		return out;
	}

	void compiledFile::replaceLines() {
		for (auto arrayText : this->compiledTextLines) {
			if (fileByLine[arrayText.getPos()].find(arrayText.getOrigLine()) != std::wstring::npos) {
				fileByLine[arrayText.getPos()].replace(
					fileByLine[arrayText.getPos()].find(arrayText.getOrigLine()),
					arrayText.getOrigLine().length(),
					arrayText.getLocaleLine()
				);
			}
		}
	}

};