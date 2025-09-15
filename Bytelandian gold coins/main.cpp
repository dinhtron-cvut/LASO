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
        queue<int> temp_coins = coins;
        int current = coins.front();
        for(int i = 0; i < 3; i++){
            int new_coin = current / division[i];
            if(small_coins.find(new_coin) == small_coins.end()){
                coins.push(new_coin);
                small_coins.insert(new_coin);
            }
        }
        while(!temp_coins.empty()){
            temp += temp_coins.front();
            temp_coins.pop();
        }
        if(temp > max_sum){
            max_sum = temp;
        }
        coins.pop();
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

