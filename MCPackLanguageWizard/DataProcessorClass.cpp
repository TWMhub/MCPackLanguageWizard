#include "McWizard.h"

namespace depozit_wizard {

	bool DataProcessor::isDir(fs::path path) {
		return fs::is_directory(path);
	}

	std::vector<std::wstring> DataProcessor::getFile(fs::path path) {
		std::wifstream input(path);
		std::vector<std::wstring> out;
		std::wstring line;
		while (std::getline(input, line)) {
			out.push_back(line);
		}
		return out;
	}

	compiledFile DataProcessor::parseFtbQuestFile(fs::path path) {
		return this->parseFtbQuestFile(this->getFile(path), path);
	}

	compiledFile DataProcessor::parseFtbQuestFile(std::vector<std::wstring> input, fs::path path) {

		compiledFile out;
		out.target = TargetInit::ftbQuests;
		out.pathToFile = path;

		int iterator = 0;
		size_t startBorder;
		size_t endBorder;

		for (int i = 0; i < input.size(); i++) {
			if (input[i].find(L"quests") != std::wstring::npos) {
				iterator = i + 1;
				break;
			}
		}

		for (iterator; iterator < input.size(); iterator++) {

			if (input[iterator].find(L"title") != std::wstring::npos || input[iterator].find(L"subtitle") != std::wstring::npos) {
				if (input[iterator].find(L"{") != std::wstring::npos) {

					startBorder = input[iterator].find_first_of(L"\"");
					endBorder = input[iterator].find_last_of(L"\"");
					if (startBorder != std::wstring::npos && endBorder != std::wstring::npos)
						out.compiledTextLines.push_back(TextLine{ iterator,
							input[iterator].substr(startBorder + 1,endBorder - startBorder - 1) });

				}
			}

			if (input[iterator].find(L"description") != std::wstring::npos) {
				for (int d = iterator; d < input.size(); d++) {
					if (input[d].find(L"\"") != std::wstring::npos) {
						startBorder = input[d].find_first_of(L"\"");
						endBorder = input[d].find_last_of(L"\"");
						if (startBorder != std::wstring::npos && endBorder != std::wstring::npos)
							out.compiledTextLines.push_back(TextLine{ d,
								input[d].substr(startBorder + 1,endBorder - startBorder - 1) });
					}
					if (input[d].find(L"]") != std::wstring::npos) {
						iterator = d;
						break;
					}
				}
			}

		}

		return out;
	}

	std::vector<fs::path> DataProcessor::getTranslatableKubeJsFiles(fs::path path) {
		std::vector<fs::path> out;
		path += "\\kubejs\\assets";
		for (const auto& dir : fs::recursive_directory_iterator(path)) {
			if (isDir(fs::path(dir) / "lang") && fs::exists(fs::path(dir) / "lang\\en_us.json")) {
				out.push_back(fs::path(dir) / "lang\\en_us.json");
			}
		}
		return out;
	}

	compiledFile DataProcessor::parseKubeJsFile(std::vector<std::wstring> input, fs::path path) {

		compiledFile out;
		out.target = TargetInit::kubeJS;
		out.pathToFile = path;

		size_t startBorder;
		size_t endBorder;

		for (int i = 0; i < input.size(); i++) {
			if (input[i].find(L"\"") != std::wstring::npos) {

				startBorder = input[i].find(L"\"", input[i].find(L":"));
				endBorder = input[i].find_last_of(L"\"");

				out.compiledTextLines.push_back(TextLine{ i,input[i].substr(startBorder + 1,startBorder - endBorder - 1) });
			}
		}

		return out;
	}
}