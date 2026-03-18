# include <iostream>
using namespace std;


 int main()
 {
double ad[4] = {0.0, 1.1, 2.2, 3.3};
float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
int ai[3] = {0, 1, 2};
 int x = 1;
 float y = 1.1;
 (&y)[1] = 0;
cout << x << "\n";
// stampo 0 e non 1 perchè il comando alla riga 12 prende l'indirizzo di y
// e si sposta in avanti della dimensione di un float finendo cosi sul
// indirizzo di x sovrascrivendo 0 al posto di 1
 cout<< "l'indirizzo di x è" <<&x<<endl;
 cout<<"l'indirzzo di y è" <<&y<<endl;


 return 0;
}