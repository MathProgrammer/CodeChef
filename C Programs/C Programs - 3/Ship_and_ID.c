#include <stdio.h>

void solve()
{
    char id;
    scanf(" %c", &id);

    switch(id)
    {
        case 'b':
        case 'B': printf("BattleShip\n");
                  return;
        case 'c':
        case 'C': printf("Cruiser\n");
                  return;
        case 'd':
        case 'D': printf("Destroyer\n");
                  return;
        case 'f':
        case 'F': printf("Frigate\n");
                  return;
    }
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}

