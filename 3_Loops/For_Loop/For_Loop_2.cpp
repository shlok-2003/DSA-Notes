#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    string arr[9]={"one","two","three","four","five","six","seven","eight","nine"};
    int x;
    for(x=a;x<=b;x++){
        if(x >= a && x <= 9){
            cout<<arr[x-1]<<endl;
            }
        else{
            if(x %2==0){
                cout<<"even"<<endl;
            }
            else{
                cout<<"odd"<<endl;
            }
        }
    }
    return 0;
}