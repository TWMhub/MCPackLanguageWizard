#ifndef MODEBUILDENUM_H
#define MODEBUILDENUM_H

namespace depozit {
	namespace ModeBuildEnum {
		enum {
			toFile = 1 << 0,
			fromFile = 1 << 1,
			unknown = 1 << 2
		};
	}
}

#endif // !MCWIZARD_H