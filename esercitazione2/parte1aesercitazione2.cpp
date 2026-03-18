# include <iostream>
using namespace std;

// questo programma lo uso per stampare gli indirizzi del vettori
 int main()
 {
double ad[4] = {0.0, 1.1, 2.2, 3.3};
float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
int ai[3] = {0, 1, 2};
double* puntatore1;
float* puntatore2;
int* puntatore3;
 int x = 1,i=0;
 float y = 1.1;
puntatore1=&ad[0];
puntatore2=&af[0];
puntatore3=&ai[0];
 (&y)[1] = 0;

 cout << x << "\n";
 
 for(i=0;i<4;i++){
	cout<<"l'indirizzo in posizione "<<+i <<"del vettore ad è" <<(puntatore1+i)<<endl;
	 
 }
 for(i=0;i<8;i++){
	cout<<"l'indirizzo in posizione "<<+i <<"del vettore af è" <<(puntatore2+i)<<endl;
	 
 }
 
 for(i=0;i<3;i++){
	cout<<"l'indirizzo in posizione "<<+i <<"del vettore ai è"<<(puntatore3+i)<<endl;
	 
 }

 return 0;
}