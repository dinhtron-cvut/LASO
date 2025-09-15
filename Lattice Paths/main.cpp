#include <iostream>
#include <vector>
using namespace std;

void alg(long long int n, long long int m){
    vector<vector<long long int>> grid;
    for(int i = 0; i < n; i++){
        vector<long long int> row;
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0){
                row.push_back(1);
            } else {
                row.push_back(grid[i-1][j] + row[j-1]);
            }
        }
        grid.push_back(row);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    long long int n;
    long long int m;
    cin >> n >> m;
    alg(n, m);
    return 0;

}