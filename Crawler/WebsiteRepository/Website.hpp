#ifndef WEBSITE_HPP
#define WEBSITE_HPP

#include <string>

class Website
{
private:

    int id;
    std::string domain;
    std::string homepage;
    time_t lastCrawlingTime;

public:

    int getId() const;
    const std::string& getDomain() const;
    const std::string& getHomepage() const;
    time_t getLastCrawlingTime() const;

    Website(int id, const std::string& domain, const std::string&  hompagae,);
};



#endif
