#ifndef WIZARDCLASS_H
#define WIZARDCLASS_H

namespace depozit_wizard {
	class Wizard :private DataProcessor {
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

// можно вынести за скобки: парсер для разных файлов