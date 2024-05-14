#ifndef TEXTLINECLASS_H
#define TEXTLINECLASS_H
#include "McWizard.h"

namespace depozit_wizard {

	class TextLine {
	public:
		//create class
		TextLine();
		TextLine(int, const std::wstring&);
		TextLine(int, const std::wstring&, const std::wstring&);

		//init class
		void init(int, const std::wstring&);
		void init(int, const std::wstring&, const std::wstring&);

		//add locale lines
		void addLocaleLine(const std::wstring&);

		//get info from class
		int getPos();
		std::wstring getOrigLine();
		std::wstring getLocaleLine();

		//search for a suspected error
		std::wstring analysisErrors();

		//clear class
		void clear();
	private:
		//methods
		void initEmptyClass();

		//vars
		int posInFile;
		std::wstring origLine;
		std::wstring localeLine;
		bool isEmpty;
	};
}

#endif // !TEXTLINECLASS_H
