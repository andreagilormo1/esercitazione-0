/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int righe,colonne,i,k,inversa;
    srand(time(0));
    cout<<"numero righe"<<endl;
    cin>>righe;
    cout<<"numero colonne"<<endl;
    cin>>colonne;
    int matrice[righe][colonne];
    for(i=0;i<righe;i++){
        for(k=0;k<colonne;k++){
            
        
        matrice[i][k]=rand()%30;
        }
    }
    for(i=0;i<righe;i++){
        for(k=0;k<colonne;k++){
            
        
        cout<<matrice[i][k]<<" ";
        
        }
        cout<<""<<endl;
    }
   do{
       cout<<"che colonna vuoi inversa"<<endl;
       cin>>inversa;
       
   }while (inversa>=colonne || inversa<0);

    
     int vettore [righe];
     for (i =0;i<righe;i++){
         vettore[i]=matrice[righe-i-1][inversa];
     }
     for (i =0;i<righe;i++){
         matrice[i][inversa]=vettore[i];
     }
     
    
     for(i=0;i<righe;i++){
        for(k=0;k<colonne;k++){
            
        
        cout<<matrice[i][k]<<" ";
        
        }
        cout<<""<<endl;
    }
    
     
     
     return 0;
     
     
}
