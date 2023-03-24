/*  CODECHEF.com
Chef has an exam which will start exactly MM minutes from now. However, instead of preparing for his exam, Chef started watching Season-11 of Superchef. Season-11 has NN episodes, and the duration of each episode is KK minutes.

Will Chef be able to finish watching Season-11 strictly before the exam starts?

Note:Note: Please read the explanations of the sample test cases carefully.

Input Format
The first line contains an integer TT denoting the number of test cases. TT test cases then follow.
The first and only line of each test case contains 33 space separated integers MM, NN and KK.
Output Format
For each test case, output on one line YES if it is possible to finish Season-1 strictly before the exam starts, or NO if it is not possible to do so.

Output is case insensitive, which means that "yes", "Yes", "YEs", "no", "nO" - all such strings will be acceptable.

Constraints
1≤T≤1041≤T≤104
1≤M≤1091≤M≤109
1≤N,K≤1041≤N,K≤104
Sample Input 1 
3
10 1 10
25 2 10
15 2 10
Sample Output 1 
NO
YES
NO
Explanation
Test Case 11: The duration of the only episode is 1010 minutes, and the exam starts exactly after 1010 minutes. So, Chef will not be able to finish watching Season-11 strictly before the exam starts.

Test Case 22: There are two episodes in Season-11, each of duration 1010 minutes. Therefore, Chef will require 10+10=2010+10=20 minutes to finish watching Season-11. As the exam starts after 2525 minutes, Chef will be able to finish watching Season-11 strictly before the exam starts.

Test Case 33: There are two episodes in Season-11, each of duration 1010 minutes. Therefore, Chef will require 10+10=2010+10=20 minutes to finish watchin Season-11. As the exam starts after 1515 minutes, Chef will not be able to finish watching Season-11 strictly before the exam starts.
*/

#include <iostream>
using namespace std;

int main() {
	int t, m, n, k;
	cin >> t;
	
	while(t--){
        cin >> m >> n >> k;
        
        int time = n * k;
        
        if (m > time)
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
