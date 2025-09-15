#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

queue<int> coins;
int max_sum = 0;
set<int> small_coins = {0, 1, 2};
vector<int> division = {2, 3, 4};

void alg(int coin){
    while(!coins.empty()){
        int temp = 0;
        int current = coins.front();
        for(int i = 0; i < 3; i++){
            int new_coin = current / division[i];
            if(new_coin != 0){
                coins.push(new_coin);
            }
        }
        coins.pop();
        queue<int> temp_coins = coins;
        while(!temp_coins.empty()){
            cout << temp_coins.front() << " ";
            temp += temp_coins.front();
            temp_coins.pop();
        }
        cout << endl;
        if(temp > max_sum){
            max_sum = temp;
        }
    }
    cout << max_sum << endl;
    return;
}



int main() {
    int coin;
    cin >> coin;
    coins.push(coin);
    alg(coin);
    return 0;
}

