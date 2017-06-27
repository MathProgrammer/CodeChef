#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int number_of_houses;
    scanf("%d", &number_of_houses);

    vector <int> gold_in_house(number_of_houses);
    for(int i = 0; i < number_of_houses; i++)
        scanf("%d", &gold_in_house[i]);


    sort(all(gold_in_house));

    int number_of_queries;
    scanf("%d", &number_of_queries);

    for(int i = 1; i <= number_of_queries; i++)
    {
        int no_of_free_houses, minimum_cost = 0;
        scanf("%d", &no_of_free_houses);

        int paid_house = 0;
        int looted_houses = 0;

        while(looted_houses < number_of_houses)
        {
            minimum_cost += gold_in_house[paid_house];

            paid_house++;

            looted_houses +=  1 + no_of_free_houses; //At each step, take 1 paid house and as many free houses as possible
        }

        printf("%d\n", minimum_cost);
    }
    return 0;
}
