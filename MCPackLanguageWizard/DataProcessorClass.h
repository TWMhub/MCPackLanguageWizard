#ifndef DATAPROCESSORCLASS_H
#define DATAPROCESSORCLASS_H
#include "WizardClass.h"

namespace depozit_wizard {

	class DataProcessor {
	protected:
		bool isDir(fs::path); //check if it is a directory

		//parsing methods
		std::vector<std::wstring> getFileByVecWstring(fs::path);
		std::wstring getFileByWstring(fs::path);

		//ftb quest methods
		compiledFile parseFtbQuestFile(fs::path);
		compiledFile parseFtbQuestFile(std::vector<std::wstring>, fs::path);

		//kubejs methods
		std::vector<fs::path> getTranslatableKubeJsFiles(fs::path); //path to modpack
		compiledFile parseKubeJsFile(std::vector<std::wstring>, fs::path);

		//mod 
		bool isTranslatableMod(zip_t*, const std::string& parent_folder = "");
		std::vector<fs::path> getTranslatableMods(fs::path);
		std::vector<compiledFile> parseModFile(std::vector<std::wstring>);

		std::vector<compiledFile> getWorkingFiles(fs::path);

	};
}

#endif // !DATAPROCESSORCLASS
