#include "ProjectIOClass.h"

namespace depozit_wizard {

	void ProjectIO::initProject(std::string projectName, fs::path sourceDir, fs::path path—reation) {
		this->projectName = projectName;
		this->sourcePath = sourceDir;
		this->projectPath = path—reation;

		fs::create_directory(path—reation / projectName);
		fs::create_directory(path—reation / projectName / "input");
		fs::create_directory(path—reation / projectName / "output");

		fs::copy(sourceDir / "kubejs", path—reation / projectName / "input");
		fs::copy(sourceDir / "config", path—reation / projectName / "input");
	}

	void ProjectIO::deleteProject() {
		fs::remove_all(projectPath / projectName);
	}

}