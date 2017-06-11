#include <stdio.h>

#define MAX_FILES 100 + 1

void solve()
{
    int actions_on_file[MAX_FILES] = {0}, number_of_files, number_of_ignored_files, number_of_tracked_files, file_i, i;
    int number_of_ignored_and_tracked_files = 0, number_of_neither_ignored_nor_tracked_files = 0;

    scanf("%d %d %d", &number_of_files, &number_of_ignored_files, &number_of_tracked_files);

    for(i = 1; i <= number_of_ignored_files; i++)
    {
        scanf("%d", &file_i);
        actions_on_file[file_i]++;
    }

    for(i = 1; i <= number_of_tracked_files; i++)
    {
        scanf("%d", &file_i);
        actions_on_file[file_i]++;
    }

    for(i = 1; i <= number_of_files; i++)
    {
        number_of_ignored_and_tracked_files += (actions_on_file[i] == 2 ? 1 : 0);
        number_of_neither_ignored_nor_tracked_files += (actions_on_file[i] == 0 ? 1 : 0);
    }
    printf("%d %d\n",number_of_ignored_and_tracked_files, number_of_neither_ignored_nor_tracked_files);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}

