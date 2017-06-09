#include <stdio.h>

void solve()
{
    int max_limak_candies, max_bob_candies, no_of_limak_turns, no_of_bob_turns;
    scanf("%d %d", &max_limak_candies, &max_bob_candies);

    //Limak has always eaten n^2 candies after n turns
    for(no_of_limak_turns = 0; no_of_limak_turns*no_of_limak_turns <= max_limak_candies; no_of_limak_turns++);

    no_of_limak_turns--;

    //Bob has eaten n(n+1) i.e. 2T_n candies after n turns
    for(no_of_bob_turns = 0; no_of_bob_turns*(no_of_bob_turns + 1) <= max_bob_candies; no_of_bob_turns++);

    no_of_bob_turns--;

    printf(no_of_limak_turns > no_of_bob_turns ? "Limak\n" : "Bob\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
