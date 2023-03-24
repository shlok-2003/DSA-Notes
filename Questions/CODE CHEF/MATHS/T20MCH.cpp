/* CODECHEF.com
Chef is playing in a T20 cricket match. In a match, Team A plays for 20 overs. In a single over, the team gets to play 6 times, and in each of these 6 tries, they can score a maximum of 6 runs. After Team A's 20 overs are finished, Team B similarly plays for 20 overs and tries to get a higher total score than the first team. The team with the higher total score at the end wins the match.

Chef is in Team B. Team A has already played their 20 overs, and have gotten a score of RR. Chef's Team B has started playing, and have already scored CC runs in the first OO overs. In the remaining 20−O20−O overs, find whether it is possible for Chef's Team B to get a score high enough to win the game. That is, can their final score be strictly larger than RR?

Input:
There is a single line of input, with three integers, R,O,CR,O,C.
Output:
Output in a single line, the answer, which should be "YES" if it's possible for Chef's Team B to win the match and "NO" if not.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
0≤C≤R≤7200≤C≤R≤720
1≤O≤191≤O≤19
0≤C≤36∗O0≤C≤36∗O
Sample Input 1 
719 18 648
Sample Output 1 
YES
Explanation
In the remaining 20−O=220−O=2 overs, Team B gets to play 2∗6=122∗6=12 times, and in each try, they can get a maximum of 6 score. Which means that the maximum score that they can acheieve in these 2 overs is 12∗6=7212∗6=72. Thus, the maximum total score that Team B can achieve is C+72=720C+72=720. 720720 is strictly more than Team A's score of 719719, and hence Chef's Team B can win this match.

Sample Input 2 
720 18 648
Sample Output 2 
NO
Explanation
Similar to the previous explanation, the maximum total score that Team B can achieve is 720720, which isn't strictly greater than Team A's 720720.Hence Chef's Team B can't win this match.
*/

#include <iostream>
using namespace std;

int main() {
	int r, o, c;
	cin >> r >> o >> c;
	
	o = (20 - o) * 6;
	c= o * 6;
	
	if(c > r)
	{
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

	
	return 0;
}
