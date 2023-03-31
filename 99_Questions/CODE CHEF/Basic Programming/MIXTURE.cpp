/* CODECHEF.com
Read problem statements in Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
Chef has AA units of solid and BB units of liquid. He combines them to create a mixture. What kind of mixture does Chef produce: a solution, a solid, or a liquid?

A mixture is called :

1) A solution if A>0A>0 and B>0B>0,

2) A solid if B=0B=0, or

3) A liquid if A=0A=0.

Input Format
The first line contains TT denoting the number of test cases. Then the test cases follow.
Each test case contains two space-separated integers AA and BB on a single line.
Output Format
For each test case, output on a single line the type of mixture Chef produces, whether it is a Solution, Solid, or Liquid. The output is case sensitive.

Constraints
1≤T≤201≤T≤20
0≤A,B≤1000≤A,B≤100
A+B>0A+B>0
Subtasks
Subtask 1 (100 points): Original constraints
Sample Input 1 
3
10 5
0 3
3 0
Sample Output 1 
Solution
Liquid
Solid
Explanation
Test case 11: Chef adds both solid and liquid to the mixture, hence the mixture is a solution.

Test case 22: Chef does not add solid to the mixture, hence the mixture is liquid.

Test case 33: Chef does not add liquid to the mixture, hence the mixture is solid.
*/

#include <iostream>
using namespace std;

int main() {
	int t, a, b;
	cin >> t;
	
	while(t--){
        cin >> a >> b;
        
        if(a == 0)
        {
            cout << "Liquid" << endl;
        }
        else if(b == 0)
        {
            cout << "Solid"<< endl;
        }
        else
        {
            cout << "Solution" << endl;
        }
	}
	return 0;
}
