#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
using namespace std;

class gradiente_coniugato{
     
    Eigen::MatrixXd A;
    Eigen::VectorXd b;
    Eigen::VectorXd r;
    Eigen::VectorXd p;
    
    double tol;
    
    
    public:
    
    gradiente_coniugato(Eigen::MatrixXd B,Eigen::VectorXd vettore,
    double tollerenza){
      A=B;
      b=vettore;
      tol=tollerenza;
      
      // faccio un piccolo controllo per vedere se è simmetrica
      if(!A.isApprox(A.transpose())){
        cout<<"c'è un errore poichè non è simmetrica"<<endl;
        exit(1);


      }
      // volendo se si vuole essere rigorosi potrei
      // verificare anche la condizione di essere semipositiva
     
    }
    Eigen::VectorXd conti(){
    int n = b.size();// prendo la dimensione del vettore
    int cont=0;
    Eigen::VectorXd x=Eigen::VectorXd::Zero(n);
    Eigen::VectorXd r0=b-A*x;
    Eigen::VectorXd p0=r0;
    double alfa;
    double beta;
    double norma=r0.norm();
    while (norma>abs(tol)){
        cont=cont+1;
     alfa=((p0.transpose()*r0)/(p0.transpose()*A*p0)).value();
     x=x+alfa*p0;
     r0=b-A*x;
     norma=r0.norm();
     
     beta=((p0.transpose()*A*r0)/(p0.transpose()*A*p0)).value();
     p0=r0-beta*p0;

    };
    cout<<"il numero di cicli è "<<+cont<<endl;

    return x;

    }
    
    
};

int main() {
    
    unsigned int n = 50;
    double tolleranza =1.0e-11;

    
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n) * 5.0; 
    
    // in questo modo avro A positiva e simmetrica
    // infatti nel costruttore potrei evitare di mettere il 
    // controllo della simmetria con questo test visto che è 
    // ridondante, motivo per cui ho evitato di verificare 
    // la semipositivita
    Eigen::MatrixXd A = B.transpose() * B; 


    Eigen::VectorXd b = Eigen::VectorXd::Random(n) * 10.0; 

    // dal corso di algebra lineare del prof malaspina so che è 
    // invertibile se il det non è 0 (nel computer vedo anche che
    //  non sia vicino)
    if (abs(A.determinant()) < 1.0e-11) {
        cout << " La matrice A non è invertibile!"<<endl;
        return -1;
    }

    
    cout <<"Matrice A" <<"\n"<< A  << endl;
    cout << "Vettore b " <<"\n"<< b << endl;

    
    gradiente_coniugato oggetto(A, b, tolleranza); 
    
    Eigen::VectorXd x = oggetto.conti(); 

    
    cout << "la soluzione è " <<"\n"<< x << endl;

    return 0;
}