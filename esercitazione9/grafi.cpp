#include <iostream>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>

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
map<int,set<int>> vicini;

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


set<unidirected_edge> all_edges() const {
return archi;
}

set<int> all_nodes() const {
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

// creato questo metodo con l'ausilio del inteligenza artificiale

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

// lo uso per modellare la coda
template <typename T>
class fifo{
    list <T> lista;
    public:
    fifo(){
        
    }
    void put( T x){
        lista.push_back(x);
    }
    // non posso modificare la lista
    bool empty() const{
        return lista.empty();
    }
    
    T get (){
        T valore= lista.front();
        lista.pop_front();
        return valore;
    }
    
};

// lo uso per modellare una pila
template <typename T>
class lifo{
    list <T> lista;
    public:
    lifo(){
        
    }
    void put( T x){
        lista.push_back(x);
    }
    // non posso modificare la lista
    bool empty() const{
        return lista.empty();
    }
    
    T get (){
        T valore= lista.back();
        lista.pop_back();
        return valore;
    }
    
};

// ho usato l'ia veramente pochissimo per fare una specie di brainstorming sul impostazione
// e poi da li ho sviluppato il codice
// (ci sono più commenti del solito che mi sono dovuto segnare un po
// di roba per non fare casini)

template < typename C>
// devo passare 3 cose il grafo,il nodo da cui parto e il tipo di metodo
// con cui faccio la visita bfs o dfs
undirected_graph graph_visit(undirected_graph& g, int partenza, C& lista) {

undirected_graph albero;

//la visita su un nodo mi dara un insieme di nodi che contiene al piu
// tutti i nodi del grafo quindi devo creare un vettore in cui ci sono n celle
// e metterle tutte false visto che al inizio non ho visitato nulla
map<int, bool> visitato;


lista.put(partenza);
visitato[partenza] = true;

while (!lista.empty()) {
// ogni volta tolgo esattamente un nodo dalla lista,quindi quando
// non ci sono piu collegamenti piano piano svuoto la lista
int u = lista.get(); // in ase all oggetto del tipo di classe passato
// decide come togliere

//  prendo un nodo e i suoi vicini e aggiungo isuoi vicini nella lista
// solo se non è gia stato visitato per evitare cicli infiniti come detto
// a lezione
for (int v : g.neighhours(u)) {
if (!visitato[v]) {
visitato[v] = true;

// Aggiungo l'arco all'albero risultante
albero.add_edge(u, v);

// Mettiamo il nuovo nodo nella pila/coda
lista.put(v);
}
}
}

return albero;
}



void dfs_aiutami(undirected_graph& g, int u, map<int, bool>& visitato,
undirected_graph& albero) {
    visitato[u] = true;
    // questo in realta anche se l'ho un po paciocato l'ho fatto 
    // praticamente uguale a prima quidni la logica e la stessa
    // se sei un professore non leggere è una roba informale per me
    //pensala come quando ad esempio studiavi come trovare un nodo data la 
    // sua chiave facevi una roba simile solo che al posto di farlo con la
    // ricerca della chiave lo fai con il dfs
    for (int v : g.neighhours(u)) {
        if (!visitato[v]) {
            albero.add_edge(u, v);
            dfs_aiutami(g, v, visitato, albero);
        }
    }
}


undirected_graph recursive_dfs(undirected_graph& g, int partenza) {
    undirected_graph albero;
    map<int, bool> visitato; 
    dfs_aiutami(g, partenza, visitato, albero);
    return albero;
}
// per questo metodo visto che è un algoritmo molto usato l'ia per aiutarmi
// e poi l'ho un po aggiustato per ottenere il metodo come 
// nelle slide come il professore vicini

map<int, double> dijkstra(undirected_graph& g, int partenza,
map<unidirected_edge, double>& pesi) {
    map<int, double> distanze;
    
    // ho messo un numero tanto alto perche infinito non c.è
    for (int n : g.all_nodes()){
        
     distanze[n] = 1e9;
    }
    distanze[partenza] = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>,
    greater<pair<double, int>>> pq;
    pq.push({0, partenza});

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        
        if (d > distanze[u]) continue;

        
        for (int v : g.neighhours(u)) {
            
            double p_arco = pesi[unidirected_edge(u, v)];
            
            
            if (distanze[u] + p_arco < distanze[v]) {
                distanze[v] = distanze[u] + p_arco;
                pq.push({distanze[v], v});
            }
        }
    }
    return distanze;
}

