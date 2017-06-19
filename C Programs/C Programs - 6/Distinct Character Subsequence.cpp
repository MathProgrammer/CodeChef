#include <stdio.h>

#define MAX_LENGTH 100000 + 1
#define NO_OF_ALPHABETS 26

void solve()
{
    bool alphabet_present[NO_OF_ALPHABETS] = {false};
    int no_of_distinct_characters = 0, i;
    char line[MAX_LENGTH];


    scanf("%s", line);
    for(i = 0; line[i] != '\0'; i++)
    {
        if(alphabet_present[line[i] - 'a'] == false)
            no_of_distinct_characters++;

        alphabet_present[line[i] - 'a'] = true;
    }

    printf("%d\n",no_of_distinct_characters);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
