#include "magicBox.hpp"

#include <climits>

auto MagicBox::drawId() -> unsigned long long {
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