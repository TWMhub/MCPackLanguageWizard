#ifndef TYPEENUM_H
#define TYPEENUM_H

namespace depozit {
	
	enum class Type {	//flags to FTBQuests
		title,			//title in quests
		subtitle,		//subtitle in quest
		description,	//desc in quest, it can contain several lines
		unknown			//if the flag could not be determined
	};
}

#endif // !TYPEENUM_H