/* CODECHEF.com
You are given the height HH (in metres) and mass MM (in kilograms) of Chef. The Body Mass Index (BMI) of a person is computed as MH2MH2.

Report the category into which Chef falls, based on his BMI:

Category 1: Underweight if BMI ≤18≤18
Category 2: Normal weight if BMI ∈{19∈{19, 2020,……, 24}24}
Category 3: Overweight if BMI ∈{25∈{25, 2626,……, 29}29}
Category 4: Obesity if BMI ≥30≥30
Input:
The first line of input will contain an integer, TT, which denotes the number of testcases. Then the testcases follow.
Each testcase contains a single line of input, with two space separated integers, M,HM,H, which denote the mass and height of Chef respectively.
Output:
For each testcase, output in a single line, 1,2,31,2,3 or 44, based on the category in which Chef falls.

Constraints
1≤T≤2∗1041≤T≤2∗104
1≤M≤1041≤M≤104
1≤H≤1021≤H≤102
Its guaranteed that H2H2 divides MM.
Sample Input:
3
72 2
80 2
120 2
Sample Output:
1
2
4
Explanation:
Case 1: Since MH2=7222=18MH2=7222=18, therefore person falls in category 11.

Case 2: Since MH2=8022=20MH2=8022=20, therefore person falls in category 22.

Case 3: Since MH2=12022=30MH2=12022=30, therefore person falls in category 44.
*/

#include <iostream>
using namespace std;

int main() {
	int t, m, h;
	cin >> t;
	
	while(t--){
        cin >> m >> h;
        int bmi = (m) / (h*h);
        
        if(bmi <= 18)
        {
            cout << "1" << endl;
        }
        else if(bmi < 25)
        {
            cout << "2" << endl;
        }
        else if(bmi < 30)
        {
            cout << "3" << endl;
        }
        else
        {
            cout << "4" << endl;
        }
	}
	return 0;
}
