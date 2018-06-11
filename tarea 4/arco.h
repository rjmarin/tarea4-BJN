#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stdlib.h>  
#include <ctime>
using namespace std;

class arco;

class node{
	public:
	int info;
	vector <arco> ady;
};

class arco{
	public:
	int peso;
	node  *destino;
	node  *llegada;
	arco(int peso, node *llegada, node * destino);
	
};