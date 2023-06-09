/* CODECHEF.com
To address the situation of Water Scarcity in Chefland, Chef has started an awareness campaign to motivate people to use greywater for toilets, washing cars, gardening, and many other chores which don't require the use of freshwater. These activities presently consume yy liters of water every week per household and Chef thinks through this campaign he can help cut down the total usage to ⌊y2⌋⌊y2⌋.

Assuming xx liters of water every week per household is consumed at chores where using freshwater is mandatory and a total of CC liters of water is available for the entire Chefland having HH households for a week, find whether all the households can now have sufficient water to meet their requirements.

Input:
First line will contain TT, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, four integers H,x,y,CH,x,y,C.
Output:
Print a single line containing the string "YES" if it is possible to meet the requirement of all the households in Chefland or "NO" if it is impossible (without quotes).

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤3001≤T≤300
1≤H,x,y≤101≤H,x,y≤10
1≤C≤1001≤C≤100
Sample Input:
3
3 1 1 3
1 1 1 2
2 1 1 1
Sample Output:
YES
YES
NO
Explanation:
TestCase 1: Total consumption of a single household after using greywater = 1+1+ ⌊12⌋⌊12⌋ = 1+01+0 = 11 liter.

Total consumption of three households after using greywater = 3∗1=33∗1=3 liters which is equal to the available quantity of water.

TestCase 2: Total consumption of a single household after using greywater = 1+1+ ⌊12⌋⌊12⌋ = 1+01+0 = 11 liter which is less than the available quantity of water.

TestCase 3: Total consumption of a single household after using greywater = 1+1+ ⌊12⌋⌊12⌋ = 1+01+0 = 11 liter.

Total consumption of two households after using greywater = 2∗1=22∗1=2 liters which is more than the available quantity of water.
*/

#include <iostream>
using namespace std;

int main()
{
	int t, h, x, y, c;
	cin >> t;
	
	while(t--)
	{
        cin >> h >> x >> y >> c;
        
        x = x + y/2;
        x = h * x;          //total water consumed
        
        if(x > c)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
	return 0;
}
