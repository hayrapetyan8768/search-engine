#include "DocumentRepository.hpp"
#include "LinkInfoRepository.hpp"
#include "WebsiteRepository.hpp"
#include "PageLoader.hpp"
#include "Parser.hpp"


int main()
{
    const sql::SQLString hostName = "tcp://localhost:3306/Crawler";
    const sql::SQLString userName = "root";
    const sql::SQLString password = "Admin_1390";

    sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
    auto connection = driver->connect(hostName, userName, password);

    if(!connection)
    {
        std::cout << "Connection failed " << std::endl;
        return 0;
    }

    WebsiteRepository websiteRepo(connection);
    
    auto websites = websiteRepo.getAll();


    LinkInfoRepository linkRepo;  
    PageLoader pageloader;

    DocumentRepository documentRepo;
    for(auto& website : websites)
    {
        std::cout << "Crawling website: " << website.getDomain() << " " << website.getHomepage() << std::endl;
        linkRepo.save(LinkInfo(website.getHomepage(), website.getWebsiteId(), LinkStatus::WAITING), connection); 
        while(true)
        {
            
            auto& links = linkRepo.getBy(website.getWebsiteId(), LinkStatus::WAITING, 10, connection);
            if(links.size() == 0)
            {
                break;
            }
            
            for(auto& link : links)
            {
                std::string domain = website.getDomain();
                Page page = pageloader.load(link.getUrl(), domain);
                if (page.getStatus() < 200 || page.getStatus() >= 300)
                {
                    linkRepo.save(LinkInfo(link.getUrl(), website.getWebsiteId(), LinkStatus::ERROR), connection);
                    continue;
                }
                Parser parser;
                parser.parse(page.getBody(), page.getEffectiveUrl(), page.getDomain());
                
                documentRepo.add(Document(link.getUrl(), parser.getTitle(), parser.getDescription(), parser.getContent()), connection);
                
                for(auto& url : parser.getLinks())
                {
                    if(linkRepo.getByUrl(url).has_value())
                    {
                        continue;
                    }
                    linkRepo.save(LinkInfo(url, website.getWebsiteId(), LinkStatus::WAITING), connection);
                }

                linkRepo.save(LinkInfo(link.getUrl(), link.getWebsiteId(), LinkStatus::LOADED), connection);
            }

        }
        
        websiteRepo.update(website.getDomain(), Website(website.getWebsiteId(), website.getDomain(), website.getHomepage(), true), connection);
    }
    
    return 0;
}