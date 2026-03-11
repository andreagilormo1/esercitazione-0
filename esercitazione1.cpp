#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc,const char*argv[])
{
    if(argc<2){
        cerr<<"c'e stato un errore"<<endl;
        return 1;
    }
    
    
    string nomefile=argv[1];
    
    
    ifstream file1(nomefile);
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
            cout<<"la temperatura media di "<<citta<<" e "<<+media<<endl;
            
            
            
        }
    }
else{
		cerr<<"c'e stato un errore"<<endl;
        return 1;
	}

}

