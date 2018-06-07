#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include <stdlib.h>  
#include <ctime>
#define LIST


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
	arco(int peso, node *llegada, node  *destino){
		this->peso = peso;
		this->llegada = llegada;
		this->destino = destino;
		
	}
	
};

class grafo
{
	static int n_de_nodos;
	vector <arco> arcos;
	vector <node> nodos;
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

int grafo::n_de_nodos = 0;


void grafo::add_arco(int d, int h, int w){
			
		node *destino;
		node *llegada;
		for(int i = 0; i < this->n_de_nodos; i++)
		{
			if (this->nodos[i].info == d){
				destino = &this->nodos[i];
			}
			else if (this->nodos[i].info == h){
				llegada = &this->nodos[i];
			}
		}
		arco arco_d_l = arco(w, llegada, destino);
		destino->ady.push_back(arco_d_l);
		llegada->ady.push_back(arco_d_l);
		this->arcos.push_back(arco_d_l);

}

int grafo::add_nodo(){
		node n;
		this->n_de_nodos++;
		n.info = n_de_nodos;
		this->nodos.push_back(n);
		return n_de_nodos;
} 

bool grafo::hay_arco(int d, int h){
		/*if (nodos[d].ady->peso ==nodos[h].ady->peso){
			if (nodos[d].ady->destino.info==nodos[h].info)
			{
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}*/
}

bool grafo::hay_camino(int d, int h){
	node *before_node = NULL;
	node *node;
	bool found_route = false;
	int counter = 0;
	for(int i = 0; i < this->n_de_nodos; i++)
	{
		if (this->nodos[i].info == d){
			node = &this->nodos[i];
			if (before_node == NULL){
				before_node = &this->nodos[i];
			}
		}
	}
	vector <int> visited;
	//cout << "| ";
	visited.push_back(node->info);
	while (!found_route  && counter < 10){
		visited.push_back(node->info);
		
		int pos = rand() % node->ady.size();
		bool in_vec = false;
		for(int i = 0; i < visited.size(); i++)
		{
			if (visited[i] == node->ady[pos].llegada->info) {
				in_vec = true;
				break;
			}	
		}
		int looped = 0;
		while(in_vec && looped < visited.size()){
			for(int i = 0; i < visited.size(); i++)
			{
				if (visited[i] == node->ady[pos].llegada->info | node->ady[pos].llegada->info == node->info) {
					pos = rand() % node->ady.size();
					looped += 1;
					if (looped == visited.size()){
						cout << "\n";
					}
					continue;
				}	
			}
			break;
		}
		cout << node->info << " | ";
		before_node = node;
		node = node->ady[pos].llegada;
		visited.push_back(node->info);
		if (node->info == h) {
			found_route = true;
			cout << node->info << " |\n";
			cout << "Founded Route\n" ;
		}
		counter++;
	}	

}


bool grafo::ruta_optima(int d, int h){
	node *before_node = NULL;
	node *node;
	bool found_route = false;
	int counter = 0;
	for(int i = 0; i < this->n_de_nodos; i++)
	{
		if (this->nodos[i].info == d){
			node = &this->nodos[i];
			if (before_node == NULL){
				before_node = &this->nodos[i];
			}
		}
	}
	vector <vector <int> > used;

	cout << "| ";
	while (!found_route){
		int max_val = 9999;
		int pos = 0;
		cout << node->info << " | ";
		for(int i = 0; i < node->ady.size(); i++)
		{
			if (node->ady[i].peso < max_val && before_node->info !=node->ady[i].llegada->info && node->info !=node->ady[i].llegada->info ){
				max_val = node->ady[i].peso;
				pos = i;
			}
		}
		before_node = node;
		node = node->ady[pos].llegada;

		if (node->info == h) {
			found_route = true;
			cout << node->info << " |\n";
			cout << "Founded Route\n" ;
		}
		counter++;
		
	}	

}





int main(int argc, char const *argv[])
{
	srand(time (NULL));
	grafo the_grafo = grafo(6);
	the_grafo.add_arco(0,1,0);
	the_grafo.add_arco(1,2,1);
	the_grafo.add_arco(1,4,0);
	
	the_grafo.add_arco(2,3,1);
	the_grafo.add_arco(3,1,1);
	the_grafo.add_arco(3,4,0);
	the_grafo.add_arco(3,5,1);
	the_grafo.add_arco(0,5,1);
	the_grafo.hay_camino(0, 4);

	return 0;
}