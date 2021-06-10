PageLoader: $(patsubst %.cpp,%.o,$(wildcard *.cpp))
        gcc $^ -o $@ 

    %.o: %.cpp
        gcc -c $<

    PageLoader.o:     PageLoader.hpp Page.hpp 
    Page.o:   Page.hpp 

	clean: 
        rm *.o PageLoader