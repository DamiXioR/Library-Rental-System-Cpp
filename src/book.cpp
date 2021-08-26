#include "book.hpp"

Book::Book( std::string author, 
            std::string title, 
            std::string kind, 
            short date,
            unsigned long long uniqueId ) :
            author_(author),
            title_(title),
            kind_(kind),
            date_(date),
            uniqueId_(uniqueId)
{};

 auto Book::getStringStreamOfBooksData() const -> std::stringstream {
	std::stringstream ss;
	ss << "Title: " << getTitle() << " Kind: " << getKind() << " Date: " << getDate() << " ID: " << getId();
	return ss;
}