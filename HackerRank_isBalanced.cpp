#include <stack>
#include <iostream>
#include <string>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> tempStack;

    for (auto a : s){
        switch(a){
            case '{':
            case '[':
            case '(':
                tempStack.push(a);
                break;
            case '}':
                if (tempStack.empty() || (tempStack.top() != '{')){
                    return "NO";
                }
                tempStack.pop();
                break;
            case ']':
                if (tempStack.empty() || (tempStack.top() != '[')){
                    return "NO";
                }
                tempStack.pop();
                break;
            case ')':
                if (tempStack.empty() || (tempStack.top() != '(')){
                    return "NO";
                }
                tempStack.pop();
                break;
        }
    }

    return (tempStack.empty()?"YES":"NO");
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

//    fout.close();

    return 0;
}
