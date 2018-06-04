#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#define LIST


using namespace std;
typedef struct nodo node;
typedef struct arcos arco;

typedef struct nodo{
            int info;
            node *sgte; 
            arcos *ady;
}node;
            
typedef struct arcos{
			  int peso;
              node  destino;
              node  llegada;
}arco;

class grafo
{
	static int n_de_nodos;
	vector <node> nodos;
	node  n;
	arco  a; 
public:
	grafo(){
		grafo * primer = new grafo;
		n_de_nodos=0;

	}
	grafo(int a){
		n_de_nodos = a;
		for (int i = 0; i < a; ++i)
		 {
		 	node n;
		 	n.info =i;
		 	this->nodos.push_back(n);
		 } 
	}
	void add_arco(int d, int h, int w);
	int add_nodo();
	bool hay_arco(int d, int h);
	bool hay_camino(int d, int h);
	bool ruta_optima(int d, int h);	
};


void grafo::add_arco(int d, int h, int w){
	int c = grafo::n_de_nodos;
	if (d<=c && h<=c){
		arco * a;
		a->peso = w;
		for (int i = 0; i < n_de_nodos; ++i)
		{
			if(i == d){
				a->llegada = this->nodos[i];

			}
			else if (i==h)
			{
				a->destino = this->nodos[i];
			}
		}
	}		
}

int grafo::add_nodo(){
		node n;
		this->n_de_nodos++;
		n.info = n_de_nodos;
		this->nodos.push_back(n);
		return n_de_nodos;
} 

bool grafo::hay_arco(int d, int h){

}

bool grafo::hay_camino(int d, int h){

}

bool ruta_optima(int d, int h){

}





int main(int argc, char const *argv[])
{
	
	return 0;
}