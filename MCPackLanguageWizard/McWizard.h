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
		std::wstring OricLine;
		std::wstring LocaleLine;
		bool isEmpty;
	};
}
