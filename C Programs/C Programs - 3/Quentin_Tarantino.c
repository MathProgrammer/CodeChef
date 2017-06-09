#include <stdio.h>

#define MAX_CHAPTERS 500 + 1
#define true 1
#define false 0

void solve()
{
    int out_of_order = false, sloppy_numbering = false, i, chapter_i, no_of_chapters, chapter_already_written[MAX_CHAPTERS] = {false};
    scanf("%d",&no_of_chapters);

    for(i = 1; i <= no_of_chapters ; i++)
    {
        scanf("%d", &chapter_i);
        if(chapter_i > no_of_chapters || chapter_already_written[chapter_i])
            sloppy_numbering = true;

        if(chapter_i != i)
            out_of_order = true;

        chapter_already_written[chapter_i] = true;
    }

    printf(out_of_order && sloppy_numbering == false ? "yes\n" : "no\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
