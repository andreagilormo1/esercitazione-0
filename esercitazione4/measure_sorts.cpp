#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "randfiller.h"
#include "my_sorts.hpp"

using namespace std;

int main() {
ofstream out("tempi_ordinamento.dati");
randfiller gen;

for (int dim = 4; dim <=8192; dim *= 2) {
vector<int> v_base(dim);
gen.fill(v_base, -1000, 1000);

// per fare queste 5 righe ho usato l'ia per capire usare le misurazioni poi
// ho copiato e incollato questo e l'ho eseguito per gli altri 2 algoritmi di ordinamento
vector<int> v1 = v_base;
auto s1 = chrono::high_resolution_clock::now();
bubble_sort(v1);
auto e1 = chrono::high_resolution_clock::now();
chrono::duration<double> d1 = e1 - s1;

vector<int> v2 = v_base;
auto s2 = chrono::high_resolution_clock::now();
selection_sort(v2);
auto e2 = chrono::high_resolution_clock::now();
chrono::duration<double> d2 = e2 - s2;

vector<int> v3 = v_base;
auto s3 = chrono::high_resolution_clock::now();
insertion_sort(v3);
auto e3 = chrono::high_resolution_clock::now();
chrono::duration<double> d3 = e3 - s3;

vector<int> v4 = v_base;
auto s4 = chrono::high_resolution_clock::now();
std::sort(v4.begin(), v4.end());
auto e4 = chrono::high_resolution_clock::now();
chrono::duration<double> d4 = e4 - s4;

out << dim << " " << d1.count() << " " << d2.count() << " " << d3.count() << " " << d4.count() << endl;
cout << "Misurazione N=" << dim << " completata" << endl;
}

out.close();
return 0;


}

