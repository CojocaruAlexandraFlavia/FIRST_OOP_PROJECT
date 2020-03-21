#include <iostream>
#include <fstream>

class Vector {
    int *v;
    int n;
public:
    Vector (int x, int n );
    Vector (Vector &t);
    Vector (int *w, int m);
    Vector() {
        n=0;
        v=new int[n];
    }
    ~Vector();
    int Suma_vector(Vector);
    int* Maxim_poz();
    void Sortare();
    void Reactualizare(int, int );
    int getNrElemente() const;
    int getElement(int )const;
    void setElement(int, int);
    double operator * (Vector& );
    Vector& operator = (const Vector&);
    friend std::ostream& operator << (std::ostream&, const Vector&);
    friend std::istream& operator >> (std::istream&, Vector&);

};

Vector::Vector(int x, int n) {
    this->n=n;
    this->v=new int[n];
    for (int i=0; i<n; i++)
        this->v[i]=x;
}

Vector::Vector(Vector& t) {
    this->n=t.n;
    this->v=new int[n];
    for (int i=0; i<n; i++)
        this->v[i]=t.v[i];
}

Vector :: Vector(int *w, int m) {
    this->n=m;
    this->v=new int[n];
    for (int i=0; i<n; i++)
        this->v[i]=w[i];
}

Vector::~Vector() {
    delete[] v;
}

int Vector::Suma_vector(Vector v ) {
    int suma=0;
    for (int i=0; i<v.getNrElemente(); i++)
        suma+=v.getElement(i);
    return suma;
}

int* Vector:: Maxim_poz() {
    static int r[2];
    int poz=0, maxim=v[0];
    for (int i=1; i<n; i++)
        if (v[i]>maxim) {
            maxim=v[i];
            poz=i;
        }
    r[0]=maxim;
    r[1]=poz;
    return r;
}

void Vector::Sortare() {
    int aux;
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (v[j]<v[i]) {
                aux=v[j];
                v[j]=v[i];
                v[i]=aux;
            }
}

void Vector::Reactualizare(int n, int x) {
    this->n = n;
    this->v = new int [n];
    for (int i=0; i<n; i++)
        this->v[i]=x;
}

int Vector::getNrElemente() const {
    return this->n;
}
void Vector:: setElement(int i, int x) {
    this->v[i]=x;
}
int Vector::getElement (int i) const {
    return this->v[i];
}

double Vector:: operator * (Vector& v1) {
    double p=0;
    for(int i=0; i<v1.getNrElemente(); i++)
        p+= v1.getElement(i) * (this->v[i]);
    return p;
};

Vector& Vector:: operator = (const Vector& w) {
    if (this != &w) {
        delete [] v;
        v = new int[n];
        for (int i = 0; i < n; i++)
            v[i] = w.v[i];
        return *this;
    } else
        return *this;
}
std::istream& operator >> (std::istream& in, Vector& v) {
    int m,x;
    in>>m;
    v.n=m;
    for (int i=0; i<m; i++) {
        in>>x;
        v.setElement(i,x);
    }
    return in;
}
std::ostream& operator << (std::ostream& out, const Vector& v) {
    for (int i=0; i<v.getNrElemente(); i++)
        out<<v.getElement(i)<<' ';
    return out;
}

int main() {
    //Vector b;
    //std::cin>>b;
    //std::cout<<"Elementele vectorului b sunt: "<<b<<std::endl;
    int x=3;
    int z[]= {3, 6, 1, -1, 4};
    Vector w(z, 5);
    Vector t(x, 5);
    Vector a(t);
    std::cout<<"Elementele vectorului a sunt: "<<a<<'\n';
    std::cout<<"Elementele vectorului w sunt: "<<w<<'\n';
    std::cout<<"Elementele vectorului t sunt: "<<t<<'\n';
    std::cout<<"Suma elementelor vectorului w este: "<<w.Suma_vector(w)<<'\n';
    int* r=w.Maxim_poz();
    std::cout<<"Maximul vectorului w este "<<r[0]<<" aflat pe pozitia "<<r[1]<<'\n';
    std::cout<<"Produsul scalar al vectorilor w si t este: "<<w*t<<'\n';
    w.Sortare();
    std::cout<<"Vectorul w sortat este: "<<w<<'\n';
    t.Reactualizare(4, 0);
    std::cout<<"Elementele vectorului t dupa actualizare sunt: "<<t<<'\n';
    return 0;
}
