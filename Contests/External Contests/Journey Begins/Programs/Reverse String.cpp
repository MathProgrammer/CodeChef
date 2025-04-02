#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <string> sentence;
    char word[505];
    while(scanf("%s", word) > 0)
    {
        sentence.push_back(word);
    }

    for(int i = sentence.size() - 1; i >= 0; i--)
        cout << sentence[i] << " ";

    return 0;
}
