#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int MINIMUM_DISTANCE = 6;
    int last_one = 0, social_distancing = true;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] == 0)
        {
            continue;
        }
        
        if(last_one > 0 && i - last_one < MINIMUM_DISTANCE)
        {
            social_distancing = false;
        }
        
        last_one = i;
    }
    
    printf(social_distancing ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
