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
