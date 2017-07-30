#include <cstdio>
#include <map>

using namespace std;

#define MAX_LENGTH 1000 + 2

void solve()
{
    char string_1[MAX_LENGTH], string_2[MAX_LENGTH];
    scanf("%s %s", string_1, string_2);

    map <char, char> mapping_1_to_2;
    map <char, char> mapping_2_to_1;
    for(int i = 0; string_1[i] != '\0'; i++)
    {
        mapping_1_to_2[string_1[i]] = mapping_2_to_1[string_2[i]] = '*';
    }

    bool historical_similarity = true;
    for(int i = 0; string_1[i] != '\0'; i++)
    {
        char char_1 = string_1[i], char_2 = string_2[i];

        if(mapping_1_to_2[char_1] == '*' && mapping_2_to_1[char_2] == '*')//Both unmapped
        {
            mapping_1_to_2[char_1] = char_2;
            mapping_2_to_1[char_2] = char_1;
        }
        else if(mapping_1_to_2[char_1] != char_2 || mapping_2_to_1[char_2] != char_1)
        {
            historical_similarity = false;
            break;
        }
    }

    printf(historical_similarity ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
