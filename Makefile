tests.o: tests.cpp
	g++ -g -c tests.cpp  

modele.o: modele.cpp
	g++ -g -c modele.cpp  

test: modele.o tests.o
	g++ -g modele.o tests.o -o tests  

clean:
	rm -f modele.o tests.o tests
