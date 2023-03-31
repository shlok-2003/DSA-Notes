/* CODECHEF.com
Vacations have arrived and Chef wants to go to his home in ChefLand. There are two types of routes he can take:

Take a flight from his college to ChefArina which takes XX minutes and then take a bus from ChefArina to ChefLand which takes YY minutes.
Take a direct train from his college to ChefLand which takes ZZ minutes.
Which of these two options is faster?

Input Format
The first line of the input contains a single integer TT - the number of test cases. The test cases then follow.
The first line of the test case contains three space-separated integers XX, YY, and ZZ.
Output Format
For each test case, if Chef takes the train output TRAIN, if Chef takes the plane and the bus output PLANEBUS, if both are equal output EQUAL.

You may print each character of the string in uppercase or lowercase (for example, the strings train, tRAiN, TrAin, and TRAIN will all be treated as identical).

Constraints
1≤T≤10001≤T≤1000
1≤X,Y,Z≤1091≤X,Y,Z≤109
Subtasks
Subtask 11 (100 points): Original constraints
Sample Input 1 
3
10 12 11
3 5 15
9 4 13
Sample Output 1 
TRAIN
PLANEBUS
EQUAL
Explanation
Test Case 1: It will take 10+12=2210+12=22 minutes to travel using Plane and Bus. The train journey takes 1111 minutes. Since the train is faster, Chef will choose the train.
Test Case 2: It will take 3+5=83+5=8 minutes to travel using Plane and Bus. The train journey takes 1515 minutes. Since the plane and bus are faster, Chef will choose the plane and bus.
Test Case 3: It will take 9+4=139+4=13 minutes to travel using Plane and Bus. The train journey takes 1313 minutes. Since they both are equal, Chef can choose either.
*/

#include <iostream>
using namespace std;

int main() {
	int t, x, y, z;
	cin >> t;
	
    while(t--){
        cin >> x >> y >> z;
        
        if((x + y) > z)
        {
            cout << "TRAIN" << endl;    
        }
        else if((x + y) < z)
        {
            cout << "PLANEBUS" << endl;
        }
        else
        {
            cout << "EQUAL" << endl;
        }
    }
	return 0;
}

