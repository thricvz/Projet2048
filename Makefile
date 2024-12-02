

tests.o:tests.cpp
	g++ -c tests.cpp

modele.o:modele.cpp
	g++ -c modele.cpp

test: modele.o tests.o
	g++ modele.o tests.o -o test

clean:
	rm modele.o tests.o test