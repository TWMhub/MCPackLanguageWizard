#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

namespace depozit_wizard {

	class DataProcessor {
	protected:
		bool isDir(fs::path); //check if it is a directory
		//parsing methods
		std::vector<std::wstring> getFile(fs::path);
		//ftb quest methods
		std::vector<compiledFile> parseFtbQuestFile(std::vector<std::wstring>);
		//kubejs methods
		std::vector<fs::path> getTranslatableKubeJsFiles(fs::path);
		std::vector<compiledFile> parseKubeJsFile(std::vector<std::wstring>);
		//mod 
		bool isTranslatableMod(fs::path);
		std::vector<fs::path> getTranslatableMods(fs::path);
		std::vector<compiledFile> parseModFile(std::vector<std::wstring>);

	};
}

#endif // !DATAPROCESSORCLASS
