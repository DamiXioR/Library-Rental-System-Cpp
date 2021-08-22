#ifndef SHELF
#define SHELF

#include "book.hpp"

#include <algorithm>
#include <string>
#include <utility>
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
	auto findTheBookOnTheShelfByTitle(std::string title) -> std::pair<bool,std::vector<Book>::iterator> {
		auto founded = std::find_if(shelf_.begin(),shelf_.end(),[&title](const auto& everyBook){
			return (title == everyBook.getTitle());
		});
		bool foundedFlag{false};
		if(founded != shelf_.end()){
			foundedFlag = true;
		}
		return std::make_pair(foundedFlag,founded);
	}
};

#endif
