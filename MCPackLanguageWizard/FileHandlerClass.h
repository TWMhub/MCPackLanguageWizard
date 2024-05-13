#ifndef FILEHANDLERCLASS_H
#define FILEHANDLERCLASS_H

namespace depozit_wizard {

	class FileHandler {
	protected:
		//json settings project
		void initJson(unsigned short); //initialise the project settings base file with all input data
		void addJsonData(unsigned short); //adds flags to the project
		std::vector<std::wstring> getJsonData(); //retrieves json data //I don't know the best way to get specific things yet
	};

}

#endif // !FILEHANDLERCLASS
