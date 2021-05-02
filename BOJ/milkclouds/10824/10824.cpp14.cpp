#include <iostream>
#include <string>
using namespace std;
string input[4];

int main(void) {
    for(int i = 0; i < 4; i++) {
        cin >> input[i];
    }
    cout << stoll(input[0] + input[1]) + stoll(input[2] + input[3]) << endl;
}