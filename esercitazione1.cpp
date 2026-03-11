#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream file1("testoes1.txt");
    if (file1.is_open()){
        double media, somma=0;// ci sono 4 misure per citta non serve il cont
        string citta="";
        double valore=0;
        while(file1>>citta){
            for (int i=0;i<4;i++){
            file1>>valore;
            somma = somma+  valore;
            }
            media=somma/4;
            somma=0;
            cout<<"la temperatura media di "<<citta<<" è "<<+media<<endl;
            
            
            
        }
    }
   
}