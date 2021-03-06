#ifndef SHELF
#define SHELF

#include "book.hpp"

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

class Shelf {
private:
	std::vector<Book> shelf_{};
public:
	auto isShelfEmpty() const -> bool {
		return shelf_.empty();
	}
	auto getBooksCount() const -> int {
		return shelf_.size();
	}
	auto putTheBookOnTheShelf(Book newBook) -> void {
		shelf_.push_back(newBook);
	}

	auto findTheBookOnTheShelfByTitle(std::string title) -> std::pair<bool,std::vector<Book>::iterator>;
	auto findTheBookOnTheShelfById(unsigned long long id) -> std::pair<bool,std::vector<Book>::iterator>;
	auto removeTheBookFromTheShelfById(unsigned long long id) -> void;
	auto getStringStreamWithAllBooksOntTheShelf() const -> std::stringstream {
		std::stringstream ss;
		for(const auto& book : shelf_){
			ss << book.getStringStreamOfBooksData().str();
		}
		return ss;
	}
};

#endif
