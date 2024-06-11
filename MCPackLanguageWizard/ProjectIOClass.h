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
* 
* 
--------------------------------------------------------------------------*/

#ifndef PROJECTIOCLASS_H
#define PROJECTIOCLASS_H
#include "ProjectIO.h"
#include "FileHandlerClass.h"

namespace depozit_wizard {

	class ProjectIO {
	public:

		/*
		* this method accepts a directory with projects of the PolyFlow type,
		* and works only with it, if you need to read projects from another folder, 
		* create another instance of the class
		*/
		ProjectIO(fs::path projetctsDir);

		/*
		* creates a PolyFlow project folder with the specified name, 
		* and also generates standard files. 
		* To import data from modpack, use the "initProject" function
		*/
		void createProject(std::string nameProject);

		/*
		* initializes the specified project based on data from the specified modpack
		* the path should point to the "minecraft" folder or, in the case of sourceforge, the name of the modpack.
		* function checks for the presence of mods and config folders (in my experience these folders are always in modpacks.)
		* to avoid errors I advise to use the function getExistringProjects more often.
		*/
		void initProject(std::string nameProject, fs::path pathToModpack);

		/*
		* returns a vector of all existing projects in the folder
		* easy to use so that you don't get the name of the project wrong
		*/
		std::vector<std::string> getExistringProjects();

		/*
		* returns the read .pf project file, 
		* if the project is not initialized, it will return an empty vector
		*/
		std::vector<std::wstring> getTranslationFile(std::string nameProject);

		/*
		* writes the updated translation file to the specified project
		* if the project is not initialized, it will return an empty vector
		*/
		void setTranslationFile(std::string nameProject, std::vector<std::wstring>);

		/*
		* replaces the original lines with translated ones, and returns the original files but translated ones to the out folder.
		*/
		void configureTranslate(std::string nameProject);

	private:
		fs::path projectsDir;
		std::vector<std::string> existingProjects;
	};

}

#endif // !PROJECTIOCLASS_H
