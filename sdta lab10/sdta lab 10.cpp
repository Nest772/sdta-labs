#include <iostream>
using namespace std;

const int N = 6;


int adj[N][N] = {
    {0, 0, 2, 0, 8, 0},
    {0, 0, 6, 4, 0, 0},
    {2, 6, 0, 0, 0, 9},
    {0, 4, 0, 0, 4, 0},
    {8, 0, 0, 4, 0, 0},
    {0, 0, 9, 0, 0, 0}
};


void printMatrix() {
    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cout << adj[i][j] << "\t";
        cout << endl;
    }
}


void isComplete() {
    bool complete = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i != j && adj[i][j] == 0)
                complete = false;
        }
    }
    if(complete) cout << "Graph is complete\n";
    else cout << "graph is incomplete\n";
}


void makeAdjacencyList() {
    cout << "\nAdjacency list:\n";
    for(int i = 0; i < N; i++) {
        cout << i+1 << ": ";
        for(int j = 0; j < N; j++) {
            if(adj[i][j] != 0)
                cout << j+1 << "(" << adj[i][j] << ") ";
        }
        cout << endl;
    }
}


void countAverageDistance() {
    int sum = 0, count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(adj[i][j] != 0) {
                sum += adj[i][j];
                count++;
            }
        }
    }
    cout << "\nAverage length: " << (double)sum / count << endl;
}


void findIsolatedVertices() {
    int count = 0;
    cout << "\nIsolated peak:\n";
    for(int i = 0; i < N; i++) {
        int degree = 0;
        int lastWeight = 0;

        for(int j = 0; j < N; j++) {
            if(adj[i][j] != 0) {
                degree++;
                lastWeight = adj[i][j];
            }
        }

        if(degree == 1) {
            cout << "Peak " << i+1 
                 << ", distance = " << lastWeight << endl;
            count++;
        }
    }
    cout << "number: " << count << endl;
}


void findMaxPath3() {
    int maxSum = 0;
    int a=0,b=0,c=0;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                if(adj[i][j] && adj[j][k] && i!=k) {
                    int sum = adj[i][j] + adj[j][k];
                    if(sum > maxSum) {
                        maxSum = sum;
                        a=i; b=j; c=k;
                    }
                }
            }
        }
    }

    cout << "\nMaximum path:\n";
    cout << "(" << a+1 << ") -- " << adj[a][b]
         << " -- (" << b+1 << ") -- " << adj[b][c]
         << " -- (" << c+1 << ")\n";
}


bool visited[N];

void dfs(int v) {
    visited[v] = true;
    for(int i=0;i<N;i++) {
        if(adj[v][i] && !visited[i])
            dfs(i);
    }
}

void isConnected() {
    for(int i=0;i<N;i++) visited[i]=false;

    dfs(0);

    bool connected = true;
    for(int i=0;i<N;i++)
        if(!visited[i]) connected = false;

    if(connected)
        cout << "\ncan go around all peaks\n";
    else
        cout << "\ncant go around all peak\n";
}

int main() {
    printMatrix();
    isComplete();
    makeAdjacencyList();
    countAverageDistance();
    findIsolatedVertices();
    findMaxPath3();
    isConnected();

    return 0;
}