#include <stdio.h>

int main()
{
    int money, jacket_cost, sock_cost, no_of_socks;
    scanf("%d %d %d", &jacket_cost, &sock_cost, &money);

    no_of_socks = (money - jacket_cost)/sock_cost;

    printf( no_of_socks > 0 && no_of_socks%2 == 0 ? "Lucky Chef\n" : "Unlucky Chef\n");
    return 0;
}
