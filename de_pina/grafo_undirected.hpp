#include <iostream>
#include <list>
#include <set>
#include <map>

using namespace std;

// questo codice è copiato dal esercitazione 8 
// ho solo rimosso tutti i commenti (incluso se avevo usato l'ia per qualcosa)
// si può vedere direttamente da li
class unidirected_edge {
    int nodo1,nodo2;
    public:
    unidirected_edge() {}
    unidirected_edge(int nodoa,int nodob){
        if (nodob==nodoa){
            nodo1=nodoa;
            nodo2=nodoa;
        }
        if (nodoa>nodob){
            nodo2=nodoa;
            nodo1=nodob;
        }
        else {
            nodo1=nodoa;
            nodo2=nodob;
        }
    }
    
    int from () const{
        return nodo1;
    }
    int to() const{
        return nodo2;
    }
    
    bool operator<(const unidirected_edge & arco) const{
        if(nodo1!=arco.nodo1){
            return nodo1<arco.nodo1;
        }
        return nodo2<arco.nodo2;
    }
    bool operator==(const unidirected_edge & arco) const{
        
        return (nodo1==arco.nodo1 && nodo2==arco.nodo2);
    }
    
    // questo metodo l'ho creato con l'ausilio del ia
  friend ostream& operator<<(ostream& out,const unidirected_edge& e){
        out<<"("<<e.nodo1<<" , "<<e.nodo2<<")";
        return out;
    }
    
};


class undirected_graph {
    
    public:

set<unidirected_edge> archi;
set<int> nodi;
map<int, set<int>> vicini;



undirected_graph() {}

undirected_graph(const undirected_graph& grafo) {
archi = grafo.archi;
nodi = grafo.nodi;
vicini = grafo.vicini;
}



set<int> neighhours(int nodo) {
return vicini[nodo];
}

void add_edge(int a, int b) {
unidirected_edge nuovo_arco(a, b);
archi.insert(nuovo_arco);
nodi.insert(a);
nodi.insert(b);
vicini[a].insert(b);
vicini[b].insert(a);
}


set<unidirected_edge> all_edges()  {
return archi;
}

set<int> all_nodes()  {
return nodi;
}

int edge_number(unidirected_edge arco) {
int pos = 0;
for (const unidirected_edge& e : archi) {
if (e == arco) return pos;
pos++;
}
return -1; 
}

unidirected_edge edge_at(int n) {
auto it = archi.begin(); 
advance(it, n);
return *it;
}


undirected_graph operator-(const undirected_graph& altro) {
undirected_graph risultato;
for (const unidirected_edge& e : archi) {
if (altro.archi.find(e) == altro.archi.end()) {
risultato.add_edge(e.from(), e.to());
}
}
return risultato;
}


};