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

auto Shelf::findTheBookOnTheShelfById(unsigned long long id) -> std::pair<bool,std::vector<Book>::iterator> {
	auto founded = std::find_if(shelf_.begin(),shelf_.end(),[&id](const auto& everyBook){
		return (id == everyBook.getId());
	});
	bool foundedFlag{false};
	if(founded != shelf_.end()){
		foundedFlag = true;
	}
	return std::make_pair(foundedFlag,founded);
}

auto Shelf::removeTheBookFromTheShelfById(unsigned long long id) -> void {
	auto foundedPair = findTheBookOnTheShelfById(id);
	if(foundedPair.first){
		shelf_.erase(foundedPair.second);
	}
}