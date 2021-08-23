#ifndef MAGICBOX
#define MAGICBOX

#include <random>
#include <set>

class MagicBox {
private:
	std::set<unsigned long long> idBox_{};
public:
	auto getIdBoxSize() const -> std::size_t {
		return idBox_.size();
	}

	auto drawId() -> unsigned long long ;
};

#endif
