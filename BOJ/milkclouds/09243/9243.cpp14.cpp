#include<iostream>
#include<string>
using namespace std;
 
int N, flag = 0;
string bf, af;
int main() {
    cin >> N;
    cin >> bf >> af;
    for (int i = 0; i < bf.size(); ++i ) {
        if ((bf.at(i) == af.at(i))^!(N & 1)) {
            cout << "Deletion failed" << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Deletion succeeded" << endl;
}