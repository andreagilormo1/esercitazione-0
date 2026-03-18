#include <iostream>
#include <cmath>
using namespace std;

 int main()
 {
     const int N=10;
     double vettore [N]={10.7,3.5,4.6,7.5,1.2,8.9,45.6,0.2,4.3,2.4};
     double min,max,media,varianza,somma=0,sommaquadrati=0,ds;
     min=vettore[0];
     max=vettore[0];
     for(int i=0;i<N;i++){
         if (min>vettore[i]){
             min=vettore[i];
         }
         if(max<vettore[i]){
             max=vettore[i];
         }
         somma=somma+vettore[i];
         sommaquadrati=sommaquadrati+vettore[i]*vettore[i];
         
     }
     media=somma/N;
     varianza=sommaquadrati/N- media*media;
     ds=sqrt(varianza);
     cout<<"il min è "<<+min<<endl;
     cout<<"il max è "<<+max<<endl;
     cout<<"la media è "<<+media<<endl;
     cout<<"il deviazione standard è "<<+ds<<endl;
         
     
     
     
return 0;
}