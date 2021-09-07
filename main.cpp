#include <iostream>
#define MAX 30
using namespace std;

int sortBubble1(int niz[], int n){      //vraca broj poreednjenja
    int poredjenja = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            poredjenja++;
            if(niz[j] > niz[j+1]){
                int pom = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = pom;
            }
        }
    }
    return poredjenja;
}

int sortBubble2(int niz[], int n){
    int poredjenja = 0;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            poredjenja++;
            if(niz[j] > niz[j+1]){
                int pom = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = pom;
            }
        }
    }
    return poredjenja;
}
void popuniNiz(int niz[], int *n){
    cout << "Popunite niz/n n=?" << endl;
    cin >> (*n);
    for(int i = 0; i < (*n); i++){
        cout << "Niz[" << i << "] = ?" ;
        cin >> niz[i];
    }
}
void ispisNiza(int niz[], int n){
    for(int i = 0; i < n; i++){
        cout << "Niz[" << i << "] = " << niz[i] << endl;
    }
}

void kopirajNiz(int niz[], int niz1[], int n){
    for(int i = 0; i < n; i++){
        niz1[i] =niz[i];
    }
}

int main() {
    int niz[30], niz1[30];
    int n;
    int bubble1;
    int bubble2;
    popuniNiz(niz, &n);      // niz == &niz[0]
    kopirajNiz(niz, niz1,n);
    bubble1 = sortBubble1(niz, n);
    bubble2 = sortBubble2(niz1, n);
    ispisNiza(niz, n);
    cout << "Broj poredjenja bubble1  = " << bubble1 << " a bubble2 je = " <<bubble2;
    return 0;
}
