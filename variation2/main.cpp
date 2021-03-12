#include <iostream>

using namespace std;

const int MaxN=100;
typedef int Count[MaxN+1];
typedef int Table[MaxN+1][MaxN+1];
typedef int Solution[MaxN+1];


void Jobs(int N,Count D, Table E,bool &Exist,Solution X);
void LookingForGoodElement(int N, int i,Count D,Table E,Solution X,bool &Exist,int &j);
bool isBad(int i, int j, Table E,Solution X);

int main() {
    int N;
    Count D;
    Table E;
    bool Exist;
    Solution X;

    cout << "N=? :";
    cin >> N;
    for (int i=1;i<=N;i++) {
        cout << "Count of " << i << ". applicant's jobs? :";
        cin >> D[i];
        for (int j=1;j<=D[i];j++) {
            cout << "Which is the "<< j << ". job of " << i << ". applicant? :";
            cin >> E[i][j];
        }
    }
    Jobs(N,D,E,Exist,X);
    if (Exist) {
        for (int i=1;i<=N;i++) {
            cout << "Job for " << i << ". applicant is: " << X[i] << endl;
        }
    } else {
        cout << "Jobs cannot be done." << endl;
    }

}

void Jobs(int N,Count D, Table E,bool &Exist,Solution X){
    int i=1;
    for (int j=1;j<=N;j++) { X[j]=0; }
    while ((i>=1) && (i<=N)) {
        int j;
        LookingForGoodElement(N, i,D,E,X,Exist,j);
        if (Exist) {
            X[i]=j;
            i++;
        } else {
            X[i]=0;
            i--;
        }
    }
    Exist=(i>N);
    if (Exist) {
        for (int i=1;i<=N;i++) {
            X[i]=E[i][X[i]];
        }
    }
}

void LookingForGoodElement(int N, int i,Count D,Table E,Solution X,bool &Exist,int &j){
    j=X[i]+1;
    while ((j<=D[i]) && isBad(i,j,E,X)) {
        j++;
    }
    Exist=(j<=D[i]);
}

bool isBad(int i, int j, Table E,Solution X){
    int k=1;
    while ((k<i) && (E[k][X[k]]!=E[i][j])) {
        k++;
    }
    return (k<i);
}
