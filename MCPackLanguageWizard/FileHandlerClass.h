#ifndef FILEHANDLERCLASS_H
#define FILEHANDLERCLASS_H
#include "FileHadler.h"

namespace depozit_wizard {

	class FileHandler {
	public:
		//json
		void initJson(std::string, fs::path, unsigned short); //initialise the project settings base file with all input data
		void addJsonFlag(unsigned short); //adds flags to the project
		void removeJsonFlag(unsigned short);
		std::vector<std::wstring> getJsonData(); //retrieves json data //I don't know the best way to get specific things yet

		//YAML
		void writeYAMLFiles(const std::vector<compiledFile>&);
		std::vector<compiledFile> getYAMLFiles();

		//settings

		//working files
	};

}

#endif // !FILEHANDLERCLASS
