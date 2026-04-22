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
double sommab=0, sommas=0, sommai=0, sommam=0, sommaq=0, sommaqh=0, sommastd=0;
int dim=2;
int cont=0;

for (int n = 1; n <= 9; n++) {
dim = dim * 2;
cout << dim << endl;
cont = 0;
// aiusilio del ia per capire come dichiarare un vettore dinamico  di vettori dinamici
vector<vector<int>> campioni(100, vector<int>(dim));
for (int k = 0; k < 100; k++) {
gen.fill(campioni[k], -1000, 1000);
cont++;
}

vector<vector<int>> v1 = campioni;
auto s1 = chrono::high_resolution_clock::now();
for (int k = 0; k < 100; k++) {
bubble_sort(v1[k]);
}
auto e1 = chrono::high_resolution_clock::now();
chrono::duration<double> d1 = e1 - s1;
sommab = d1.count();

vector<vector<int>> v2 = campioni;
auto s2 = chrono::high_resolution_clock::now();
for (int k = 0; k < 100; k++) {
selection_sort(v2[k]);
}
auto e2 = chrono::high_resolution_clock::now();
chrono::duration<double> d2 = e2 - s2;
sommas = d2.count();

vector<vector<int>> v3 = campioni;
auto s3 = chrono::high_resolution_clock::now();
for (int k = 0; k < 100; k++) {
insertion_sort(v3[k]);
}
auto e3 = chrono::high_resolution_clock::now();
chrono::duration<double> d3 = e3 - s3;
sommai = d3.count();

vector<vector<int>> v4 = campioni;
auto s4 = chrono::high_resolution_clock::now();
for (int k = 0; k < 100; k++) {
merge_sort(v4[k], 0, dim - 1);
}
auto e4 = chrono::high_resolution_clock::now();
chrono::duration<double> d4 = e4 - s4;
sommam = d4.count();

vector<vector<int>> v5 = campioni;
auto s5 = chrono::high_resolution_clock::now();
for (int k = 0; k < 100; k++) {
quick_sort(v5[k], 0, dim - 1);
}
auto e5 = chrono::high_resolution_clock::now();
chrono::duration<double> d5 = e5 - s5;
sommaq = d5.count();

vector<vector<int>> v6 = campioni;
auto s6 = chrono::high_resolution_clock::now();
for (int k = 0; k < 100; k++) {
quick_sort_hybrid(v6[k], 0, dim - 1);
}
auto e6 = chrono::high_resolution_clock::now();
chrono::duration<double> d6 = e6 - s6;
sommaqh = d6.count();

vector<vector<int>> v7 = campioni;
auto s7 = chrono::high_resolution_clock::now();
for (int k = 0; k < 100; k++) {
std::sort(v7[k].begin(), v7[k].end());
}
auto e7 = chrono::high_resolution_clock::now();
chrono::duration<double> d7 = e7 - s7;
sommastd = d7.count();

cout << "Misurazione N=" << dim << " completata" << endl;
cout << "la media del boouble è " << (sommab/cont) << endl;
cout << "la media del selection è " << (sommas/cont) << endl;
cout << "la media del insertion è " << (sommai/cont) << endl;
cout << "la media del merge è " << (sommam/cont) << endl;
cout << "la media del quick è " << (sommaq/cont) << endl;
cout << "la media del quick ibrido è " << (sommaqh/cont) << endl;
cout << "la media di std::sort è " << (sommastd/cont) << endl;

out << dim << " " << (sommab/cont) << " " << (sommas/cont) << " " << (sommai/cont) << " " << (sommam/cont) << " " << (sommaq/cont) << " " << (sommaqh/cont) << " " << (sommastd/cont) << endl;
}

out.close();
return 0;
}