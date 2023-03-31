/* CODECHEF.com
Once, after a stressful day, Chef decided to relax and visit a casino near his house to gamble. He feels lucky and he's going to bet almost all of his money.

The game Chef is going to play in the casino consists of tossing a die with NN faces twice. There is a number written on each face of the die (these numbers are not necessarily distinct). In order to win, Chef must get the number AA on the first toss and the number BB on the second toss of the die.

The excited viewers want to know the probability that Chef will win the game. Can you help them find that number? Assume that Chef gets each face of the die with the same probability on each toss and that tosses are mutually independent.

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first line of each test case contains three space-separated integers NN, AA and BB.
The second line contains NN space-separated integers x1,x2,…,xNx1,x2,…,xN denoting the numbers written on the faces of the die.
Output
For each test case, print a single line containing one real number — the probability that Chef will win. Your answer will be considered correct if its absolute error does not exceed 10−610−6.

Constraints
1≤T≤701≤T≤70
1≤N≤1041≤N≤104
1≤A≤N1≤A≤N
1≤B≤N1≤B≤N
1≤xi≤N1≤xi≤N for each valid ii
Subtasks
Subtask #1 (20 points):

T≤10T≤10
N≤100N≤100
Subtask #2 (80 points): original constraints

Sample Input 1 
2
5 1 1
1 1 1 1 1
2 1 1
1 2
Sample Output 1 
1.0000000000
0.2500000000
*/

#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
	int t, n, a, b;
	cin >> t;
	
	while(t--)
	{
        cin >> n >> a >> b;
        int arr[n];
        
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        float first = 0, second = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == a)
            {
                first++;
            }
            if(arr[i] == b)
            {
                second++;
            }
            
        }
        
        double ans = (first * second) / (n * n);                   
        
        cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}
