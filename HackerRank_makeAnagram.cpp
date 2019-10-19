#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int makeAnagram(string a, string b) {
    int alpaA[26];
    int alpaB[26];
    int answer = 0;
    memset(alpaA, 0, sizeof alpaA);
    memset(alpaB, 0, sizeof alpaB);

    for(auto temp : a){
        alpaA[int(temp)-97] += 1;
    }
    for(auto temp : b){
        alpaB[int(temp)-97] += 1;
    }

    int n = sizeof alpaA / sizeof alpaA[0];

    for (int i=0; i<n; i++){
        if(alpaA[i] == 0 && alpaB[i] == 0){
            continue;
        }
        else {
            answer += abs(alpaA[i] - alpaB[i]);
        }
    };

    return answer;
}

// Complete the makeAnagram function below.
int main(){
    string a = "abc";
    string b = "bcd";

    cout << makeAnagram(a, b) << "\n";

//    for (int alpabet : alpa) cout << alpabet << "\n";

    return 0;
}