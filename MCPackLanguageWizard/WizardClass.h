#ifndef WIZARDCLASS_H
#define WIZARDCLASS_H

namespace depozit_wizard {
	class Wizard {
	public:
		//create class
		Wizard();
		Wizard(std::string, fs::path, int, bool);

		//init class
		void init(std::string, fs::path, int, bool);

		//clear class
		void clear();
	private:
		//methods
		bool isDir(fs::path);
		void initProject(fs::path, int);//if you already have a project with input, output, wf folders, then do not call the function

		//vars
		std::vector<compiledFile> arrayCompiledFiles;
		bool isEmpty;
		int counterParams;
		std::string nameProject;
	};
}

#endif // !WIZARDCLASS_H