void generatore(const undirected_graph& g, string nome_file,
map<unidirected_edge, double> pesi = {}) {
    ofstream file(nome_file);
    file << "graph G {" << endl;
    if(nome_file=="originale.dot"){
        
    
    for (unidirected_edge const& e : g.all_edges()) {
        // ho guardato con l'ia come andavano messi i caratteri
        // per usare graphviz (non sapevo dove mettere i trattini)
        
        file << "  " << e.from() << " -- " << e.to() << 
        " [label=\"" << pesi[e] << "\"];"
        << endl;
    }
    }
    else{
        for (auto const& e : g.all_edges()) {
        
        
        file << "  " << e.from() << " -- " << e.to() <<endl;
        
        
    }
        
    }
    file << "}" << endl;
    file.close();
}

int main() {
    undirected_graph g;

    g.add_edge(43, 12);
    g.add_edge(7, 21);
    g.add_edge(33, 43);
    g.add_edge(12, 7);
    g.add_edge(5, 33);
    g.add_edge(21, 5);

    // Controllo veloce della dimensione
    cout << "Nodi " << g.all_nodes().size() << endl;
    cout << "Archi " << g.all_edges().size() << endl;

    // Vediamo se i vicini di 7 sono giusti (dovrebbero essere 12 e 21)
    cout << "Vicini 7 ";
    for(int x : g.neighhours(7)) cout << x << " ";
    cout << endl;

    // Test posizione e recupero a partire dalla posizione
    unidirected_edge tmp(33, 43);
    int p = g.edge_number(tmp);
    cout << "Pos arco (33,43) " << p << " " << g.edge_at(p) << endl;

    // Test della sottrazione
    undirected_graph g2;
    g2.add_edge(43, 12);
    g2.add_edge(7, 21);

    undirected_graph res = g - g2;
    cout << "Archi dopo la sottrazione " << res.all_edges().size() << endl;

    for(auto const& a : res.all_edges()) {
        cout << "resta " << a << endl;
    }
    
    // qui faccio la visita in 3 modi diversi

    lifo<int> s;
    undirected_graph dfsG = graph_visit(g, 7, s);

    fifo<int> q;
    undirected_graph bfsG = graph_visit(g, 7, q);

    
    undirected_graph recDfsG = recursive_dfs(g, 7);

    // uso un arco come chiave e dato un arcogiustamente ci devo
    // associare un double come peso (la mappa mi sembrava adatta)
    map<unidirected_edge, double> pesi_archi;
    // si scegli che peso dare per ogni arco
    pesi_archi[unidirected_edge(43, 12)] = 1.5;
    pesi_archi[unidirected_edge(7, 21)] = 10.0;
    pesi_archi[unidirected_edge(33, 43)] = 2.4;
    pesi_archi[unidirected_edge(12, 7)] = 5.0;
    pesi_archi[unidirected_edge(5, 33)] = 0.5;
    pesi_archi[unidirected_edge(21, 5)] = 7.1;

    map<int, double> dist = dijkstra(g, 7, pesi_archi);
    cout<<"la distanza del arco (12,7) é " <<dist[12]<<endl;

    generatore(g, "originale.dot", pesi_archi); 
    generatore(bfsG, "bfs.dot"); 
    generatore(recDfsG, "dfs_ricorsiva.dot"); 

    return 0;
}