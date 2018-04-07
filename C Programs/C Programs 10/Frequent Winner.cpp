#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int no_of_names;
    cin >> no_of_names;

    map <string, int> frequency;
    while(no_of_names--)
    {
        string name;
        cin >> name;
        frequency[name]++;
    }

    string answer;
    int max_frequency = 0;

    for(map <string, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
    {
        if(it->second > max_frequency)
            max_frequency = it->second, answer = it->first;
        else if(it->second == max_frequency && it->first > answer)
            answer = it->first;
    }

    cout << answer;
    return 0;
}
