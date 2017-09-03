#include <cstdio>
#include <vector>

#define MAX_SIZE 50000 + 3
using namespace std;

void solve()
{
    const int no_of_alphabets = 26;
    vector <int> price(no_of_alphabets + 1);
    for(int i = 0; i < no_of_alphabets; i++)
        scanf("%d", &price[i]);

    char text[MAX_SIZE];
    scanf("%s", text);

    vector <int> is_present(no_of_alphabets);
    for(int i = 0; text[i] != '\0'; i++)
        is_present[text[i] - 'a'] = true;

    int minimum_price = 0;
    for(int i = 0; i < no_of_alphabets; i++)
        if(!is_present[i])
            minimum_price += price[i];

    printf("%d\n", minimum_price);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
