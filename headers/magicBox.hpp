#ifndef MAGICBOX
#define MAGICBOX

#include <string>
#include <set>

class MagicBox {
private:
	std::set<std::string> idBox_{};
public:
	std::size_t getIdBoxSize() const {
		return idBox_.size();
	}
};

#endif
