#include <iostream>

using namespace std;

const int MaxN=100;
typedef int Table[MaxN+1][MaxN+1];
typedef int Solution[MaxN+1];


void Jobs(int N,int S,Table F,bool &Exist,Solution Y);
void LookingForGoodElement(int N, int i,Table F,Solution Y,bool &Exist,int &j);
bool isBad(int i, int j, Solution Y);
int Cost(int i, int j, Table F, Solution Y);

int main() {
    int N;
    int S;
    Table F;
    bool Exist;
    Solution Y;

    cout << "N=? :";
    cin >> N;
    cout << "S=? :";
    cin >> S;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cout << "Can " << i << ". applicant do the " << j << ". job? :";
            cin >> F[i][j];
        }
    }
    Jobs(N,S,F,Exist,Y);
    if (Exist) {
        for (int i=1;i<=N;i++) {
            cout << "Job for " << i << ". applicant is: " << Y[i] << endl;
        }
    } else {
        cout << "Jobs cannot be done." << endl;
    }

}

void Jobs(int N,int S,Table F,bool &Exist,Solution Y){
    int i=1;
    for (int j=1;j<=N;j++) { Y[j]=0; }
    while ((i>=1) && (i<=N)) {
        int j;
        LookingForGoodElement(N,i,F,Y,Exist,j);
        if (Exist && (Cost(i,j,F,Y)<=S)) {
            Y[i]=j;
            i++;
        } else {
            Y[i]=0;
            i--;
        }
    }
    Exist=(i>N);
}

void LookingForGoodElement(int N, int i,Table F,Solution Y,bool &Exist,int &j){
    j=Y[i]+1;
    while ((j<=N) && (isBad(i,j,Y) || (F[i][j]==0))) {
        j++;
    }
    Exist=(j<=N);
}

bool isBad(int i, int j, Solution Y){
    int k=1;
    while ((k<i) && (Y[k]!=j)) {
        k++;
    }
  return (k<i);
}

int Cost(int i, int j, Table F, Solution Y) {
    int s=0;
    for (int k=1;k<=i-1;k++){
        cerr << s << " ";
        s=s+F[k][Y[k]];
    }
    cerr << s << " ";
    s=s+F[i][j];
    cerr << "s("<<i<<","<<j<<")=" << s << endl;
    return s;
}
