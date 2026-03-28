#include <iostream>
using namespace std;

template<typename I> requires std::integral<I>
 class rational {
 I num;
 I den;
 int con=1;
public:
rational(){
     num=0;
     den=1;
 }
 rational(I n, I d){
     num=n;
     den=d;
 }
 void controllo(){
     if (den==0){
         con=0;
         if(num==0){
             cout<<"nan"<<endl;
         }
         else{
             cout<<"inf"<<endl;
         }
     }
 }
 void semplifica(){
     if (con!=0){
         int mcd=1;
         if(num==0){
             den=1;
             
         }
         else{
             
         
         for(int k=1;k<=abs(num);k++){
             if(num%k==0 &&den%k==0){
                 mcd=k;
             }
         }
         num=num/mcd;
         den=den/mcd;
         } 
     }
 }
 I denominatore(){
     return den;
 }
 
 I numeratore (){
     return num;
 }
 
 // ausilio di intelizenza artificiale per i metodi sulle operazioni
 
rational somma(rational altro) {
if (con == 0 || altro.con == 0) {
I n = 0;
if ((num == 0 && den == 0) || (altro.num == 0 && altro.den == 0)) n = 0;
else n = num + altro.num;
rational ris(n, 0);
return ris;
}
I n = (num * altro.den) + (altro.num * den);
I d = den * altro.den;
rational ris(n, d);
ris.semplifica();
return ris;
}

rational sottrazione(rational altro) {
if (con == 0 || altro.con == 0) {
I n = 0;
if ((num == 0 && den == 0) || (altro.num == 0 && altro.den == 0)) n = 0;
else n = num - altro.num;
rational ris(n, 0);
return ris;
}
I n = (num * altro.den) - (altro.num * den);
I d = den * altro.den;
rational ris(n, d);
ris.semplifica();
return ris;
}

rational moltiplicazione(rational altro) {
if (con == 0 || altro.con == 0) {
I n = 0;
if ((num == 0 && den == 0) || (altro.num == 0 && altro.den == 0)) n = 0;
else n = num * altro.num;
rational ris(n, 0);
return ris;
}
I n = num * altro.num;
I d = den * altro.den;
rational ris(n, d);
ris.semplifica();
return ris;
}

rational divisione(rational altro) {
if (con == 0 || altro.con == 0) {
I n = 0;
if ((num == 0 && den == 0) || (altro.num == 0 && altro.den == 0)) n = 0;
else n = num * altro.den;
rational ris(n, 0);
return ris;
}
I n = num * altro.den;
I d = den * altro.num;
rational ris(n, d);
ris.semplifica();
return ris;
}




 
 
 };


int main (){
    int n,d,num,den;
    cout<<"inserire n"<<endl;
    cin>>n;
    cout<<"inserire d"<<endl;
    cin>>d;
    rational <int> oggetto(n,d);
    oggetto.controllo();
    oggetto.semplifica();
    cout<<"inserire n"<<endl;
    cin>>n;
    cout<<"inserire d"<<endl;
    cin>>d;
    rational <int> oggetto2(n,d);
    oggetto2.controllo();
    oggetto2.semplifica();
    
    // ausilio di inteligenza artificiale da qui
    rational<int> ris_somma = oggetto.somma(oggetto2);
cout << "Somma: ";
if (ris_somma.denominatore() == 0){
    
 ris_somma.controllo();}
else{ cout << ris_somma.numeratore() << "/" << ris_somma.denominatore() << endl;}

rational<int> ris_sott = oggetto.sottrazione(oggetto2);
cout << "Sottrazione: ";
if (ris_sott.denominatore() == 0){ ris_sott.controllo();}
else{ cout << ris_sott.numeratore() << "/" << ris_sott.denominatore() << endl;}

rational<int> ris_molt = oggetto.moltiplicazione(oggetto2);
cout << "Moltiplicazione: ";
if(ris_molt.denominatore() == 0) {ris_molt.controllo();}
else { cout << ris_molt.numeratore() << "/" << ris_molt.denominatore() << endl;}

rational<int> ris_div = oggetto.divisione(oggetto2);
cout << "Divisione: ";
if (ris_div.denominatore() == 0){ris_div.controllo();}
else {cout << ris_div.numeratore() << "/" << ris_div.denominatore() << endl;}



    

    
    
    return 0;
}