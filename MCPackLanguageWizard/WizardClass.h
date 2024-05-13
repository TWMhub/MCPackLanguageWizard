#ifndef WIZARDCLASS_H
#define WIZARDCLASS_H

namespace depozit_wizard {
	class Wizard {
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

		//write strings to file (modpack or working files)
		void build(unsigned short);

	private:
		//methods
		bool isDir(fs::path);

		//methods with project
		void initProject(fs::path, unsigned short);//if you already have a project with input, output, wf folders, then do not call the function
		bool hasProject(std::string);

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

		//vars
		std::vector<compiledFile> arrayCompiledFiles;
		bool isEmpty;
		int counterParams;
		std::string nameProject;
	};
}

#endif // !WIZARDCLASS_H

