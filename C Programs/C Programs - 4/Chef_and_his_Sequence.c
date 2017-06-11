#include <stdio.h>

#define MAX_SEQUENCE_LENGTH 1000 + 1
#define MAX_SUBSEQUENCE_LENGTH 1000 + 1
#define true 1
#define false 0

void solve()
{
     int subsequence_present = false, i, subsequence_i = 0, length_of_sequence, length_of_subsequence;
     int subsequence[MAX_SEQUENCE_LENGTH], sequence[MAX_SUBSEQUENCE_LENGTH];

     scanf("%d", &length_of_sequence);
     for(i = 0; i < length_of_sequence; i++)
          scanf("%d", &sequence[i]);

     scanf("%d", &length_of_subsequence);
     for(i = 0; i < length_of_subsequence; i++)
        scanf("%d", &subsequence[i]);

     for(i = 0; i < length_of_sequence; i++)
     {
         if(sequence[i] == subsequence[subsequence_i])
         {
             subsequence_i++;
             if(subsequence_i == length_of_subsequence)
             {
                 subsequence_present = true;
                 break;
             }
         }
     }

     printf(subsequence_present ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d",&no_of_test_cases);

    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
