#include <iostream>
#define MAX 30
using namespace std;

int  sortSelection(int niz[], int n);
int swap(int *, int *);
int sortBubble1(int niz[], int n);
int sortBubble2(int niz[], int n);
void popuniNiz(int niz[], int *n);
void ispisNiza(int niz[], int n);
void kopirajNiz(int niz[], int niz1[], int n);
bool sortiranOpadajuce(int niz[], int n);
int insertionSort(int niz[], int n);
void quickSort(int niz[], int n);
int podeli(int, int, int[]);
void quickSortHelp(int [], int , int );

int main() {
    int niz[30], niz1[30], niz2[30];
    int n;
    int bubble2;
    popuniNiz(niz, &n);      // niz == &niz[0]
    //bool sortiran = sortiranOpadajuce(niz, n);
  //  kopirajNiz(niz, niz1,n);
    //kopirajNiz(niz, niz2,n);
/*
    bubble2 = sortBubble2(niz, n);
    int insertion = insertionSort(niz1, n);
int selection = sortSelection(niz2, n);*/
    quickSort(niz, n);
    ispisNiza(niz, n);

//    if(sortiran){
//        cout<< "Niz je sortiran";
//    }else{
//        cout<< "niz nije sortiran";
//    }
   // cout << "Broj poredjenja bubble2  = " << bubble2 << " , insertion je = " <<insertion <<" , selection je = " <<selection;
    return 0;
}
int swap(int *a, int *b){
    int pom = *a;
    *a =  *b;
    *b = pom;
}
int  sortSelection(int niz[], int n){
    int poredjenje=0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++) {
            poredjenje++;
            if (niz[i] > niz[j]) {
                swap(&niz[i], &niz[j]);
            }
        }
    }
    return poredjenje;
}

int sortBubble1(int niz[], int n){      //vraca broj poreednjenja
    int poredjenja = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            poredjenja++;
            if(niz[j] > niz[j+1]){
                swap(&niz[j], &niz[j+1]);
            }
        }
    }
    return poredjenja;
}

int sortBubble2(int niz[], int n){
    int poredjenja = 0;
    bool biloZamene = false;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            poredjenja++;
            if(niz[j] > niz[j+1]){
                biloZamene = true;
                swap(&niz[i], &niz[j+1]);
            }
        }
        if(!biloZamene){
            break;
        }
    }
    return poredjenja;
}


int insertionSort(int niz[], int n){
    int poredjenja = 0;
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            poredjenja++;
            if(niz[j - 1] < niz[j]){
                break;
            }
            swap(&niz[j-1], &niz[j]);
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

bool sortiranOpadajuce(int niz[], int n){
    for(int i = 0; i < n-1; i++){
        if(niz[i]>niz[i+1]){
            return false;
        }
    }
    return true;
}

void quickSort(int niz[], int n){
    quickSortHelp(niz, 0, n-1);
}
void quickSortHelp(int niz[], int an1, int an2){
    if( an1 >= an2){
        return;
    }
    if( an1 + 1 == an2){
        if(niz[an1] > niz[an2]){
            swap(&niz[an1], &niz[an2]);
            return;
        }
    }
    int sredina = podeli(an1, an2, niz);
    quickSortHelp(niz, an1, sredina - 1);
    quickSortHelp(niz, sredina + 1, an2);
}
int podeli(int an1, int an2, int niz[]){
    int j = an1;
    int i = j + 1;
    for(; i < an2; i++){
        if(niz[i] > niz[an1]){
            continue;
        }
        j++;
        swap(&niz[i], &niz[j]);
    }
    swap(&niz[j], &niz[an1]);
    return j;
}
