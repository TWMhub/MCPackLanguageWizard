/*--------------------------------------

	this section is entirely devoted to working with files
	all RECORDING methods work on the principle of complete overwriting, save the original files

	why a class and not a function?
	-because it is planned to extend the functionality to work with other file types (e.g. .jar)

--------------------------------------*/

#ifndef FILEHANDLERCLASS_H
#define FILEHANDLERCLASS_H
#include "FileHadler.h"
#include "CompiledFileStruct.h"

namespace depozit_wizard {

	//a set of methods for working with files packed into a class for convenience
	class FileHandler {
	public:

		//read&write files
		std::vector<std::wstring> readFile(fs::path);
		std::vector<std::vector<std::wstring>> readDir(fs::path);
		void writeFile(const std::vector<std::wstring>&, fs::path);
		//void writeFile(const std::vector<compiledFile>&, fs::path);

	private:
		bool isCorrectPath(fs::path, bool);
	};

}

#endif // !FILEHANDLERCLASS
