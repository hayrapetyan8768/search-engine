#ifdef PARSER_HPP
define PARSER_HPP

#include <string>
#include <vector>
#include <iostream>

#include "Page.hpp"

class Parser{
    private: 
    
    
    std::vector<std::string> urls; 
    std::string title;
    std::string description;
    std::string allText;
    std::string domain;

    private:
     void extractUrls(GumboNode* node, const std::string& domain);
     bool isLinkAbsolute(const std::string& url);

public: 
  
  const std::vector<std::string>& getUrls() const;
  const std::string& getTitle() const;
  const std::string& getDescription() const;
  const std::string& getAllText() const;

  const std::string& getDomain(const std::string& rootURL) const; 
  void parse(const Page& page, const std::string& rootURL);
 

};

#endif