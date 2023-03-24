#include<iostream>
using namespace std;
/*
Roy has 15 rupees. He wants to buy chocolates. 1 chocolate = 1 rupee. 
Plus 3 chocolate wrapper can buy him another choclate. How many chocolates
Roy will have at the end?
*/
int main(){
    int rupees = 15;
    int chocolate = 0;
    int rate = 1;

    while(rupees > 0){
        rupees --;
        chocolate ++;
        if(chocolate % 3 == 0){
            chocolate ++;
        }
    }
    cout << chocolate << endl;

    return 0;
}