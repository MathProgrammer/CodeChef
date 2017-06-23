#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int no_of_forgotten_words, no_of_phrases;
    cin >> no_of_forgotten_words >> no_of_phrases;

    map <string, int> frequency;

    vector<string> forgotten_words(no_of_forgotten_words);
    for(int i = 0; i < no_of_forgotten_words; i++)
    {
        cin >> forgotten_words[i];
        frequency[forgotten_words[i]]  = 1;
    }


    for(int i = 1; i <= no_of_phrases; i++)
    {
        int no_of_words_in_phrase;
        cin >> no_of_words_in_phrase;

        for(int words = 1; words <= no_of_words_in_phrase; words++)
        {
            string word;
            cin >> word;

            frequency[word]++;
        }

    }

    for(int word = 0; word < no_of_forgotten_words; word++)
    {
        string answer = "NO";

        if(frequency[forgotten_words[word]] > 1)
            answer = "YES";

        cout << answer << (word < no_of_forgotten_words - 1 ? " " : "\n");
    }

}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
