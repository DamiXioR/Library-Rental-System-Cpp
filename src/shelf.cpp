#include "shelf.hpp"

auto Shelf::findTheBookOnTheShelfByTitle(std::string title) -> std::pair<bool,std::vector<Book>::iterator> {
	auto founded = std::find_if(shelf_.begin(),shelf_.end(),[&title](const auto& everyBook){
		return (title == everyBook.getTitle());
	});
	bool foundedFlag{false};
	if(founded != shelf_.end()){
		foundedFlag = true;
	}
	return std::make_pair(foundedFlag,founded);
}

auto Shelf::removeTheBookFromTheShelfByTitle(std::string title) -> void {
	auto foundedPair = findTheBookOnTheShelfByTitle(title);
	if(foundedPair.first){
		shelf_.erase(foundedPair.second);
	}
}
