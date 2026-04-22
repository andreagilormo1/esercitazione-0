#include <iostream>
#include "randfiller.h"
#include <vector>
#include "my_sorts.hpp" 
#include <string> 
using namespace std;
int main()
{
   
   int n=100;
   randfiller gen;
   for(int i=0;i<100;i++){
       vector <int> vec (n);
       gen.fill(vec,-1000,1000);
       merge_sort(vec,0,n-1);
       if(issorted(vec)==0){
           return EXIT_FAILURE;
       }
       
       
       
       
       
       n=n+2*i;
    
       
   }
  
   // parte in cui verifico che funziona anche con le stringe 
   //stampando e vedendo se è ordinato (l'altra volta non l'ho letto quindi lo aggiungo ora)
   vector <string> nomi (13);
   nomi={"luca","andrea","alessandro","laura","francesco","gabriele",
   "lisa","giulia","aurora","riccardo","edoardo","federico","matteo"};
   merge_sort(nomi,0,12);
   for (int i=0;i<13;i++){
       cout<<nomi[i]<<endl;
   }
   return EXIT_SUCCESS;
   
   
   
   
}  