#include <iostream>
#include <cstdlib.h>
#include <list>
#include <sstream>


typedef struct nodo{
            int info;
            struct node *sgte;
            struct node *ante; 
            struct arcos *ady;
            }node;
            
struct arcos{
			  int peso;
              struct node * destino;
              struct node * llegada;
              };

class grafo
{
	int n_de_nodos;
	node * n;
	arista * n; 
public:
	grafo(){
		grafo * primer = new grafo;
		c=0;
		n_de_nodos=0;
	}
	grafo(int a){
		c=0;
		n_de_nodos = a;
		for (int i = 0; i < a; ++i)
		 {
		 	node* n= new node;
		 	n->info =c;
		 	c++;

		 } 
	}
	void add_arco(int d, int h, int w);
	int add_nodo();
	bool hay_arco(int d, int h);
	bool hay_camino(int d, int h);
	bool ruta_optima(int d, int h);	
};

void grafo::add_arco(int d, int h, int w){

}

int grafo::add_nodo(){

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