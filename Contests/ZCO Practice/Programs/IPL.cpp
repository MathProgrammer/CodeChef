#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_games;
    scanf("%d", &no_of_games);

    vector <int> fee(no_of_games + 5, 0);
    for(int i = 1; i <= no_of_games; i++)
        scanf("%d", &fee[i]);

    vector <int> maximum_money_starting(no_of_games + 5, 0);
    for(int i = no_of_games; i >= 1; i--)
    {
        maximum_money_starting[i] = maximum_money_starting[i + 1];

        maximum_money_starting[i] = max(maximum_money_starting[i], fee[i] + maximum_money_starting[i + 2]);
        maximum_money_starting[i] = max(maximum_money_starting[i], fee[i] + fee[i + 1] + maximum_money_starting[i + 3]);
    }

    printf("%d\n", maximum_money_starting[1]);
    return 0;
}
