#include <cstdio>

#define MAX_LENGTH 100000 + 1

int main()
{
    char sequence[MAX_LENGTH], previous_character = 'X';
    int no_of_alternating_sequences = 0, no_of_operations, i;
    scanf("%s", sequence);

    for(i = 0; sequence[i] != '\0'; i++)
    {
        no_of_alternating_sequences += (previous_character != sequence[i]);

        previous_character = sequence[i];
    }

    //If last character is 0, no_of operations = 1 less than no of alternating sequences. Otherwise, number of alternating sequences.
    no_of_operations = no_of_alternating_sequences - (sequence[i - 1] == '0');

    printf("%d\n", no_of_operations);

    return 0;
}
