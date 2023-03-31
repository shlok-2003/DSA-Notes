/* CODECHEF.com
There were NN students (numbered 11 through NN) participating in the Indian Programming Camp (IPC) and they watched a total of KK lectures (numbered 11 through KK). For each student ii and each lecture jj, the ii-th student watched the jj-th lecture for Ti,jTi,j minutes.

Additionally, for each student ii, we know that this student asked the question, "What is the criteria for getting a certificate?" QiQi times.

The criteria for getting a certificate is that a student must have watched at least MM minutes of lectures in total and they must have asked the question no more than 1010 times.

Find out how many participants are eligible for a certificate.

Input
The first line of the input contains three space-separated integers NN, MM and KK.
NN lines follow. For each valid ii, the ii-th of these lines contains K+1K+1 space-separated integers Ti,1,Ti,2,…,Ti,K,QiTi,1,Ti,2,…,Ti,K,Qi.
Output
Print a single line containing one integer — the number of participants eligible for a certificate.

Constraints
1≤N,K≤1,0001≤N,K≤1,000
1≤M≤1061≤M≤106
1≤Qi≤1061≤Qi≤106 for each valid ii
1≤Ti,j≤1,0001≤Ti,j≤1,000 for each valid ii and jj
Sample Input 1 
4 8 4
1 2 1 2 5
3 5 1 3 4
1 2 4 5 11
1 1 1 3 12
Sample Output 1 
1
Explanation
Participant 11 watched 1+2+1+2=61+2+1+2=6 minutes of lectures and asked the question 55 times. Since 6<M6<M, this participant does not receive a certificate.
Participant 22 watched 3+5+1+3=123+5+1+3=12 minutes of lectures and asked the question 44 times. Since 12≥M12≥M and 4≤104≤10, this participant receives a certificate.
Participant 33 watched 1+2+4+5=121+2+4+5=12 minutes of lectures and asked the question 1111 times. Since 12≥M12≥M but 11>1011>10, this participant does not receive a certificate.
Participant 44 watched 1+1+1+3=61+1+1+3=6 minutes of lectures and asked the question 1212 times. Since 6<M6<M and 12>1012>10, this participant does not receive a certificate.
Only participant 22 receives a certificate.
*/

#include <iostream>
using namespace std;

int main() {
	int n, m, k, q;
	cin >> n >> m >> k;
	int b = 0;
	
	while(n--)
	{
        int i;
        int t = 0;
        int a[k];
        
        for(i = 0; i < k; i++)
        {
            cin >> a[i];
            t += a[i];
        }
        cin >> q;
        
        if(t >= m && q <= 10)
        {
            b++;
        }
	}  
	cout << b << endl;
	
	return 0;
}
