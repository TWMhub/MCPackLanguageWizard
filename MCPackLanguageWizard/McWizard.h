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

	enum class Flags {
		ftbQuests, //FTB Quests in config/ftbquests
		kubeJS, //all texts links
		modWLoc, //files en_en.json for example & advancements
		modWoLoc, //the same as modWLoc, but in datapacks
		unknown //if the flag could not be determined
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


	class Wizard {
	public:
		//create class
		Wizard();
		Wizard(const fs::path&, const Flags&);

		//init class
		void init(const fs::path&, const Flags&);

		//

		
	private:
		//methods

		//vars
		std::vector<std::vector<TextLine>> textLineVec;
		std::wstring completeFile;
		fs::path targetDir;
	};
}

// mods
// kubejs\assets
// config\ftbquests\quests