#include <iostream>

using namespace std;

const int MaxN=100;
const int MAX_COST=999999;
typedef int Table[MaxN+1][MaxN+1];
typedef int Solution[MaxN+1];


void BestJob(int i, int cost, const int &N,Table F,int &maxCost,Solution Y, Solution X);
bool Occured(int i, int j, Solution Y);

int main() {
    int N;
    Table F;
    Solution Y;
    Solution X;
    int maxCost=MAX_COST;

    cout << "N=? :";
    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cout << "Can " << i << ". applicant do the " << j << ". job? :";
            cin >> F[i][j];
        }
    }
    BestJob(1,0,N,F,maxCost,Y,X);
    if (maxCost<MAX_COST) {
        for (int i=1;i<=N;i++) {
            cout << "Job for " << i << ". applicant is: " << Y[i] << endl;
        }
    } else {
        cout << "Jobs cannot be done." << endl;
    }

}

void BestJob(int i, int cost, const int &N,Table F,int &maxCost,Solution Y, Solution X){
    if (i>N) {
        if (cost<maxCost) {
            for (int j=1;j<=N;j++) { Y[j]=X[j]; }
            maxCost=cost;
        }
    } else {
        for (int j=1;j<=N;j++) {
            if (!Occured(i,j,X) && (F[i][j]>0) && (cost+F[i][j]<maxCost)) {
                X[i]=j;
                BestJob(i+1,cost+F[i][j],N,F,maxCost,Y,X);
            }
        }
    }
}

bool Occured(int i, int j, Solution Y){
    int k=1;
    while ((k<i) && (Y[k]!=j)) {
        k++;
    }
  return (k<i);
}
