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

template<typename T>
void merge(std::vector <T> & vec,int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int i=0,j=0,k=0;
    std:: vector <T> L (n1+1);
    std:: vector <T> R (n2+1);
    for ( i=0;i<n1;i++){
        L[i]=vec[i+p];
    }
    for ( j=0;j<n2;j++){
        R[j]=vec[j+q+1];
    }
    // cercato su internet questo if perchè dovevo capire come mettere inf
    if constexpr(std::is_same_v<T,std::string>){
     L[n1]="{";
    R[n2]="{";   
    }
    
    else{
    // metto numeri enormi al posto di infinito 1 miliardo in questo caso
    L[n1]=1000000000;
    R[n2]=1000000000;
    
    }
    i=0;
    j=0;
    for(k=p;k<=r;k++){
        if(L[i]<=R[j]){
            vec[k]=L[i];
            i=i+1;
            
        }
        else{
            vec[k]=R[j];
            j=j+1;
        }
    }
    
}



template<typename T>
void merge_sort(std::vector <T> & vec,int p,int r){
    
    
    
 int q;   


if(p<r){
    q=(p+r)/2;
    merge_sort(vec,p,q);
    merge_sort(vec,q+1,r);
    merge(vec,p,q,r);
    
}

}
template<typename T>
int partition(std::vector <T> & vec,int p,int r){
    T x=vec[r],au;
    int i=p-1;
    
    for(int j=p;j<=r-1;j++){
        if(vec[j]<=x){
            i=i+1;
            au=vec[j];
            vec[j]=vec[i];
            vec[i]=au;
            
        }
        
    }
    au=vec[r];
    vec[r]=vec[i+1];
    vec[i+1]=au;
    return i+1;
    

}

template<typename T>
void quick_sort(std::vector <T> & vec,int p,int r){
    int q;
    if(p<r){
        q=partition(vec,p,r);
        quick_sort(vec,p,q-1);
        quick_sort(vec,q+1,r);
        
    }
    
    
}

// mi sono leggermente aiutato con l'ia per sti ultimi 2 pezzi
template<typename T>
void insertion_sort_range(std::vector<T> &v, int p, int r) {
for (int i = p + 1; i <= r; i++) {
T key = v[i];
int j = i - 1;
while (j >= p && v[j] > key) {
v[j + 1] = v[j];
j--;
}
v[j + 1] = key;
}
}

template<typename T>
void quick_sort_hybrid(std::vector<T> &v, int p, int r) {
if (p < r) {
if ((r - p) <= 16) {
insertion_sort_range(v, p, r);
} else {
int q = partition(v, p, r);
quick_sort_hybrid(v, p, q - 1);
quick_sort_hybrid(v, q + 1, r);
}
}
}






