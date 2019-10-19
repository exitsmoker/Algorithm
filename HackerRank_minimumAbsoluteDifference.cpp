#include <cstdlib>
#include <algorithm>

int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min;

    for (int i=0; i<arr.size(); i++){
        int tempMin = abs(arr[i] - arr[i+1]);
        if (i == 0){
            min = tempMin;
        }
        else {
            if (min >= tempMin){
                min = tempMin;
            }
        }
    }

    return min;
}
