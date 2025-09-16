#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <map>

using namespace std;

string sizes[6] = {"XS","S", "M", "L", "XL", "XXL"};

vector<pair<string, string>> volunteers;
map<string, int> shirt_count; 

bool alg(int index, bool pos){
    if(index < 0){
        return true;
    }
    if(pos){
        if(shirt_count[volunteers[index].first] > 0){
            shirt_count[volunteers[index].first]--;
        }
    } else if(!pos){
        if(shirt_count[volunteers[index].second] > 0){
            shirt_count[volunteers[index].second]--;
        }
    }
    else{
        return false;
    }
    bool left = alg(index - 1, true);
    shirt_count[volunteers[index].first]++;
    bool right = alg(index - 1, false);
    shirt_count[volunteers[index].second]++;
    if(left || right){
        return true;
    }
}

int main(){
    int shirts;
    int volunteer;
    cin >> shirts >> volunteer;
    for(int i = 0; i < volunteer; i++){
        string fsize;
        string ssize;
        cin >> fsize >> ssize;
        volunteers.push_back(make_pair(fsize, ssize));
    }
    int shirt_per_size = shirts / 6;
    cout << shirt_per_size << endl;
    for(int i = 0; i < 6; i++){
        shirt_count[sizes[i]] = shirt_per_size;
    }

    bool result = alg(volunteer - 1, true) || alg(volunteer - 1, false);
    if(result){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

    return 0;
}