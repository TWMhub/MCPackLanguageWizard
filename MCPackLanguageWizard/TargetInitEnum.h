#ifndef TARGETINITENUM_H
#define TARGETINITENUM_H

namespace depozit_wizard {
	namespace TargetInit {
		enum {
			ftbQuests = 1 << 0,	//FTB Quests in config/ftbquests
			kubeJS = 1 << 1,	//all texts links
			modWLoc = 1 << 2,	//files en_en.json for example & advancements
			modWoLoc = 1 << 3,	//the same as modWLoc, but in datapacks
			allTarget = ftbQuests | kubeJS | modWLoc | modWLoc //if the flag could not be determined
		};

		static const std::map<int, std::string> enumToStringMap = {
			{TargetInit::ftbQuests, "ftbQuests"},
			{TargetInit::kubeJS, "kubeJS"},
			{TargetInit::modWLoc, "modWLoc"},
			{TargetInit::modWoLoc, "modWoLoc"},
			{TargetInit::allTarget, "allTarget"}
		};
	}
}

#endif // !TARGETINITENUM_H