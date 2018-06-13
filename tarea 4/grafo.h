#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stdlib.h>  
#include <ctime>
#include "arco.h"
using namespace std;


class grafo
{
	static int n_de_nodos;
	vector <arco> arcos;
	vector <node> nodos;
public:
	grafo();
	grafo(int a);
	~grafo(){
	}
	void add_arco(int d, int h, int w);
	int add_nodo();
	bool hay_arco(int d, int h);
	bool hay_camino(int d, int h);
};
