// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> split_string(string);
int answer = 0;

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    const int tempN = arr.size();
    int maxArr[tempN];
    int currentMaxArr = 0;

    for (int i=0; i<arr.size(); i++){
        if (i >= 2){
            int tempMax = maxArr[i-2] + arr[i];
            if(tempMax >= arr[i] && tempMax >= currentMaxArr){
                maxArr[i] = tempMax;
                currentMaxArr = tempMax;
            }
            if(arr[i] >= tempMax && arr[i] >= currentMaxArr){
                maxArr[i] = arr[i];
                currentMaxArr = arr[i];
            }
            if(currentMaxArr >= arr[i] && currentMaxArr >= tempMax) {
                maxArr[i] = currentMaxArr;
            }
        }
        else if (i == 0){
            maxArr[i] = arr[i];
            currentMaxArr = arr[i];
        }
        else if (i == 1){
            if (currentMaxArr > arr[i]){
                maxArr[i] = currentMaxArr;
            }  
            else {
                maxArr[i] = arr[i];
                currentMaxArr = arr[i];
            }
        }
    }
    
    answer = currentMaxArr;
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
