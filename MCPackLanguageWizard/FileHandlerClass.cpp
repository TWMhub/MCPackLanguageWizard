#include "FileHandlerClass.h"

namespace depozit_wizard {

	bool FileHandler::isCorrectPath(fs::path validatedPath, bool isFile) {
		bool validPath = fs::exists(validatedPath);
		if (((fs::is_directory(validatedPath) && !isFile) || (!fs::is_directory(validatedPath) && isFile)) && validPath) {
			return true;
		}
		else {
			return false;
		}
	}

	std::vector<std::wstring> FileHandler::readFile(fs::path path) {

		std::vector<std::wstring> out;

		if (!isCorrectPath(path, true))
			return out;

		std::wstring line;

		std::wifstream input(path);
		if (input.is_open()) {
			while (std::getline(input, line)) {
				out.push_back(line);
			}
		}

		return out;
	}

	std::vector<std::vector<std::wstring>> FileHandler::readDir(fs::path path) {
		std::vector<std::vector<std::wstring>> out;
		if (!isCorrectPath(path, false))
			return out;

		for (const auto& entry : fs::recursive_directory_iterator(path)) {
			out.push_back(readFile(entry));
		}
		return out;

	}

	void FileHandler::writeFile(const std::vector<std::wstring>& out, fs::path path) {

		std::wofstream file(path, std::ios::out);
		for (const auto& line : out) {
			file << line + L"\n";
		}
		file.close();
	}

	/*void FileHandler::writeFile(const std::vector<compiledFile>& out, fs::path path) {
		std::vector<std::wstring> outByWstring;
		for (const auto& comp : out) {
			outByWstring.push_back(comp.pathToFile);
			for (const auto& line : comp.compiledTextLines) {
				line
			}
		}
	}*/
}