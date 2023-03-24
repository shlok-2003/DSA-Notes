/* CODECHEF.com
You are given a standard 8×88×8 chessboard which has exactly 22 rooks on it and no other pieces. The rows are numbered 11 to 88 from bottom to top, and the columns are numbered 11 to 88 from left to right. The cell at the intersection of the ii-th column and jj-th row is denoted (i,j)(i,j).

Given the initial positions of the rooks in the form of coordinates (X1,Y1)(X1,Y1) and (X2,Y2)(X2,Y2), you need to tell whether the 22 rooks currently attack each other or not. Assume, each square can contain at most one piece.

Rooks can only travel in straight lines along the row or column they are placed at, and can't jump over other pieces. For a more detailed explanation of the moves of rooks, along with images, please click here.

Input Format
The first line contains TT - the number of test cases. Then the test cases follow.
The first line of each test case contain four space-separated integers each X1,Y1,X2,Y2X1,Y1,X2,Y2 - (X1,Y1)(X1,Y1) is the position of the first rook and (X2,Y2)(X2,Y2) is the position of the second rook.
Output Format
For each test case, output on a single line YES (without quotes) if the rooks attack each other, and NO otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings YeS, YEs, yes and yeS will all be treated as identical).

Constraints
1≤T≤50001≤T≤5000
1≤X1,X2,Y1,Y2≤81≤X1,X2,Y1,Y2≤8
(X1,Y1)≠(X2,Y2)(X1,Y1)≠(X2,Y2)
Sample Input 1 
3
1 2 5 2
1 2 1 5
1 1 8 8
Sample Output 1 
YES
YES
NO
Explanation
Test case 11: The two rooks can attack each other by moving along the second column.
Test case 22: The two rooks can attack each other by moving along the first row.
Test case 33: No matter how a rook moves it cannot reach the second rook in one move. Hence, they do not attack each other.
*/

#include <iostream>
using namespace std;

int main() {
	int t, x1, y1, x2, y2;
	cin >> t;
	
	while(t--)
	{
        cin >> x1 >> y1 >> x2 >> y2;
        
        if(x1 == x2 || y1 == y2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
	return 0;
}
