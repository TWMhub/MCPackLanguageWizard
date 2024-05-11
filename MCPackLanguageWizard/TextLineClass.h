#ifndef TEXTLINECLASS_H
#define TEXTLINECLASS_H


namespace depozit {

	class TextLine {
	public:
		//create class
		TextLine();
		TextLine(int, Type, const std::wstring&);
		TextLine(int, Type, const std::wstring&, const std::wstring&);

		//init class
		void init(int, Type, const std::wstring&);
		void init(int, Type, const std::wstring&, const std::wstring&);

		//add locale lines
		void addLocaleLine(const std::wstring&);

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

}

#endif // !TEXTLINECLASS_H
