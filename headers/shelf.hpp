#ifndef SHELF
#define SHELF

#include "book.hpp"

#include <string>
#include <vector>

class Shelf {
private:
	std::vector<Book> shelf_{};
public:
	bool isShelfEmpty() const {
		return shelf_.empty();
	}
	bool getBooksCount() const {
		return shelf_.size();
	}
	void putTheBookOnTheShelf(Book newBook) {
		shelf_.push_back(newBook);
	}
};

#endif
