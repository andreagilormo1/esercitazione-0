#include <iostream>
#include "randfiller.h"
#include <vector>
#include "my_sorts.hpp" 
using namespace std;
int main()
{
   
   int n=100;
   randfiller gen;
   for(int i=0;i<100;i++){
       vector <int> vec (n);
       gen.fill(vec,-1000,1000);
       selection_sort(vec);
       if(issorted(vec)==0){
           return EXIT_FAILURE;
       }
       
       
       
       
       
       n=n+2*i;
    
       
   }
   return EXIT_SUCCESS;
}