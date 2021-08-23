#ifndef MAGICBOX
#define MAGICBOX

#include <limits>
#include <random>
#include <set>

class MagicBox {
private:
	std::set<unsigned long long> idBox_{};
public:
	std::size_t getIdBoxSize() const {
		return idBox_.size();
	}

	std::size_t drawId() {
		unsigned long long minId {1};
		unsigned long long maxId {ULLONG_MAX};
		std::random_device rd;
		std::uniform_int_distribution<unsigned long long> dist (minId, maxId);
		bool isUnique{false};
		unsigned drawedValue{0};
		while(!isUnique){
			auto insertedIt = idBox_.insert(dist(rd));
			if(insertedIt.second == true) {
				isUnique = true;
				drawedValue = *insertedIt.first;
			}
		}
		return drawedValue;
	}
};

#endif
