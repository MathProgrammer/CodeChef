#include <iostream>
#include <algorithm>

#define MAX_PLATES 7 + 1

using namespace std;

void solve()
{
    int no_of_plates, i;
    long long no_of_meatballs_on_plate[MAX_PLATES], target_meatballs;

    cin >> no_of_plates >> target_meatballs;
    for(i = 0; i < no_of_plates; i++)
        cin >> no_of_meatballs_on_plate[i];

    sort(no_of_meatballs_on_plate, no_of_meatballs_on_plate + no_of_plates);
    reverse(no_of_meatballs_on_plate, no_of_meatballs_on_plate + no_of_plates);

    for(i = 0; i < no_of_plates; i++)
    {
        target_meatballs -= no_of_meatballs_on_plate[i];
        if(target_meatballs <= 0)
            break;
    }

    cout << (target_meatballs <= 0 ? i + 1 : -1) << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
