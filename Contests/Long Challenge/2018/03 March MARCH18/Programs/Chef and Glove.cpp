#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int check_fit(vector <int> &fingers, vector <int> &glove)
{
    int fits = true;

    for(int i = 0; i < fingers.size(); i++)
        if(fingers[i] > glove[i])
            fits = false;

    return fits;
}

void solve()
{
    int no_of_fingers;
    scanf("%d", &no_of_fingers);

    vector <int> finger(no_of_fingers);
    for(int i = 0; i < no_of_fingers; i++) scanf("%d", &finger[i]);

    vector <int> glove(no_of_fingers);
    for(int i = 0; i < no_of_fingers; i++) scanf("%d", &glove[i]);

    int front_possible = check_fit(finger, glove);
    reverse(all(glove));
    int back_possible = check_fit(finger, glove);

    if(front_possible && !back_possible)
        printf("front\n");
    else if(!front_possible && back_possible)
        printf("back\n");
    else
        printf(front_possible && back_possible ? "both\n" : "none\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
