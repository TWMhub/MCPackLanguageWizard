/*--------------------------------------------------------------------------
* 
* this module is intended for grouping, storing and accessing all project files
* 
* module works with FileHandler module support (you do not need to import it separately)
* Since the library is written for extremely correct tasks, the author's vision of information structuring is used
* 
* Instead of long attempts to understand the functionality of the library and adjustments to suit yourself,
* I recommend to use the graphical application PolyFlow
* 
--------------------------------------------------------------------------*/

#ifndef PROJECTIOCLASS_H
#define PROJECTIOCLASS_H
#include "ProjectIO.h"
#include "FileHandlerClass.h"

namespace depozit_wizard {

	class ProjectIO {
	public:
		void initProject(std::string projectName, fs::path sourceDir, fs::path path—reation);
		void deleteProject();

		std::vector<std::pair<fs::path,std::vector<std::wstring>>> getOrigFiles();
		std::vector<std::wstring> getProjectFile();

		void setProjectFile(std::vector<std::wstring> data);

		//file translation replacement
		void configureOut();

	private:
		std::vector<std::wstring> projectFile;
		std::string projectName;
		fs::path projectPath;
		fs::path sourcePath;
	};

}

#endif // !PROJECTIOCLASS_H
