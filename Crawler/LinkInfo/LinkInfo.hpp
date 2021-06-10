#ifndef LINKENTERY_HPP
#define LINKENTERY_HPP

#include <string>
#include "LinkStatus.hpp"

class LinkEntery
{
private:
      int id;
      std::string domain;
      std::string url;
      time_t loaded;
      LinkStatus status;

public:
    LinkEntery(int id, std::string& domain, std::string url, time_t loaded, LinkStatus status);

    int getId() const;
    const std::string getDomain();

};




#endif