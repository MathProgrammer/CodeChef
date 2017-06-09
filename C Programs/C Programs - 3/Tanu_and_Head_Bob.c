#include <stdio.h>

#define MAX_GESTURES 1000 + 1
#define true 1
#define false 0

void solve()
{
    char gestures[MAX_GESTURES];
    int is_indian = false, is_foreigner = false, gesture_i, no_of_gestures;
    scanf("%d %s",&no_of_gestures, gestures);

    for(gesture_i = 0; gesture_i < no_of_gestures ; gesture_i++)
    {
        if(gestures[gesture_i] == 'I')
        {
            is_indian = true; break;
        }
        else if(gestures[gesture_i] == 'Y')
        {
            is_foreigner = true; break;
        }
    }

    if(is_indian == false && is_foreigner == false)
        printf("NOT SURE\n");
    else
        printf(is_indian ? "INDIAN\n" : "NOT INDIAN\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
