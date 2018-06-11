#include "grafo.h"


grafo::grafo(){
		grafo * primer = new grafo;
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
	for (int i = 0; i < this->nodos[d].ady.size(); ++i)
	{
		for (int j = 0; j <this->nodos[h].ady.size(); ++j)
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
	while (!found_route  && counter < 10){

		while (std::find(visited.begin(), visited.end(), node ->info)!= visited.end()){
			if (!node->ady.size()==0)
			{
				int pos = rand() % node->ady.size();
				node =	node->ady[pos].destino;
				if (!(std::find(visited.begin(), visited.end(), node ->info)!= visited.end()))
				{
					visited.push_back(node -> info);	
				}
				cout << "|" << node ->info; 
				if (node->info== h) {
					found_route = true;
					cout << node->info << " |\n";
					cout << "Founded Route\n" ;
					break;
				}
			}
			else{
				break;
			}
			
		}
		node = before_node;
		if (visited.size()==this->n_de_nodos | node -> ady.size()==0){//par que no dara tanta vuelta
			cout << "ruta no encontrada\n";
			break;
		}
		counter++;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}