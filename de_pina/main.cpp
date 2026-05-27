#include "grafo_undirected.hpp"
#include "de_pina.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Eigen/Dense"
#include "Eigen/SVD"



using namespace std;

void lettura_file(const string& filename, undirected_graph& grafo, map<unidirected_edge, double>& peso_arco, map<unidirected_edge, string>& tipo_arco) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Impossibile aprire il file: " << filename << endl;
        exit (0);
    }else{
    string type;
    double intensità;
    int partenza; 
    int arrivo;

    while(file>>type>>intensità>>partenza>>arrivo){
        grafo.add_edge(partenza,arrivo);
        peso_arco[unidirected_edge(partenza,arrivo)] = intensità;

        cout << "Tipo: " << type << ", Intensità: " << intensità << ", Partenza: " << partenza << ", Arrivo: " << arrivo << endl;
        if(type[0]=='R'||type[0]=='r'){
            tipo_arco[unidirected_edge(partenza,arrivo)]="resistenza";
        }
        else if(type[0]=='V'||type[0]=='v'){
            tipo_arco[unidirected_edge(partenza,arrivo)]="generatore";
        }
        else{
            cerr<<"Tipo di componente non riconosciuto: "<<type[0]<<endl;
            exit(0);
        }
    }
}
file.close();

}

void ricevi_resistori(const undirected_graph& grafo, const map<unidirected_edge, string>& tipo_arco, set<unidirected_edge>& resistori) {
    for (const auto& arco : grafo.archi) {
        if (tipo_arco.at(arco) == "resistenza") {
            resistori.insert(arco);
        }
    }
}

void riempi_R(Eigen::MatrixXd& R, const set<unidirected_edge>& resistori, const map<unidirected_edge, double>& peso_arco) {
    int i = 0;
    for (const auto& arco : resistori) {
        R(i, i) = peso_arco.at(arco);
        i++;
    }
}

void riempi_B(Eigen::MatrixXd& B, const set<unidirected_edge>& resistori, map<int, vector<int>> registro_cicli) {
    
    for (size_t i = 0; i < registro_cicli.size(); i++) {
        const auto& ciclo = registro_cicli[i];
        
        
        for (size_t nodo = 0; nodo < ciclo.size() - 1; nodo++) {
            int u = ciclo[nodo];     
            int v = ciclo[nodo + 1]; 

            
            int riga_resistore = 0;
            
            for (const auto& arco : resistori) {
               
                if ((arco.from() == u && arco.to() == v) || (arco.from() == v && arco.to() == u)) {
                    
                   
                    if (u < v) {
                        B(riga_resistore, i) = 1.0;
                    } 
                   
                    else {
                        B(riga_resistore, i) = -1.0;
                    }
                    
                    
                    break; 
                }
                
                riga_resistore++;
            }
        }
    }
}



          


int main() {
    string filename;
    cout << "Inserire nome del file da leggere: "<< endl;
    cin>>filename;
    
    undirected_graph circuito;
    map<unidirected_edge, double> peso_arco; 
    map<unidirected_edge, string > tipo_arco;

    lettura_file(filename, circuito, peso_arco, tipo_arco);
    circuito.all_edges();
    circuito.all_nodes();

    DePinaMCB solutore;
    // La funzione ora restituisce i nodi sequenziali dei cicli
    vector<vector<int>> base_cicli = solutore.calcola(circuito, peso_arco);

    cout << "i cicli  Cicli Minimi " << endl;
    
    map<int, vector<int>> registro_cicli;;
    for (size_t i = 0; i < base_cicli.size(); ++i) {
        cout << "C" << i + 1 << " = (";
        for (size_t j = 0; j < base_cicli[i].size(); ++j) {
            registro_cicli[i].push_back(base_cicli[i][j]);
            cout<<registro_cicli[i][j];
            if (j < base_cicli[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }

    set<unidirected_edge> resistori;
    ricevi_resistori(circuito, tipo_arco, resistori);
	
	Eigen::MatrixXd R(resistori.size(), resistori.size());
    R = Eigen::MatrixXd::Zero(resistori.size(), resistori.size());
    riempi_R(R, resistori, peso_arco);

    Eigen::MatrixXd B(resistori.size(), (circuito.archi.size()-circuito.nodi.size()+1));
    B = Eigen::MatrixXd::Zero(resistori.size(), (circuito.archi.size()-circuito.nodi.size()+1));
    riempi_B(B, resistori, registro_cicli);

    cout<<B<<endl;
	cout<<endl;
	cout<<endl;
	cout<<R<<endl;

	
	

   

    return 0;
    }