#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long countAvailableRoomNumber(long long tempInt, long long* check){
    int result;
    cout << sizeof(check) << "\n";
    for(int i = tempInt; i < (sizeof(check) / sizeof(long long)); i++){
        if(check[i] == 0){
            check[i] = i+1;
            check[tempInt] = i+1;
            result = i;
            break;
        }
    }
    return result;
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    long long check[k];
    memset(check, 0, sizeof(check));

    for(int i = 0; i < room_number.size(); i++){
        int tempInt = room_number[i];
        if(check[tempInt] == 0){
            answer.push_back(tempInt);
            check[tempInt] = tempInt + 1;
        }
        else {
            answer.push_back(countAvailableRoomNumber(check[tempInt], check));
        }
    }
    return answer;
}

int main(){
    vector<long long> tempArgs;
    tempArgs.push_back(1);
    tempArgs.push_back(3);
    tempArgs.push_back(4);
    tempArgs.push_back(1);
    tempArgs.push_back(3);
    tempArgs.push_back(1);

    vector<long long> temp = solution(10, tempArgs);
    for (int i = 0; i < temp.size(); i++){
        cout << temp[i] << " ";
    }
    return 0;
}