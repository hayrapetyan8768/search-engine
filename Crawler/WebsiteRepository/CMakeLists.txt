WebsiteRepository: $(patsubst %.cpp,%.o,$(wildcard *.cpp))
        gcc $^ -o $@ 

    %.o: %.cpp
        gcc -c $<

    WebsiteRepository.o: WebsiteRepository.hpp Website.hpp
    Website.o:   Website.hpp 

	clean: 
        rm *.o WebsiteRepository