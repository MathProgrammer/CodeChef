#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int num_i;
    char ch;
    vector <int> numbers;

    do{
        scanf("%d%c", &num_i, &ch);
        numbers.push_back(num_i);
    }while(ch != '\n');

    bool size_found = false;
    int maximum = 0;
    for(unsigned int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == numbers.size() - 1 && size_found == false)
            size_found = true;
        else
            maximum = max(maximum, numbers[i]);
    }

    printf("%d\n", maximum);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
