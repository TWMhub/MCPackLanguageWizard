#include "McWizard.h"

namespace depozit_wizard {

	//create class
	TextLine::TextLine() {
		initEmptyClass();
	}

	TextLine::TextLine(int pos, const std::wstring& origLine) {
		this->posInFile = pos;
		this->origLine = origLine;
		this->localeLine = L"";
		this->isEmpty = false;
	};

	TextLine::TextLine(int pos, const std::wstring& origLine, const std::wstring& localeLine) {
		this->posInFile = pos;
		this->origLine = origLine;
		this->localeLine = localeLine;
		this->isEmpty = false;
	};

	//init class
	void TextLine::init(int pos, const std::wstring& origLine) {
		this->posInFile = pos;
		this->origLine = origLine;
		this->localeLine = L"";
		this->isEmpty = false;
	};

	void TextLine::init(int pos, const std::wstring& origLine, const std::wstring& localeLine) {
		this->posInFile = pos;
		this->origLine = origLine;
		this->localeLine = localeLine;
		this->isEmpty = false;
	};


	//add locale lines
	void TextLine::addLocaleLine(const std::wstring& localeLine) {
		this->localeLine = localeLine;
	}

	//get info from class
	int TextLine::getPos() {
		return this->posInFile;
	}

	std::wstring TextLine::getOrigLine() {
		return this->origLine;
	}

	std::wstring TextLine::getLocaleLine() {
		return this->localeLine;
	}

	std::wstring TextLine::analysisErrors() {
		
		if (!(!isEmpty && localeLine.length() > 0)) 
			return L"";
		
		std::wstring buffer = L"";

		for (int i = 0; i < origLine.length() - 1; i++) {
			if (origLine[i] == L'&') {
				buffer.push_back(origLine[i + 1]);
			}
		}

		if (buffer.length() == 0) {
			return L"no errors found";
		}

		std::wstring out = L"";
		std::wstring twoWchars = L"";
		for (int i = 0; i < buffer.length(); i++) {

			twoWchars.clear();
			twoWchars.push_back(L'&');
			twoWchars.push_back(buffer[i]); 

			if (localeLine.find(twoWchars) == std::wstring::npos)
				out += L" " + twoWchars;
		}

		if (out.length() == 0) {
			return L"no errors found";
		}
		else {
			return out;
		}
		
	}

	//clear class
	void TextLine::clear() {
		initEmptyClass();
	}

	void TextLine::initEmptyClass() {
		this->posInFile = -1;
		this->origLine = L"";
		this->localeLine = L"";
		this->isEmpty = true;
	}

}
