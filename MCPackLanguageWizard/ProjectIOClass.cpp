#include "ProjectIOClass.h"

namespace depozit_wizard {


	ProjectIO::ProjectIO(fs::path projetctsDir) {

		if (fs::exists(projetctsDir)) {

			this->projectsDir = projetctsDir;

			for (const auto entry : fs::directory_iterator(projetctsDir)) {
				if (fs::is_directory(entry)) {
					std::string path = entry.path().string();
					if (path.substr(path.length() - 3) == "-pf") {
						this->existingProjects.push_back(path.substr(path.length() - 3));
					}
				}
			}

		}
			
	}


	void ProjectIO::createProject(std::string nameProject) {

		for (int i = 0; i < this->existingProjects.size(); i++) {
			if (nameProject == this->existingProjects[i])
				return;
		}

		std::string projectId = nameProject + " -pf";

		fs::create_directory(this->projectsDir / projectId);
		fs::create_directories(this->projectsDir / projectId / "in");
		fs::create_directories(this->projectsDir / projectId / "out");
		std::ofstream(this->projectsDir / projectId / "translation file.pf").close();

		this->existingProjects.push_back(nameProject);

	}


	void ProjectIO::initProject(std::string nameProject, fs::path pathToModpack) {

		if (!fs::exists(this->projectsDir / (nameProject + " -pf")))
			return;

		if (!fs::exists(pathToModpack))
			return;

		if (!(fs::exists(pathToModpack / "config") && fs::exists(pathToModpack / "mods")))
			return;

		if (fs::exists(pathToModpack / "config/ftbquests/quests")) {

			std::vector<std::wstring> translatableStrings;

			FileHandler handler;
			Wizard wizard;
			//convert to yaml..
			for (const auto entry : fs::directory_iterator(pathToModpack / "config/ftbquests/quests/chapters")) {
				wizard.init(handler.readFile(entry), TargetInit::ftbQuests);
				auto dataWizard = wizard.getAllFilesData();
				for (const auto file : dataWizard) {
					translatableStrings.push_back(strToWstr(file.pathToFile.string()));
					for (auto lines : file.compiledTextLines) {
						translatableStrings.push_back(std::to_wstring(lines.getPos()));
						translatableStrings.push_back(lines.getOrigLine());
						translatableStrings.push_back(lines.getLocaleLine());
					}
				}
				wizard.clear();
			}
			

		}


	}

}