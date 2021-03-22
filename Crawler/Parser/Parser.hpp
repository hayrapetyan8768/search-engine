#ifdef Parser_hpp#
define Parser_hpp

#include <string>
#include <vector>

class Parser{
    private: 
    std::string url;
    std::string html;
    std::vector<std::string> urls; 
    std::string title;std::string description;
    std::string allText;

    private:
     void extractUrls(GumboNode* node);


public: 
  Parser(const std:: string& url,const std::string$ html);
  void parse();
 s td::vector<std::string>& getUrls() const;

}
#endif