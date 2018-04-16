#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

int main()
{
    int no_of_phones;
    scanf("%d", &no_of_phones);

    vector <int> price(no_of_phones + 1, 0);
    for(int i = 1; i <= no_of_phones; i++)
        scanf("%d", &price[i]);

    sort(all(price));

    long long total_money = 0;
    for(int i = 1; i <= no_of_phones; i++)
        total_money = max(total_money, price[i]*1LL*(no_of_phones - i + 1));

    printf("%lld\n", total_money);
    return 0;
}
