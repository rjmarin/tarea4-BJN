#include "grafo.h"


grafo::grafo(){
		n_de_nodos=0;

	}
grafo::grafo(int a){
	n_de_nodos = a;
	for (int i = 0; i < a; ++i)
	 {
	 	node n;
	 	n.info =i;
	 	this->nodos.push_back(n);
	 } 
}

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
		arco arco_l_d = arco(w, destino, llegada);
		destino->ady.push_back(arco_l_d);
		llegada->ady.push_back(arco_d_l);
		this->arcos.push_back(arco_d_l);
		this->arcos.push_back(arco_l_d);

}

int grafo::add_nodo(){
		node n;
		this->n_de_nodos++;
		n.info = n_de_nodos-1;
		this->nodos.push_back(n);
		return n_de_nodos;
} 

bool grafo::hay_arco(int d, int h){
	bool boolito= false;
	int first_size = this->nodos[d].ady.size();
	for (int i = 0; i < first_size ; ++i)
	{
		int second_size = this->nodos[h].ady.size();
		for (int j = 0; j < second_size; ++j)
		{
			if (this->nodos[d].ady[i].peso ==nodos[h].ady[j].peso){
				if (nodos[d].ady[i].destino->info==nodos[h].info)
				{
					boolito= true;
					return true;
				}
				else{
					continue;
				}
			}
			else{
			 continue;
			}
		
		}
	}
	if (boolito)
	{
		return true;
	}
	else{
		return false;
	}

		
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
	visited.push_back(node->info);
	while (!found_route  && counter < n_de_nodos){

		while (std::find(visited.begin(), visited.end(), node ->info)!= visited.end()){
			if (!node->ady.size()==0)
			{
				int pos = rand() % node->ady.size();
				node =	node->ady[pos].destino;
				if (!(std::find(visited.begin(), visited.end(), node ->info)!= visited.end()))
				{
					visited.push_back(node -> info);	
				}
				
				if (node->info== h) {
					found_route = true;
					return true;
					break;
				}
			}
			else{
				break;
			}
			
		}
		node = before_node;
		int size1 = visited.size();
		int size2 = node -> ady.size();
		if ( (size1 == this->n_de_nodos) | (size2 == 0)){//par que no dara tanta vuelta
			return false;
			break;
		}
		counter++;
	}
	return false;
}

int main()
{
	/* code */
	return 0;
}