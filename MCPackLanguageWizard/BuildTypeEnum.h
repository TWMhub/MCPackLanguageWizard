#ifndef BUILDTYPEENUM_H
#define BUILDTYPEENUM_H

namespace depozit_wizard {
	namespace BuildType {
		enum {
			toModPack = 1 << 0,
			fromModModpack = 1 << 1
		};
	}
}

#endif // !BUILDTYPEENUM_H
