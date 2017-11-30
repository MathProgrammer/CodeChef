#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

void solve()
{
    int no_of_songs;
    scanf("%d", &no_of_songs);

    long long total_length = 0;
    map <int, int> shortest_song;

    for(int i = 0; i < no_of_songs; i++)
    {
        int singer,length;
        scanf("%d %d", &singer, &length);

        total_length += length;

        if(shortest_song[singer] == 0)
            shortest_song[singer] = length;

        shortest_song[singer] = min(shortest_song[singer], length);
    }

    vector <long long> shortest_songs;
    for(map <int, int> :: iterator it = shortest_song.begin(); it != shortest_song.end(); it++)
    {
        shortest_songs.push_back(it->second);
    }

    sort(all(shortest_songs));

    long long length_of_shortest_songs = 0, total_sweetness = 0;

    int no_of_singers = shortest_songs.size();
    for(int i = 0; i < no_of_singers; i++)
    {
        total_sweetness += (i + 1)*shortest_songs[i];
        length_of_shortest_songs += shortest_songs[i];
    }

    total_sweetness += (total_length - length_of_shortest_songs)*no_of_singers;

    printf("%lld\n", total_sweetness);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
