#pragma once
//standard libraries
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

//third-party libraries
#include "rapidjson/document.h"
#include "yaml-cpp/yaml.h"

namespace fs = std::filesystem;

namespace depozit {

	//lib info
	std::string getLibInfo();
	void coutLibInfo();

	//flags
	enum class Type { //flags to FTBQuests
		title,
		subtitle,
		description,
		unknown
	};



	//helpful methods
	std::wstring strToWstr(const std::string&);
	std::string wstrToStr(const std::wstring&);
	std::wstring typeToWstring(const Type&);

	class TextLine {
	public:
		//create class
		TextLine();
		TextLine(int, Type, const std::wstring&);
		TextLine(int, Type, const std::wstring&, const std::wstring&);

		//init class
		void init(int, Type, const std::wstring&);
		void init(int, Type, const std::wstring&, const std::wstring&);

		//get info from class
		int getPos();
		Type getType();
		std::wstring getOrigLine();
		std::wstring getLocaleLine();
		std::wstring getFullLine();
		std::vector<std::wstring> getFullLineByVec();
		void getParamsByLink(int&, Type&, std::wstring&);
		void getParamsByLink(int&, Type&, std::wstring&, std::wstring&);

		//clear class
		void clear();
	private:
		//methods
		void initEmptyClass();

		//vars
		int posInFile;
		Type type;
		std::wstring origLine;
		std::wstring localeLine;
		bool isEmpty;
	};

	enum class TargetInit {
		ftbQuests = 1 << 0, //FTB Quests in config/ftbquests
		kubeJS = 1 << 1, //all texts links
		modWLoc = 1 << 2, //files en_en.json for example & advancements
		modWoLoc = 1 << 3, //the same as modWLoc, but in datapacks
		unknown = 1 << 4//if the flag could not be determined
	};

	enum class modeBuild {
		toFile = 1 << 0,
		fromFile = 1 << 1,
		unknown = 1 << 2
	};

	struct compiledFile {
		fs::path pathToFile;//in project (input)
		TargetInit target;
		std::wstring nameOfFile;
		std::vector<std::wstring> fileByLine;
		std::vector<TextLine> compiledTextLines;
		std::wstring getFileByLine();
		void replaceLines();
	};

	class Wizard {
	public:
		//create class
		Wizard();
		Wizard(std::string, fs::path, TargetInit, bool);

		//init class
		void init(std::string, fs::path, TargetInit, bool);

		//clear class
		void clear();
	private:
		//methods
		bool isDir(fs::path);
		void initProject(fs::path, TargetInit);//if you already have a project with input, output, wf folders, then do not call the function

		void parseQuestDir();
		void parseKubeJsDir();
		void parseModWLocDir();
		void parseModWoLocDir();
		//vars
		fs::path projectPath;
		std::vector<compiledFile> arrayCompiledFiles;
		bool isEmpty;
		int counterParams;
		std::string nameProject;
	};

	//class Wizard {
	//public:
	//	//create class
	//	Wizard();
	//	Wizard(const fs::path&, const Flag&);

	//	//init class
	//	void init(const fs::path&, const Flag&);

	//	//build & read
	//	void buildToLocFile(); //build from raw files to translate file
	//	void buildToOrigFile(); //build from loc file to orig
	//	void read(const Flag&); //read loc file by flag

	//	//get data
	//	std::vector<std::vector<std::wstring>> getAllLines();
	//	std::vector<std::wstring> getLinesFile(int num = 0); 
	//	std::wstring getLines();
	//	Flag getFlag();

	//	//init working dir's
	//	void initFtbQuestProject(fs::path input, fs::path output);
	//	void initKubeJsProject(fs::path input, fs::path output);
	//	void initModsProject(fs::path input, fs::path output);

	//	//clear
	//	void clear();
	//private:
	//	//methods
	//	//inits by flag
	//	void initMods(const fs::path&);
	//	void initKubeJs(const fs::path&);
	//	void initQuest(const fs::path&);

	//	//read row file
	//	std::vector<std::wstring> readFileByPath(const fs::path&);

	//	//convert vector to wstring
	//	std::wstring convVecWstr(const std::wstring&);

	//	//get: mods, kubejs\assets, config\ftbquests\quests
	//	std::wstring getPathByFLag(const Flag&);

	//	//checking the path or file
	//	bool isPath(const fs::path&);

	//	//vars
	//	std::vector<std::vector<TextLine>> textLineVec;
	//	std::wstring completeFile;
	//	fs::path targetDir;
	//	Flag flag;
	//	bool isEmpty;
	//};
}

// mods
// kubejs\assets
// config\ftbquests\quests
//