/* CODECHEF.com
It's the soccer match finals in Chefland and as always it has reached the penalty shotouts. Each team is given 55 shots to make and the team scoring a goal on the maximum number of shots wins the game. If both the teams' scores are equal, then the game is considered a draw and we would have 22 champions.

Given ten integers A1,A2,…,A10A1,A2,…,A10, where the odd indexed integers(A1,A3,A1,A3, A5,A5, A7,A9A7,A9) represent the outcome of the shots made by team 11 and even indexed integers(A2,A4,A6,A8,A10A2,A4,A6,A8,A10) represent the outcome of the shots made by team 22 (here Ai=1Ai=1 indicates that it's a goal and Ai=0Ai=0 indicates a miss), determine the winner or find if the game ends in a draw.

Input Format
The first line of input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains ten space-separated integers A1,A2,…,A10A1,A2,…,A10.
Output Format
For each test case, print a single line containing one integer - 00 if the game ends in a draw or 11 if the first team wins or 22 if the second team wins.

Constraints
1≤T≤10241≤T≤1024
0≤Ai≤10≤Ai≤1
Sample Input 1 
4
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
1 0 1 0 0 0 0 0 0 0 
1 1 1 1 1 1 1 1 1 0
Sample Output 1 
0
2
1
1
Explanation
Test case 11: No team scores any goal, so the game ends in a draw.

Test case 22: The second team is able to score in their final shot, while the first team has scored 0 goals and hence the second team wins.

Test case 33: The first team is successfully able to make their first 22 shots count and whereas the second team has not scored any goals. Therefore the first team wins.

Test case 44: Team 22 misses their final shot and hence team 11 wins the game with the final score of 5−45−4.
*/

#include <iostream>
using namespace std;

int main() {
	int t, a[10];
	cin >> t;
	
	while(t--)
	{
        int x = 0; 
        int y = 0;
        
        for(int i = 0; i < 10; i++){
            cin >> a[i];
            if((a[i] == 1) && (i % 2 == 0))
            {
                x++;
            }
            else if((a[i] == 1) && (i % 2 == 1))
            {
                y++;
            }
        }
        
        if(x == y)
        {
            cout << "0" << endl;
        }
        else if(x > y)
        {
            cout << "1" << endl;
        }
        else if(x < y)
        {
            cout << "2" << endl;
        }

	}
	return 0;
}
