#include "LinkEnteryRepository.hpp"


const std::vector<LinkEntery> LinkEnteryRepository::getBy(const std::string& domain, LinkStatus status){
 std::vector<LinkEntery> result;
 for(auto& link : this->links){

     if(link.getDomain() = domain && link.getStatus() = status){

         result.push_back(link);
     }
 }
 return result;
} 