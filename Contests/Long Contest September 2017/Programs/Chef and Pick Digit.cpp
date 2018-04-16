#include <cstdio>
#include <vector>

#define MAX_SIZE 100009
using namespace std;

int possible_to_make(char ch, vector <int> &frequency)
{
    switch(ch)
    {
        case 'A' : return (frequency[6] >= 1 && frequency[5] >= 1);
        case 'B' : return (frequency[6] >= 2);
        case 'C' : return (frequency[6] >= 1 && frequency[7] >= 1);
        case 'D' : return (frequency[6] >= 1 && frequency[8] >= 1);
        case 'E' : return (frequency[6] >= 1 && frequency[9] >= 1);
        case 'F' : return (frequency[7] >= 1 && frequency[0] >= 1);
        case 'G' : return (frequency[7] >= 1 && frequency[1] >= 1);
        case 'H' : return (frequency[7] >= 1 && frequency[2] >= 1);
        case 'I' : return (frequency[7] >= 1 && frequency[3] >= 1);
        case 'J' : return (frequency[7] >= 1 && frequency[4] >= 1);
        case 'K' : return (frequency[7] >= 1 && frequency[5] >= 1);
        case 'L' : return (frequency[7] >= 1 && frequency[6] >= 1);
        case 'M' : return (frequency[7] >= 2);
        case 'N' : return (frequency[7] >= 1 && frequency[8] >= 1);
        case 'O' : return (frequency[7] >= 1 && frequency[9] >= 1);
        case 'P' : return (frequency[8] >= 1 && frequency[0] >= 1);
        case 'Q' : return (frequency[8] >= 1 && frequency[1] >= 1);
        case 'R' : return (frequency[8] >= 1 && frequency[2] >= 1);
        case 'S' : return (frequency[8] >= 1 && frequency[3] >= 1);
        case 'T' : return (frequency[8] >= 1 && frequency[4] >= 1);
        case 'U' : return (frequency[8] >= 1 && frequency[5] >= 1);
        case 'V' : return (frequency[8] >= 1 && frequency[6] >= 1);
        case 'W' : return (frequency[8] >= 1 && frequency[7] >= 1);
        case 'X' : return (frequency[8] >= 2);
        case 'Y' : return (frequency[8] >= 1 && frequency[9] >= 1);
        case 'Z' : return (frequency[9] >= 1 && frequency[0] >= 1);
    }
    return false;
}

void solve()
{
    const int no_of_alphabets = 26;
    vector <int> frequency(no_of_alphabets, 0);

    char number[MAX_SIZE];
    scanf("%s", number);

    for(int i = 0; number[i] != '\0'; i++)
    {
        frequency[number[i] - '0']++;
    }

    for(char current_char = 'A'; current_char <= 'Z'; current_char++)
        if(possible_to_make(current_char, frequency))
            putchar(current_char);

    printf("\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
