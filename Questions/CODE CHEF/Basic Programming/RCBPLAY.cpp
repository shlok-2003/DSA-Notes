#include <iostream>
using namespace std;

int main() {
	int t, x, y, z;
	cin >> t;
	
	while(t--){
        cin >> x >> y >> z;

	    z = 2 * z;

        if(y <= (x + z))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
	}
	return 0;
}
