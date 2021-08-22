#ifndef BOOK
#define BOOK

#include <string>

class Book {
private:
	std::string author_{};
	std::string title_{};
	std::string kind_{};
	short date_{};
public:
	Book(std::string author, std::string title, std::string kind, short date);

	std::string getAuthor() const {
		return author_;
	}
	std::string getTitle() const {
		return title_;
	}
	std::string getKind() const {
		return kind_;
	}
	short getDate() const {
		return date_;
	}

};

#endif
