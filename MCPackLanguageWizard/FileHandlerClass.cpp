#include "McWizard.h"

namespace depozit_wizard {

	void FileHandler::initJson(std::string nameProject, fs::path pathToOriginalModPack, unsigned short flag) {

        //working with time
        //getting the current time
        time_t now = time(nullptr);
        struct tm localTime;
        localtime_s(&localTime, &now);
        
        //formatting the correct date
        std::string formatingTime = std::to_string(localTime.tm_year + 1900) + '-' +
            (localTime.tm_mon < 9 ?
                '0' + std::to_string(localTime.tm_mon + 1) : std::to_string(localTime.tm_mon + 1)) +
            '-' + (localTime.tm_wday < 10 ?
                '0' + std::to_string(localTime.tm_mday) : std::to_string(localTime.tm_mday));

        //working with Flags
        std::vector<std::string> stringFlags;
        for (int iFlag = TargetInit::ftbQuests; iFlag != TargetInit::modWoLoc; iFlag++) {
            if (flag & iFlag) {
                auto it = TargetInit::enumToStringMap.find(iFlag);
                if (it != TargetInit::enumToStringMap.end()) {
                    stringFlags.push_back(it->second);
                }
            }
        }

        //working with json
        //inits rapidjson elements
        rapidjson::Document doc;
        doc.SetObject();
        auto allocator = doc.GetAllocator();

        //add elements to doc
        doc.AddMember("project name", rapidjson::Value(nameProject.c_str(), allocator), allocator);
        doc.AddMember("project creation date", rapidjson::Value(formatingTime.c_str(), allocator), allocator);
        doc.AddMember("modpack path", rapidjson::Value(pathToOriginalModPack.string().c_str(), allocator), allocator);

        //add array to doc
        rapidjson::Value jsonFlags(rapidjson::kArrayType);
        for (const auto& vecFlag : stringFlags) {
            jsonFlags.PushBack(vecFlag, allocator);
        }

        doc.AddMember("flags", jsonFlags, allocator);
        
        //init buffer
        rapidjson::StringBuffer buffer;
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);

        //writing output file
        std::ofstream outFile(nameProject + "/prop.json");
        if (outFile.is_open()) {
            outFile << buffer.GetString();
            outFile.close();
        }
	}

}