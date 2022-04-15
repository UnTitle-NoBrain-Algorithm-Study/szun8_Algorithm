#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	if (n % 5 == 0)
        cout<<n/5;

	else if (n % 5 == 1 && n > 5)
        cout<<n/5+1;

	else if (n % 5 == 2 && n > 11)
		cout<<n/5+2;

	else if (n % 5 == 3)
		cout<<n/5+1;

	else if (n % 5 == 4 && n > 8)
		cout<<n/5+2;

	else 
		cout<<"-1";
    return 0;
}