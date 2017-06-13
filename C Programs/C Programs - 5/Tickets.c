#include <stdio.h>

#define MAX_LENGTH 1000 + 1
#define true 1
#define false 0

void solve()
{
    char ticket[MAX_LENGTH], first_character, second_character;
    int successful = true, i;

    scanf("%s", ticket);

    first_character = ticket[0];
    second_character = ticket[1];

    if(first_character == second_character)
        successful = false;

    for(i = 2; ticket[i] != '\0'; i++)
    {
        if( (i%2 == 0 && ticket[i] != first_character) || (i%2 == 1 && ticket[i] != second_character) )
        {
            successful = false;
            break;
        }
    }

    printf(successful ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);
    while(no_of_queries-- != 0)
        solve();

    return 0;
}

