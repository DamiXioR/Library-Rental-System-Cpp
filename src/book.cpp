#include "book.hpp"

Book::Book( std::string author, 
            std::string title, 
            std::string kind, 
            short date) :
            author_(author),
            title_(title),
            kind_(kind),
            date_(date)
{};