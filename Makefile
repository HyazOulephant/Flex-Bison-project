all:
	flex -o projet.flex.cpp projet.flex
	bison -t -d projet.y -o projet.y.cpp
	g++ -o projet projet.flex.cpp projet.y.cpp instruction.cpp numerique.cpp function.cpp -w `sdl2-config --cflags --libs`
	./projet tests/collier.txt
