#ifndef WIZARDCLASS_H
#define WIZARDCLASS_H
#include "McWizard.h"
#include "CompiledFileStruct.h"
#include "TargetInitEnum.h"

namespace depozit_wizard {

	class Wizard{
	public:
		//create class
		/*  ----
		this method is for 1 file,
		but you can add std::vector < std::vector<std::vector<std::wstring>>
		to process a bunch of files at once, and even in multithreading.
		----  */
		Wizard();
		Wizard(std::vector<std::wstring>, TargetInit::TargetInit, fs::path = "");

		//init class
		void init(std::vector<std::wstring>, TargetInit::TargetInit, fs::path = "");

		//clear class
		void clear();

		std::vector<compiledFile> getAllFilesData();
	private:
		//methods

		void FtbQuestDataParse(std::vector<std::wstring>, fs::path = ""); //parse all data from ftb quest files
		void KubeJsDataParse(std::vector<std::wstring>, fs::path = ""); //parse all data from kube js files
		void ModsDataParse(std::vector<std::wstring>, fs::path = ""); //parse all data from mods files

		bool chekUniquePos(const size_t&, const size_t&, const size_t&, const size_t&);

		//vars
		std::vector<compiledFile> arrayCompiledFiles;
	};
}

#endif // !WIZARDCLASS_H
