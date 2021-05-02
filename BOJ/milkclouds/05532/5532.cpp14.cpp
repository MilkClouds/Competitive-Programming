#include <iostream>
#include <math.h>
using namespace std;

int L,A,B,C,D;

int main()
{
	cin>>L>>A>>B>>C>>D;
	cout<<L-max(ceil((double)A/C),ceil((double)B/D));
}