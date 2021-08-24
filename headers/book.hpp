#ifndef BOOK
#define BOOK

#include <string>

class Book {
private:
	std::string author_{};
	std::string title_{};
	std::string kind_{};
	short date_{};
	unsigned long long uniqueId_{};

public:
	Book(std::string author, std::string title, std::string kind, short date, unsigned long long uniqueId);

	auto getAuthor() const -> std::string {
		return author_;
	}
	auto getTitle() const -> std::string {
		return title_;
	}
	auto getKind() const -> std::string {
		return kind_;
	}
	auto getDate() const -> short {
		return date_;
	}

};

#endif
