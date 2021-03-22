#include "Parser.hpp"
#include <gumbo.h>

Parser::Parser(const std:: string& url,const std::string$ html){
    this->url=url;this->html=html;
}

void Parser::extractUrls(GumboNode* node){
 if (node->type != GUMBO_NODE_ELEMENT){ 
     return;
      }
 if (node->element.tag == GUMBO_TAG_A){ 
     GumboAttribute* herf =gumbo_get_attribute(&node->v.element.attributes, "herf");
      if (href == nullptr || href->value == nullptr){ 
          return;
           }
 this->urls.push_back(std::string(href->value)); 
 }
 
  GumboVector* children = &node->v.element.children; 
  for (unsigned i = 0; i < children->length; i++){ 
      this->extractUrls(static_cast<GumboNode*>(children->data[i])); 
      } 
      
      }
void Parser::parse(){ 
    GumboOutput* output = gumbo_parse(this->html.c_str()); 
    this->extractUrl(output->root); gumbo_destroy_output(&kGumboDefaultOptions, output);
 }
const std::vector<std::string>& Parser::getUrls() const{ 
    return this->urls;
}