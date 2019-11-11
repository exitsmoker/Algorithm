#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmpString(string a, string b){
    if(a.size() != b.size()){
        return false;
    }
    else {
        for(int i = 0; i < a.size(); i++){
            if(b[i] != '*'){
                if(a[i] != b[i]){
                    return false;
                    break;
                }
            }
        }
    }
    return true;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    vector<int> per;
    int answer = 0;

    for (int i = 0; i < banned_id.size(); i++){
        per.push_back(i+1);
    }
    for (int i = 0; i < user_id.size() - banned_id.size(); i++){
        per.push_back(0);
    }
    do {
        bool tempCheck = true;

        for (int i = 0; i < per.size(); i++){
            if(per[i] > 0){
                if(!cmpString(user_id[i], banned_id[per[i]-1])){
                    tempCheck = false;
                    break;
                }
            }
        }

        if(tempCheck){
            answer++;
        }
    }while(next_permutation(per.begin(), per.end()));

    return answer;
}