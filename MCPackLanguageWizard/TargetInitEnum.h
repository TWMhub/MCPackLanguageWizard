#ifndef TARGETINITENUM_H
#define TARGETINITENUM_H

namespace depozit_wizard {
	namespace TargetInit {
		enum TargetInit {
			ftbQuests = 1 << 0,	//FTB Quests in config/ftbquests
			kubeJS = 1 << 1,	//all texts links
			//allTarget = ftbQuests | kubeJS //if the flag could not be determined
		};

		static const std::map<int, std::string> enumToStringMap = {
			{TargetInit::ftbQuests, "ftbQuests"},
			{TargetInit::kubeJS, "kubeJS"},
			//{TargetInit::allTarget, "allTarget"}
		};
	}
}

#endif // !TARGETINITENUM_H