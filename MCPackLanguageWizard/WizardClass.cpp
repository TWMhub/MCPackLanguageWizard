#include "WizardClass.h"

namespace depozit_wizard {
	//public
	Wizard::Wizard() {
		this->clear();
	}

	Wizard::Wizard(std::vector<std::wstring> inputFile, TargetInit::TargetInit target, fs::path path= "") {
		this->init(inputFile, target, path);
	}

	void Wizard::init(std::vector<std::wstring> inputFile, TargetInit::TargetInit target, fs::path path = "") {

		if (target == TargetInit::ftbQuests) {
			this->FtbQuestDataParse(inputFile, path);
		}
		else if (target == TargetInit::kubeJS) {
			this->KubeJsDataParse(inputFile, path);
		}
		else {
			this->clear();
		}
	}

	void Wizard::clear() {
		arrayCompiledFiles.clear();
	}

	std::vector<compiledFile> Wizard::getAllFilesData() {
		return this->arrayCompiledFiles;
	}
	//private
	void Wizard::FtbQuestDataParse(std::vector<std::wstring> inputFile, fs::path path = "") {
		compiledFile file;
		file.pathToFile = path;
		file.target = TargetInit::ftbQuests;

		unsigned short iterator = 0; //is needed to determine the start of parsing
		size_t initialQuotation = 0;
		size_t endQuotation = 0;

		for (unsigned short i = 0; i < inputFile.size(); i++) {
			if(inputFile[i].find(L"quests") != std::wstring::npos){
				iterator = i;
				break;
			}
		}

		for (iterator; iterator < inputFile.size(); iterator++) {

			if (inputFile[iterator].find(L"title") != std::wstring::npos) {

				initialQuotation = 0;
				endQuotation = 0;

				initialQuotation = inputFile[iterator].find_first_of(L"\"") + 1;
				endQuotation = inputFile[iterator].find_last_of(L"\"") - inputFile[iterator].find_first_of(L"\"") - 1;

				file.compiledTextLines.push_back(TextLine{ iterator,
					inputFile[iterator].substr(initialQuotation, endQuotation)
					}
				);
			}

			if (inputFile[iterator].find(L"description") != std::wstring::npos) {
				for (unsigned short iterInDesc = iterator; iterInDesc < inputFile.size(); iterInDesc++) {

					initialQuotation = 0;
					endQuotation = 0;

					initialQuotation = inputFile[iterInDesc].find_first_of(L"\"") + 1;
					endQuotation = inputFile[iterInDesc].find_last_of(L"\"") - inputFile[iterator].find_first_of(L"\"") - 1;

					if (initialQuotation != endQuotation && initialQuotation != 0) {
						file.compiledTextLines.push_back(TextLine{ iterInDesc,
							inputFile[iterInDesc].substr(initialQuotation, endQuotation)
							}
						);
					}

					if (inputFile[iterInDesc].find(L"]") != std::wstring::npos) {
						iterator = iterInDesc;
						break;
					}

				}
			}
		}
		this->arrayCompiledFiles.push_back(file);
	}

	void Wizard::KubeJsDataParse(std::vector<std::wstring> inputFile, fs::path path = "") {
		compiledFile file;
		file.target = TargetInit::kubeJS;
		file.pathToFile = path;

		size_t quotation1 = 0;
		size_t quotation2 = 0;
		size_t quotation3 = 0;
		size_t quotation4 = 0;

		for (int i = 0; i < inputFile.size(); i++) {

			quotation1 = inputFile[i].find_first_of(L"\"");
			quotation2 = inputFile[i].find(L"\"", quotation1 + 1);
			quotation3 = inputFile[i].find(L"\"", quotation2 + 1);
			quotation4 = inputFile[i].find(L"\"", quotation3 + 1);

			if (chekUniquePos(quotation1, quotation2, quotation3, quotation4)) {
				file.compiledTextLines.push_back(TextLine{ i,inputFile[i].substr(quotation3 + 1,quotation4 - quotation3 - 1) });
			}
		}
		this->arrayCompiledFiles.push_back(file);
	}

	void Wizard::ModsDataParse(std::vector<std::wstring> inputFile, fs::path path = "") {
		compiledFile file;
		arrayCompiledFiles.push_back(file);
	}

	bool Wizard::chekUniquePos(const size_t& p1, const size_t& p2, const size_t& p3, const size_t& p4) {
		if (p1 != p2 && p2 != p3 && p3 != p4 && std::max(std::max(p1, p2), std::max(p3, p4)) != std::wstring::npos) {
			return true;
		}
		return false;
	}
	 
}