
// queste 2 righe fatte con ia
#ifndef DEPINA_MCB_HPP
#define DEPINA_MCB_HPP

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
// importante è leggermente piu lento di un de pina standard poichè il suo costo è quello di de pina
// per un fattore logaritmico, tuttavia per poche operazioni in piu acquisiamo una migliore leggibilita 
// del codice
class DePinaMCB {
private:
   // mi dice dati 2 insiemi di archi se essi condividono un numero di archi pari se
   // ritorna 0 e dispari se ritorna 1
    int prodotto_scalare(const set<unidirected_edge>& ciclo, const set<unidirected_edge>& S) {
        int comuni = 0;
        for (const auto& e : ciclo) {
            // entro se e è contenuto in S
            if (S.count(e)){
                
            comuni=comuni+1;
            
                
            }
        }
        return comuni % 2;
    }

    set<unidirected_edge> trova_ciclo_minimo(undirected_graph& grafo,
    const map<unidirected_edge, double>& peso, const set<unidirected_edge>& S) {
        
        // metto un costo enorme cosi sono sicuro che non sara il minore
        double min_costo = 1e9;
        // creo l'insieme che conterra gli archi di un ciclo ottimo per ognuno di quelli presenti
        set<unidirected_edge> ciclo_ottimo;
        
        for (const auto& e_test : grafo.all_edges()) {
            // per ogni arco nel grafo prendo i suoi nodi
            // e creo dist e padre
            int u = e_test.from(); 
            int v = e_test.to();
            map<int, double> dist;
            map<int, unidirected_edge> padre;
            // questa riga qua sotto scritta con l'ia 
            priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
            // operazioni di inizializzazione
            for (int n : grafo.all_nodes()){
            dist[n] = 1e9;
            dist[u] = 0;
            pq.push({0.0, u});
            }
            // procedimento su cui si base l'algoritmo
            while (!pq.empty()) {
                auto [d, curr] = pq.top(); // mi da il nodo e la sua distanza che è la minore
                pq.pop(); // e poi qua li tolgo
                if (d > dist[curr]) {
                    continue;
                }

                for (int vic : grafo.neighhours(curr)) {
                    unidirected_edge e_vic(curr, vic); // arco che contiene quello vicino
                    if (e_vic == e_test){
                        
                     continue;
                    }
                    if (dist[curr] + peso.at(e_vic) < dist[vic]) {
                        dist[vic] = dist[curr] + peso.at(e_vic);
                        padre[vic] = e_vic;
                        pq.push({dist[vic], vic});
                    }
                }
            }
            if (dist[v] < 1e9) {
                set<unidirected_edge> ciclo_corr = {e_test};
                int curr = v; 
                double costo = peso.at(e_test);
                // il codice dentro questo while aiutato con l'ia
                while (curr != u) {
                    unidirected_edge e_p = padre[curr];
                    ciclo_corr.insert(e_p);
                    costo += peso.at(e_p);
                    curr = (e_p.from() == curr) ? e_p.to() : e_p.from();
                }
                if (prodotto_scalare(ciclo_corr, S) == 1 && costo < min_costo) {
                    min_costo = costo;
                    ciclo_ottimo = ciclo_corr;
                }
            }
        }
        return ciclo_ottimo;
    }

public:
    vector<vector<int>> calcola(undirected_graph& grafo, const map<unidirected_edge, double>& peso) {
        vector<vector<int>> risultato_nodi;
        set<int> vis; 
        set<unidirected_edge> albero;
        queue<int> q;
        // se il grafo è vuoto
        if (grafo.all_nodes().empty()){
            
         return risultato_nodi;
        }

        int radice = *grafo.all_nodes().begin(); // valore del indirizzo del del nodo iniziale 
        q.push(radice);
        vis.insert(radice);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : grafo.neighhours(u)) {
                if (vis.find(v) == vis.end()) {
                    vis.insert(v); albero.insert(unidirected_edge(u, v)); q.push(v);
                }
            }
        }

        vector<unidirected_edge> co_albero;
        for (const auto& e : grafo.all_edges()) {
            if (albero.find(e) == albero.end()){
                
             co_albero.push_back(e);
            }
        }

        vector<set<unidirected_edge>> S(co_albero.size());
        for (size_t i = 0; i < co_albero.size(); ++i){
            
         S[i].insert(co_albero[i]);
        }

        for (size_t i = 0; i < co_albero.size(); ++i) {
            set<unidirected_edge> C_i = trova_ciclo_minimo(grafo, peso, S[i]);
            if (C_i.empty()){
                
             continue;
            }

            // ora devo convertire l'insieme di archi in una seguenza ordinata di nodi
            map<int, vector<int>> adj;
            for (const auto& e : C_i) {
                adj[e.from()].push_back(e.to());
                adj[e.to()].push_back(e.from());
            }
            // da qui fino al prossimo commento ausilio del ia
            vector<int> nodi_ciclo = { C_i.begin()->from() };
            int curr = nodi_ciclo[0], pred = -1;
            do {
                int prox = (adj[curr][0] != pred) ? adj[curr][0] : (adj[curr].size() > 1 ? adj[curr][1] : -1);
                if (prox == -1) break;
                nodi_ciclo.push_back(prox); pred = curr; curr = prox;
            } while (curr != nodi_ciclo[0] && nodi_ciclo.size() <= C_i.size());
            risultato_nodi.push_back(nodi_ciclo);

            // modifica dei vettori ortogonali S
            for (size_t j = i + 1; j < co_albero.size(); ++j) {
                if (prodotto_scalare(C_i, S[j]) == 1) {
                    for (const auto& e : C_i) {
                        if (S[j].count(e)) S[j].erase(e); else S[j].insert(e);
                    }
                }
            }
        }
        return risultato_nodi;
    }
};
// questa riga fattacon ia
#endif