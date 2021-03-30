#include "Website.hpp"
#include <ctime>


time_t Website::getLastCrawlingTime() const{
    this->lastCrawlingTime = time(nullptr);
}

const std::string &Website::getDomain() const {
    return this->domain;
}

const std::string &Website::getHomepage() const{
    return this->homepage;
}

int Website::getId() const {
    return this->id;
}