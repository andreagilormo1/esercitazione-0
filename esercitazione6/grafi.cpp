
#include <iostream>
#include <list>
#include <set>
#include <map>
using namespace std;
class unidirected_edge {
    int nodo1,nodo2;
    public:
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
    // mi devo ricordare che con il const dopo le tonde io non
    // posso modificare gli attributi della classe dentro quel metodo
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
set<unidirected_edge> archi;
set<int> nodi;
map<int, set<int>> vicini;

public:
// non serve perchè ho gia dichirato prima
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
return -1; // lo devo fare solo se non trovo l'arco nel grafo
}

unidirected_edge edge_at(int n) {
auto it = archi.begin(); // uso un iteratore
advance(it, n);// ho visto su ia che sposta un iteratore avanti di n posizioni
// dunque se parto dalla posizione 0  mi spostero avanti l'iteratore su a puntare
// al arco alla posizione n
return *it;
}

// creato con l'ausilio del inteligenza artificiale

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
    

int main() {
undirected_graph g;

// Inserisco un po' di archi a caso
g.add_edge(43, 12);
g.add_edge(7, 21);
g.add_edge(33, 43);
g.add_edge(12, 7);
g.add_edge(5, 33);
g.add_edge(21, 5);

// Controllo velociìe della dimensione
cout << "Nodi " << g.all_nodes().size() << endl;
cout << "Archi " << g.all_edges().size() << endl;

// Vediamo se i vicini di 7 sono giusti (dovrebbero essere 12 e 21)
cout << "Vicini 7 ";
for(int x : g.neighhours(7)) cout << x << " ";
cout << endl;

// Test posizione e recupero a partire dalla posizione
unidirected_edge tmp(33, 43);
int p = g.edge_number(tmp);
cout << "Pos arco (33,43) " << p  << g.edge_at(p) << endl;

// Test della sottrazione
undirected_graph g2;
g2.add_edge(43, 12);
g2.add_edge(7, 21);

undirected_graph res = g - g2;
cout << "Archi dopo la  sottrazione " << res.all_edges().size() << endl;

for(auto const& a : res.all_edges()) {
cout << "resta " << a << endl;
}

return 0;
}

