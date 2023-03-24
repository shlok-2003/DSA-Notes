#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Push happens at REAR and Pop happens at FRONT
    
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.size() << endl;

    cout << "Front Element is: " << q.front() << endl;
    q.pop();

    cout << "Now Front Element is: " << q.front() << endl;
    cout << "Rear Element is: " << q.back() << endl;
}