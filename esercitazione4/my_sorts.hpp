#include <vector>

template<typename T>




bool issorted (const std::vector <T>& vec){
    if(vec.size()==0){
        return true;
    }
    for(int i=1;i<vec.size();i++){
        if (vec[i]<vec[i-1]){
            return false;
        }
        
        
    }
    return true;
    
}

template<typename T>
void bubble_sort (std::vector <T>& vec){
    int i=0,k=0 ;
    T au;
    for(i=0;i<vec.size()-1;i++){
        k=vec.size()-1;
        while(k>i){
            if(vec[k]<vec[k-1]){
                au=vec[k];
                vec[k]=vec[k-1];
                vec[k-1]=au;
                
            }
            k=k-1;
            
            
        }
    }
}



template<typename T>
void selection_sort (std::vector <T>& vec){
    int i=0,k=0,posmin ;
    T au;
    for(i=0;i<vec.size()-1;i++){
        posmin=i;
        for(k=i+1;k<vec.size();k++){
            if(vec[k]<vec[posmin]){
                posmin=k;
                
            }
        }
         au=vec[i];
         vec[i]=vec[posmin];
         vec[posmin]=au;
        
        
    }
}


template<typename T>
void insertion_sort (std::vector <T>& vec){
    int i=0,k=0;
    T chiave;
    
    for(k=1;k<vec.size();k++){
        chiave=vec[k];
        i=k-1;
        while(i>=0&& vec[i]>chiave){
            vec[i+1]=vec[i];
            i=i-1;
        }
         vec[i+1]=chiave;
        
        
    }
}

