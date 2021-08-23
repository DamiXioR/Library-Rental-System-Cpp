#ifndef MAGICBOX
#define MAGICBOX

#include <random>
#include <string>
#include <set>

class MagicBox {
private:
	std::set<unsigned> idBox_{};
public:
	std::size_t getIdBoxSize() const {
		return idBox_.size();
	}

	std::size_t drawId() {
		std::random_device rd;
		std::uniform_int_distribution<int> dist (1,9);
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
