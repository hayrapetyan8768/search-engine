#ifndef LINKENTERYREPOSITORY_HPP
#define LINKENTERYREPOSITORY_HPP

#include <vector>
#include "LinkEntery.hpp"

class LinkEnteryRepository
{
private:
    std::vector<LinkEntery> links;

public:
    const std::vector<LinkEntery>& getAll() const;
    const std::pair<bool, LinkEntery> getById() const;
    const std::pair<bool, LinkEntery> getByURL() const;
    const std::vector<LinkEntery> getBy(const std::string& domain, LinkStatus status) const;

    
};



#endif