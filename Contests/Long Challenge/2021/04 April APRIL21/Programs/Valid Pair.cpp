#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << (a == b || b == c || c == a ? "Yes" : "No") << "\n";

    return 0;
}
