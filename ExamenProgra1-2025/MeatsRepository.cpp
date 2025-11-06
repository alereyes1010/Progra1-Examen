#include "MeatsRepository.h"
#include <stdexcept>


MeatsRepository::MeatsRepository() {
    auto data = DataLoader::LoadFromFile("meats.txt");
    data_ = std::move(data);
}

int MeatsRepository::GetAvailableQuantity(const std::string& meatsType) const {
    auto it = data_.find(meatsType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown meats type: " + meatsType);
    }
    return std::stoi(it->second[0]);
}

void MeatsRepository::UpdateQuantity(const std::string& meatsType, int newQuantity) {
    auto it = data_.find(meatsType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown meats type: " + meatsType);
    }
    it->second[0] = std::to_string(newQuantity);
}