#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the amount of variables you want to store in array: ";
    cin >> n;

    int input[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << "These are the stored elements: ";

    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}