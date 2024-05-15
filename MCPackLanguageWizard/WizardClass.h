#ifndef WIZARDCLASS_H
#define WIZARDCLASS_H
#include "McWizard.h"

namespace depozit_wizard {

	class Wizard : private DataProcessor, private FileHandler {
	public:
		//create class
		Wizard();
		Wizard(std::string, fs::path, unsigned short);
		Wizard(std::string, unsigned short);
		Wizard(std::string);


		//init class
		void init(std::string, fs::path, unsigned short);
		void init(std::string, unsigned short);
		void init(std::string);

		//methods with flags
		unsigned short getTargetFlags();
		void printTargetFlags();
		void addTargetFlags(unsigned int);
		void removeTargetFlags(unsigned int);


		//clear class
		void clear();

		std::vector<compiledFile> getAllFilesData();
		std::string getNameProject();

		//write strings to file (modpack or working files)
		void build(unsigned short);

	private:
		//methods
		
		//methods with project
		void initWorkingProject(fs::path, unsigned short); //initialises the project in the folder with the program for further work
		bool hasProject(std::string); //checks if a project with this name exists


		void addFtbQuestData(fs::path); //reads all data from ftb quest files
		void addKubeJsData(fs::path); //reads all data from kube js files
		void addModsData(fs::path); //reads all data from mods files
		void getDataFromWorkingFiles();

		
		//vars
		std::vector<compiledFile> arrayCompiledFiles;
		bool isEmpty;
		int counterParams;
		std::string nameProject;

	};
}

#endif // !WIZARDCLASS_H
