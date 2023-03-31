#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, x, m, d;
	cin >> t;
	
	while(t--){
        cin >> x >> m >> d;
        
	    int a = x * m;
        int b = x + d;
        
        cout << min(a, b) << endl;
    }
	return 0;
}
