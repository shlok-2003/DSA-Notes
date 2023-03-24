/* CODECHEF.com
“You won’t get caught if you hide behind someone.”

Sang-Woo advises Gi-Hun to hide behind someone to avoid getting shot.

Gi-Hun follows Sang-Woo's advice and hides behind Ali, who saved his life earlier. Gi-Hun and Ali both have the same height, KK. Many players saw this trick and also started hiding behind Ali.

Now, there are NN players standing between Gi-Hun and Ali in a straight line, with the ithith player having height HiHi. Gi-Hun wants to know the minimum number of players who need to get shot so that Ali is visible in his line of sight.

Note:

Line of sight is a straight line drawn between the topmost point of two objects. Ali is visible to Gi-Hun if nobody between them crosses this line.
Even if there are some players who have the same height as that of Gi-Hun and Ali, Ali will be visible in Gi-Hun's line of sight.
Gi-Hun and Ali have the same height.
Input Format
The first line of input contains a single integer TT, denoting the number of test cases. The description of TT test cases follows.
The first line of each test case contains two space-separated integers NN and KK, denoting the total number of players between Gi-Hun and Ali and the height of both of them respectively.
The second line of each test case contains NN space-separated integers, denoting the heights of the players between Gi-Hun and Ali.
Output Format
For each test case, output in a single line the minimum number of players who need to get shot so that Ali is visible in Gi-Hun's line of sight.

Constraints
1≤T≤1051≤T≤105
1≤N≤1051≤N≤105
1≤K≤1061≤K≤106
1≤Hi≤1061≤Hi≤106 for every 1≤i≤N1≤i≤N.
The sum of NN across all test cases does not exceed 5⋅1055⋅105.
Sample Input 1 
3
4 10
2 13 4 16
5 8
9 3 8 8 4
4 6
1 2 3 4
Sample Output 1 
2
1
0
Explanation
Test Case 1: Gi-Hun and Ali have height 1010. For Ali to be visible to Gi-Hun, the second person (with height 1313) and the fourth person (with height 1616) need to get shot. Hence, the minimum number of players who need to get shot is 22.

Test Case 2: Gi-Hun and Ali have height 88. For Ali to be visible to Gi-Hun, the first person (with height 99) needs to get shot. Hence, the minimum number of players who need to get shot is 11.

Test Case 3: Nobody needs to get shot because everyone is shorter than Gi-Hun and Ali.
*/

#include <iostream>
using namespace std;

int main() {
	int t, n, k;
	cin >> t;
	
	while(t--)
	{
        cin >> n >> k;
        int arr[n];
        int shot = 0;
        
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] > k)
            {
                shot++;
            }
        }
        cout << shot << endl;
        
	}
	return 0;
}
