#ifndef SHELF
#define SHELF

#include "book.hpp"

#include <string>
#include <vector>

class Shelf {
private:
	std::vector<Book> shelf_{};
public:
	bool isShelfEmpty() {
		return shelf_.empty();
	}
	bool getBooksCount() {
		return shelf_.size();
	}
};

#endif
