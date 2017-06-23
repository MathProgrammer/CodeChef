#include <stdio.h>
#include <string>
#include <algorithm>

#define MAX_LENGTH 100000 + 1

using namespace std;

int main()
{
    int subsequence_count = 0, location_c, location_h = 0, location_e = 0, location_f = 0;
    char sequence[MAX_LENGTH];
    scanf("%s", sequence);

    for(location_c = 0; sequence[location_c] != '\0'; location_c++)
    {
        if(sequence[location_c] == 'C')
        {
            for(location_h = max(location_c, location_h) + 1; sequence[location_h] != '\0' && sequence[location_h] != 'H'; location_h++);

            if(sequence[location_h] == '\0') break;

            for(location_e = max(location_h, location_e) + 1; sequence[location_e] != '\0' && sequence[location_e] != 'E'; location_e++);

            if(sequence[location_e] == '\0') break;

            for(location_f = max(location_e, location_f) + 1; sequence[location_f] != '\0' && sequence[location_f] != 'F'; location_f++);

            if(sequence[location_f] == '\0') break;

            subsequence_count++;
        }
    }

    printf("%d\n", subsequence_count);

    return 0;
}
