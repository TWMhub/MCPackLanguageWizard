#include "TextLineClass.h"

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

	std::vector<std::wstring> TextLine::analysisErrors() {

		std::vector<std::wstring> outData;
		
		if (!(!isEmpty || localeLine.length() > 0)) //check if strings can be checked at all
			return outData;

		for (int i = 0; i < origLine.length() - 1; i++) { //search for all special characters in the original string
			if (this->origLine.substr(i,1) == L"&") {
				outData.push_back(std::wstring{ L"&" + origLine[i + 1] });
			}
		}

		if (outData.size() == 0) //if there are no special characters at all
			return outData;
		
		for (int i = 0; i < localeLine.length() - 1; i++) { //the strings are checked and the missing characters are found
			if (localeLine[i] == L'&' && std::find(outData.begin(), outData.end(), std::wstring{ localeLine[i] } + std::wstring{ localeLine[i + 1] }) != outData.end()) {
				outData.erase(std::remove(outData.begin(), outData.end(), std::wstring{ localeLine[i] } + std::wstring{ localeLine[i + 1] }), outData.end());
			}
		}

		return outData;
		
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
