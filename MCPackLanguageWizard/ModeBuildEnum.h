#ifndef MODEBUILDENUM_H
#define MODEBUILDENUM_H

namespace depozit {
	namespace ModeBuildEnum {
		enum {
			toFile = 1 << 0,	// read modPack, parse it & write to working files
			fromFile = 1 << 1,	// read working files & replace orig line to translate in modPack
			unknown = 1 << 2	//if the flag could not be determined
		};
	}
}

#endif // !MCWIZARD_H