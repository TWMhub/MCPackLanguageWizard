#ifndef WIZARDCLASS_H
#define WIZARDCLASS_H
#include "McWizard.h"
#include "CompiledFileStruct.h"
#include "DataProcessorClass.h"
#include "TargetInitEnum.h"

namespace depozit_wizard {

	class Wizard : private DataProcessor{
	public:
		//create class
		Wizard();
		Wizard(std::vector<std::string>, fs::path, unsigned short);

		//init class
		/*this method is for 1 file,
		but you can add std::vector < std::vector<std::vector<std::wstring>> 
		to process a bunch of files at once, and even in multithreading.*/
		void init(std::vector<std::string>, fs::path, unsigned short); 

		//clear class
		void clear();

		std::vector<compiledFile> getAllFilesData();

		//write strings to file (modpack or working files)
		void build(unsigned short);

	private:
		//methods

		void addFtbQuestData(std::vector<std::wstring>); //parse all data from ftb quest files
		void addKubeJsData(std::vector<std::wstring>); //parse all data from kube js files
		void addModsData(std::vector<std::wstring>); //parse all data from mods files

		//vars
		std::vector<compiledFile> arrayCompiledFiles;
		bool isEmpty;
	};
}

#endif // !WIZARDCLASS_H
