CC = g++
FLAGS = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
EX = grf
LIB = _grafo.so

$(EX): grafo.o arco.o $(LIB)
	$(CC) -o $(EX) grafo.o arco.o $(FLAGS)

$(LIB): grafo.o arco.o interface.i
	swig -python -c++ interface.i
	$(CC) -fPIC -c arco.h grafo.h interface_wrap.cxx arco.cpp grafo.cpp -I/usr/include/python2.7/
	$(CC) -shared interface_wrap.o arco.o grafo.o -o $(LIB) -lstdc++

grafo.o: grafo.cpp
	$(CC) $(FLAGS) -c -fPIC -o grafo.o grafo.cpp

arco.o: arco.cpp
	$(CC) $(FLAGS) -c -o arco.o arco.cpp


clean:
	rm *.o
	rm grafo.h.gch
	rm grafo.py
	rm grf
	rm *.so
	rm *.cxx
