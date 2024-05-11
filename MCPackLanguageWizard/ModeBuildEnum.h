#ifndef MODEBUILDENUM_H
#define MODEBUILDENUM_H

namespace depozit {
	namespace ModeBuildEnum {
		enum {
			toFile = 1 << 0,	//
			fromFile = 1 << 1,	//
			unknown = 1 << 2	//if the flag could not be determined
		};
	}
}

#endif // !MCWIZARD_H