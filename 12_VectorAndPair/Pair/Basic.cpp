#include<iostream>
#include<vector>
using namespace std;

int main() {
    // We can pair two elements of any data type with c++ stl --> pair
    // It stores the two data type and these data's can be anything. Mainly, these are the data's which have some relation between them.
    // Like if we want to do some operation on array according to their value(smallest --> largest). 
    // I mean if we want to do some operation according to the input array values in order. Then we have to sort it first. 
    // But after sorting, their relative index would change and this means, the required operation couldn't be performed as new
    // index would be diff from before index. 
    // So we could store the elements along with their index, so that after sorting, we could do relevant operations according to their indexes 
    // which are stored in the pair. This could be done by pair<type, type>.

    pair<int, char> pr;
    pr.first = 4;
    pr.second = 'c';

    cout << pr.first << " " << pr.second << endl;
    return 0;
}