#include <stdio.h>

#define MAX_LENGTH 1000 + 1
#define NO_OF_ALPHABETS 26
#define true 1
#define false 0

void solve()
{
    int alphabet_present_1[NO_OF_ALPHABETS] = {false}, alphabet_present_2[NO_OF_ALPHABETS] = {false}, same_alphabet_present = false, i;
    char string_1[MAX_LENGTH], string_2[MAX_LENGTH];
    scanf("%s %s", string_1, string_2);

    for(i = 0; string_1[i] != '\0'; i++)
        alphabet_present_1[string_1[i] - 'a'] = true;

    for(i = 0; string_2[i] != '\0'; i++)
        alphabet_present_2[string_2[i] - 'a'] = true;

    for(i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(alphabet_present_1[i] && alphabet_present_2[i])
        {
            same_alphabet_present = true;
            break;
        }
    }

    printf(same_alphabet_present ? "Yes\n" : "No\n");
}
int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
