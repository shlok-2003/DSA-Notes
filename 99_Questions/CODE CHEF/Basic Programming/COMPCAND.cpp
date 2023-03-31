/* CODECHEF.com
You are a person who is always fond of eating candies. Your friend gave you a candy of length NN, to eat during the break period of your school.

You start eating this candy from one of the ends. But as it is not your candy, your friend told you to eat exactly KK unit length of candy during each bite. You will stop eating if the candy's length becomes 00. This means that you have eaten the entire candy.

If at some point of time, the candy's length is positive, but less than KK, you cannot take a bite thereafter.

Can you eat the complete candy? If yes, print the number bites it will take, else print −1−1.

Input Format
First line will contain TT, number of testcases. Then the testcases follow.
Each testcase contains of two spaced integers NN, KK.
Output Format
For each testcase, print the minimum number of bites you need to eat the complete candy. Print −1−1 if it is not possible to do so.

Constraints
1≤T≤1051≤T≤105
0≤N≤1060≤N≤106
1≤K≤1061≤K≤106
Sample Input 1 
3
3 1
3 2
0 3
Sample Output 1 
3
-1
0
Explanation
Test case 1: When you eat your first bite of length 11, the length of the candy will become 22. After the second bite, the candy's length will be 11 and finally after the third bite, candy's length will be 00, and hence you eat the entire candy!

Test case 2: After the first bite, candy's length will become 11. You cannot go for the second bite as candy's length is positive and less than 22.

Test case 3: Candy's length is already 00, hence it can be said that you have eaten the entire candy!
*/

#include <iostream>
using namespace std;

int main() {
	int t, n, k;
	cin >> t;
	
	while(t--)
	{
        cin >> n >> k;
        
        if(n % k == 0)
        {
            cout << n / k << endl;
        }
        else{
            cout << "-1" << endl;
        }
	}
	return 0;
}
