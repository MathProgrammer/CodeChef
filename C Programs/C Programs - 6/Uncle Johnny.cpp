#include <iostream>
#define MAX_SONGS 100 + 1

using namespace std;

void solve()
{
    int no_of_songs, johnny_song_position, i, johnny_song_final_position, johnny_song_length, length_of_song[MAX_SONGS];
    int no_of_shorter_songs = 0;

    cin >> no_of_songs;
    for(i = 1; i <= no_of_songs; i++)
        cin >> length_of_song[i];

    cin >> johnny_song_position;
    johnny_song_length = length_of_song[johnny_song_position];

    for(i = 1; i <= no_of_songs; i++)
        no_of_shorter_songs += (length_of_song[i] < johnny_song_length);

    johnny_song_final_position = no_of_shorter_songs + 1;

    cout << johnny_song_final_position << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
