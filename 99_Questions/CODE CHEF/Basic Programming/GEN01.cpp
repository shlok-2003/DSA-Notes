/* CODECHEF.com
People in Chefland have three different eye colors, namely brown, blue, and green. green is the rarest of the eye colors whereas brown is most common.

The eye color of the child of two people is most likely to be the most common eye color between them.

You are given two characters denoting the eye colors of two people in Chefland. The character R denotes bRown color, B denotes Blue color, and G denotes Green color.

Determine the most likely eye color of their child. (Print R, B or G denoting bRown, Blue or Green respectively).

Please see the sample test cases below for explained examples.

Input Format
The first (and only) line of input contains two space-separated characters, the eye colors of the parents.
Output Format
Print a single character denoting the most likely eye color of the child. (Print R, B or G denoting brown, blue or green respectively).

Constraints
The input contains two space-separated characters
Each character in the input is one among {R, B, G}.
Subtasks
Sample Input 1 
R B
Sample Output 1 
R
Explanation
The two people have brown and blue eyes and brown is the most common. Therefore, their child will most likely have brown eyes.

Sample Input 2 
B B
Sample Output 2 
B
Explanation
Both parents have blue eyes, therefore their child will most likely have blue eyes

Sample Input 3 
G B
Sample Output 3 
B
Explanation
The parents have green and blue eyes, out of which blue is more common than green, therefore the child will most likely have blue eyes.
*/

#include <iostream>
using namespace std;

int main() {
	char a, b;
    cin >> a >> b;
    
    if( (a == 'R' && b == 'B') || (a == 'R' && b == 'G') || (a == 'R' && b == 'R') || (a == 'B' && b == 'R') || (a == 'G' && b == 'R') )
    {
        cout << "R" << endl;
    }
    else if( (a == 'B' && b == 'G') || (a == 'B' && b == 'B') || (a == 'G' && b == 'B') )
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "G" << endl;
    }
        
    return 0;
}
