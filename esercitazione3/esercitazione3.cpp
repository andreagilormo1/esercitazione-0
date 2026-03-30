#include <iostream>
#include <concepts>

using namespace std;

template<typename I> requires std::integral<I>
// 0/0= nan num/0=inf
// da qui fino al avviso scritto senza uso del ia
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
}
else {
con=1;
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
if(num%k==0 && den%k==0){
mcd=k;
}
}
num=num/mcd;
den=den/mcd;
}
}
}
I denominatore() const {
return den;
}

I numeratore () const {
return num;
}

// ausilio di intelizenza artificiale per i metodi sulle operazioni

rational& operator+=(const rational& altro) {
if (con == 0 || altro.con == 0) {
if ((num == 0 && den == 0) || (altro.num == 0 && altro.den == 0)) {
num = 0;
}
else {
num = num + altro.num;
}
den = 0;
con = 0;
return *this;
}
num = (num * altro.den) + (altro.num * den);
den = den * altro.den;
semplifica();
return *this;
}

rational& operator-=(const rational& altro) {
if (con == 0 || altro.con == 0) {
if ((num == 0 && den == 0) || (altro.num == 0 && altro.den == 0)) {
num = 0;
}
else {
num = num - altro.num;
}
den = 0;
con = 0;
return *this;
}
num = (num * altro.den) - (altro.num * den);
den = den * altro.den;
semplifica();
return *this;
}

rational& operator*=(const rational& altro) {
if (con == 0 || altro.con == 0) {
num = num * altro.num;
den = 0;
con = 0;
}
else {
num = num * altro.num;
den = den * altro.den;
semplifica();
}
return *this;
}

rational& operator/=(const rational& altro) {
if (con == 0 || altro.con == 0) {
num = num * altro.den;
den = 0;
con = 0;
}
else {
num = num * altro.den;
den = den * altro.num;
semplifica();
controllo();
}
return *this;
}

rational operator+(const rational& altro) const {
rational ris = *this;
ris += altro;
return ris;
}

rational operator-(const rational& altro) const {
rational ris = *this;
ris -= altro;
return ris;
}

rational operator*(const rational& altro) const {
rational ris = *this;
ris *= altro;
return ris;
}

rational operator/(const rational& altro) const {
rational ris = *this;
ris /= altro;
return ris;
}

};
// uso ia per questo metodo
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
if (r.denominatore() == 0) {
if (r.numeratore() == 0) {
os << "nan";
}
else {
os << "inf";
}
}
else {
os << r.numeratore() << "/" << r.denominatore();
}
return os;
}

// scritto tutto da me
int main (){
int n,d;
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

cout << "Somma: " << oggetto + oggetto2 << endl;
cout << "Sottrazione: " << oggetto - oggetto2 << endl;
cout << "Moltiplicazione: " << oggetto * oggetto2 << endl;
cout << "Divisione: " << oggetto / oggetto2 << endl;

return 0;
}

