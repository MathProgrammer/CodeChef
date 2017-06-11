#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int main()
{
    int  no_of_rounds, i, player_1_score = 0, player_2_score, player_1_total = 0, player_2_total = 0, player_1_max_lead = 0, player_2_max_lead = 0;
    scanf("%d", &no_of_rounds);

    for(i = 1; i <= no_of_rounds; i++)
    {
        scanf("%d %d", &player_1_score, &player_2_score);

        player_1_total += player_1_score;
        player_2_total += player_2_score;

        player_1_max_lead = max(player_1_max_lead, (player_1_total - player_2_total) );
        player_2_max_lead = max(player_2_max_lead, (player_2_total - player_1_total) );
    }

    if(player_1_max_lead > player_2_max_lead)
        printf("1 %d\n",player_1_max_lead);
    else
        printf("2 %d\n", player_2_max_lead);

    return 0;
}
