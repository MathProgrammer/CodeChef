#include <stdio.h>

#define YES 1
#define NO 0

int is_chef_lucky()
{
    int target_pages, remaining_pages, no_of_books, budget, i, pages, price, can_chef_buy_book = NO;
    scanf("%d %d %d %d", &target_pages, &remaining_pages, &budget, &no_of_books);

    for(i = 1; i <= no_of_books; i++)
    {
        scanf("%d %d", &pages, &price);

        if(pages >= (target_pages - remaining_pages) && price <= budget)
            can_chef_buy_book = YES;
    }

    return can_chef_buy_book;
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases-- != 0)
    {
        printf(is_chef_lucky() ? "LuckyChef\n" : "UnluckyChef\n");
    }
    return 0;
}
