#ifndef TARGETINITENUM_H
#define TARGETINITENUM_H

namespace depozit{
	namespace TargetInit {
		enum {
			ftbQuests = 1 << 0,	//FTB Quests in config/ftbquests
			kubeJS = 1 << 1,	//all texts links
			modWLoc = 1 << 2,	//files en_en.json for example & advancements
			modWoLoc = 1 << 3,	//the same as modWLoc, but in datapacks
			unknown = 1 << 4	//if the flag could not be determined
		};
	}
}

#endif // !TARGETINITENUM_H