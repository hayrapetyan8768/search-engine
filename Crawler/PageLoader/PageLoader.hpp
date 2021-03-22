#ifndef PAGE_LOADER_HPP
#define PAGE_LOADER_HPP

#include "Page.hpp"
#include <curl/curl.h>


class PageLoader{
public: 

Page load(const std::string& url);

private: 

static std::size_t write_data(void* ptr, std::size_t size, std::size_t nmemb, std::string* data);

};

#endif