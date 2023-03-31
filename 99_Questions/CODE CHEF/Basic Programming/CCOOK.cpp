/* CODECHEF.com
Chef has obtained the results of a past Cook-Off. He wants to estimate the skill level of each contestant. The contestants can be classified with high probability (w.h.p.) based on the number of solved problems:

A contestant that solved exactly 0 problems is a beginner.
A contestant that solved exactly 1 problem is a junior developer.
A contestant that solved exactly 2 problems is a middle developer.
A contestant that solved exactly 3 problems is a senior developer.
A contestant that solved exactly 4 problems is a hacker.
A contestant that solved all five problems is Jeff Dean.
Please help Chef to identify the programming level of each participant.

Input
The first line of the input contains a single integer N denoting the number of competitors.
N lines follow. The i-th of these lines contains five space-separated integers Ai, 1, Ai, 2, Ai, 3, Ai, 4, Ai, 5. The j-th of these integers (1 ≤ j ≤ 5) is 1 if the i-th contestant solved the j-th problem and 0 otherwise.
Output
For each participant, print a single line containing one string denoting Chef's classification of that contestant — one of the strings "Beginner", "Junior Developer", "Middle Developer", "Senior Developer", "Hacker", "Jeff Dean" (without quotes).

Constraints
1 ≤ N ≤ 5000
0 ≤ Ai, j ≤ 1 for each valid i, j
Sample Input 1 
7
0 0 0 0 0
0 1 0 1 0
0 0 1 0 0
1 1 1 1 1
0 1 1 1 0
0 1 1 1 1
1 1 1 1 0
Sample Output 1 
Beginner
Middle Developer
Junior Developer
Jeff Dean
Senior Developer
Hacker
Hacker
Explanation
The first contestant has no solved problems, therefore he is a beginner. The second contestant solved 2 problems (the second and fourth 
problem), therefore he has the skills of a middle developer. The third contestant solved 1 problem, therefore he's at the expected level of a junior developer. The fourth contestant solved 5 problems — we can guess it was Jeff Dean. The fifth contestant solved 3 problems, so he is a senior developer. And the last two contestants should be hackers because they solved exactly 4 problems each.
*/

#include <iostream>
using namespace std;

int main() {
	int n, a[5];
	cin >> n;
	
	while(n--)
	{
        int x =0;
        for(int i = 0; i < 5; i++)
        {
            cin >> a[i];
            
            if(a[i] == 1)
            {
                x++;
            }
        }
        
        if(x == 0)
        {
            cout << "Beginner" << endl;
        }
        else if(x == 1)
        {
            cout << "Junior Developer" << endl;
        }
        else if(x == 2)
        {
            cout << "Middle Developer" << endl;
        }
        else if(x == 3)
        {
            cout << "Senior Developer" << endl;
        }
        else if(x == 4)
        {
            cout << "Hacker" << endl;
        }
        else if(x == 5)
        {
            cout << "Jeff Dean" << endl;
        }
	}
	return 0;
}
