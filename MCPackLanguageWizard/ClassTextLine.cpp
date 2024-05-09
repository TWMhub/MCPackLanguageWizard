#include "McWizard.h"

namespace depozit {

	//create class
	TextLine::TextLine() {
		initEmptyClass();
	}

	TextLine::TextLine(int pos, Type type, const std::wstring& origLine) {
		this->posInFile = pos;
		this->type = type;
		this->origLine = origLine;
		this->localeLine = L"";
		this->isEmpty = false;
	};

	TextLine::TextLine(int pos, Type type, const std::wstring& origLine, const std::wstring& localeLine) {
		this->posInFile = pos;
		this->type = type;
		this->origLine = origLine;
		this->localeLine = localeLine;
		this->isEmpty = false;
	};

	//init class
	void TextLine::init(int pos, Type type, const std::wstring& origLine) {
		this->posInFile = pos;
		this->type = type;
		this->origLine = origLine;
		this->localeLine = L"";
		this->isEmpty = false;
	};

	void TextLine::init(int pos, Type type, const std::wstring& origLine, const std::wstring& localeLine) {
		this->posInFile = pos;
		this->type = type;
		this->origLine = origLine;
		this->localeLine = localeLine;
		this->isEmpty = false;
	};

	//get info from class
	int TextLine::getPos() {
		return this->posInFile;
	}

	Type TextLine::getType() {
		return this->type;
	}

	std::wstring TextLine::getOrigLine() {
		return this->origLine;
	}

	std::wstring TextLine::getLocaleLine() {
		return this->localeLine;
	}

	std::wstring TextLine::getFullLine() {
		return std::to_wstring(this->posInFile) + L"\n" + typeToWstring(this->type) + L"\n" + this->origLine + L"\n" + this->localeLine;
	}

	std::vector<std::wstring> TextLine::getFullLineByVec() {
		std::vector<std::wstring> out;
		out.push_back(std::to_wstring(this->posInFile));
		out.push_back(typeToWstring(this->type));
		out.push_back(this->origLine);
		out.push_back(this->localeLine);
		return out;
	}

	void TextLine::getParamsByLink(int& pos, Type& type, std::wstring& origLine) {
		pos = this->posInFile;
		type = this->type;
		origLine = this->origLine;
	}

	void TextLine::getParamsByLink(int& pos, Type& type, std::wstring& origLine, std::wstring& localeLine) {
		pos = this->posInFile;
		type = this->type;
		origLine = this->origLine;
		localeLine = this->localeLine;
	}

	//clear class
	void TextLine::clear() {
		initEmptyClass();
	}

	void TextLine::initEmptyClass() {
		this->posInFile = -1;
		this->type = Type::unknown;
		this->origLine = L"";
		this->localeLine = L"";
		this->isEmpty = true;
	}

}