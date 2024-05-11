#ifndef COMPILEDFILESTRUCT_H
#define COMPILEDFILESTRUCT_H

namespace depozit {
	struct compiledFile {
		fs::path pathToFile;						//in project (input)
		int target;									//it is necessary to write to a specific file
		std::vector<TextLine> compiledTextLines;	//orig loc lines
	};
}

#endif // !COMPILEDFILESTRUCT_H

