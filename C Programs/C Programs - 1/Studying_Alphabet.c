#include <stdio.h>

#define NO_OF_ALPHABETS 26
#define true 1
#define false 0

int main()
{
    int alphabet_present[NO_OF_ALPHABETS] = {false}, no_of_words, i, j, can_read;
    char word[NO_OF_ALPHABETS + 1];

    scanf("%s %d", word, &no_of_words);

    for(i = 0; word[i] != '\0'; i++)
        alphabet_present[word[i] - 'a'] = true;

    for(i = 1; i <= no_of_words; i++)
    {
        scanf("%s", word);

        can_read = true;
        for(j = 0; word[j] != '\0'; j++)
            if(alphabet_present[word[j] - 'a'] == false)
            {
                can_read = false;
                break;
            }

        printf(can_read ? "Yes\n" : "No\n");
    }

    return 0;
}
