#include "McWizard.h"

namespace depozit_wizard {

	Wizard::Wizard() {
		clear();
	};

	Wizard::Wizard(std::string name, fs::path pathToModPack, unsigned short flag, bool needInitProject) {
		init(name, pathToModPack, flag, needInitProject);
	};

	//init class
	void Wizard::init(std::string name, fs::path pathToModPack, unsigned short flag, bool needInitProject) {
		//initial settings
		clear();

		if (!fs::exists(name)) {
			std::cout << "project doesnt exist\n";
			return;
		}

		if (!fs::exists(pathToModPack)) {
			std::cout << "modpack doesnt exist\n";
			return;
		}

		this->nameProject = name;

		//checking for the need to create a project
		if (needInitProject) {
			this->initProject(pathToModPack, TargetInit::unknown);
		}

		//checking flags
		if (flag & TargetInit::ftbQuests) {
			this->counterParams++;
			if (needInitProject)
				this->initProject(pathToModPack, TargetInit::ftbQuests);
			//parseQuestDir();
		}
		if (flag & TargetInit::kubeJS) {
			this->counterParams++;
			if (needInitProject)
				this->initProject(pathToModPack, TargetInit::kubeJS);
			//parseKubeJsDir();
		}
		if (flag & TargetInit::modWLoc) {
			this->counterParams++;
			if (needInitProject)
				this->initProject(pathToModPack, TargetInit::modWLoc);
			//parseModWLocDir();
		}
		if (flag & TargetInit::modWoLoc) {
			//parseModWoLocDir();
			this->counterParams++;
		}

		//checking for the correctness of the flags
		if (counterParams == 0) {
			this->isEmpty = true;
			std::cout << "0 parameters are entered, the class will be initialized as empty\n";
			return;
		}
		else {
			this->isEmpty = false;
			std::cout << counterParams << " parameters have been entered\n";
		}

	}

	//clear class
	void Wizard::clear() {
		this->nameProject.clear();
		this->arrayCompiledFiles.clear();
		this->isEmpty = true;
		this->counterParams = 0;
	}

	bool Wizard::isDir(fs::path targetPath) {
		return fs::is_directory(targetPath);
	}

	void Wizard::initProject(fs::path path, unsigned short flag = TargetInit::unknown) {
		fs::create_directories(nameProject + "\\input");
		fs::create_directories(nameProject + "\\wf");
		fs::create_directories(nameProject + "\\output");


		try {
			if (flag & TargetInit::ftbQuests)
				fs::copy(path / "\\config\\ftbquests\\quests", nameProject + "\\FTBQuests", fs::copy_options::overwrite_existing);

			if (flag & TargetInit::kubeJS)
				fs::copy(path / "\\kubejs\\assets", nameProject + "\\kubeJs", fs::copy_options::overwrite_existing);

			if (flag & TargetInit::modWLoc)
				fs::copy(path / "\\mods", nameProject + "\\mods", fs::copy_options::overwrite_existing);
		}
		catch (const fs::filesystem_error& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	

}