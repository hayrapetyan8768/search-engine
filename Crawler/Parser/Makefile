Parser: $(patsubst %.cpp,%.o,$(wildcard *.cpp))
        gcc $^ -o $@ 

    %.o: %.cpp
        gcc -c $<

    Parser.o:     Parser.hpp 
	clean: 
        rm *.o Parser
    