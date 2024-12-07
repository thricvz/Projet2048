all: jeu 

graphics.o:graphics.cpp
	g++ -c graphics.cpp

sfml:graphics.o modele.o
	g++ graphics.o modele.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

clean_sfml: 
	rm graphics.o sfml-app

tests.o: tests.cpp
	g++ -g -c tests.cpp  

modele.o: modele.cpp
	g++ -g -c modele.cpp  

test: modele.o tests.o
	g++ -g modele.o tests.o -o tests  

2048.o : 2048.cpp
	g++ -g -c 2048.cpp

jeu: modele.o 2048.o
	g++ modele.o 2048.o -o jeu

clean_test:
	rm -f modele.o tests.o tests

clean:
	rm -f modele.o 2048.o jeu