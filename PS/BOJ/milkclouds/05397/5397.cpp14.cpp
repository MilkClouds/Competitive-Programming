#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string str, left;
        stack <char> right;
        cin >> str;
        for (char& ch : str) {
            if (ch == '<') {
                if (!left.empty()) {
                    right.push(left.back());
                    left.pop_back();
                }
            }
            else if (ch == '>') {
                if (!right.empty()) {
                    left.push_back(right.top());
                    right.pop();
                }
            }
            else if (ch == '-') {
                if (!left.empty())
                    left.pop_back();
            }
            else
                left.push_back(ch);
 
        }
        while (!right.empty()) {
            left.push_back(right.top());
            right.pop();
        }
        if (!left.empty())
            cout << left << '\n';
    }
}