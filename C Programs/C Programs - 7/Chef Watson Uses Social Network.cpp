#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

#define MAX_LENGTH 100 + 1

using namespace std;

struct post
{
    bool is_special;
    int id;
    int popularity;
    char content[MAX_LENGTH];


};

bool Compare_Posts(post const&A, post const&B)
{
    if(A.is_special == true && B.is_special == false)
        return true;
    else if(A.is_special == false && B.is_special == true)
        return false;

    if(A.popularity > B.popularity) //More popular one comes first
        return true;
    else if(A.popularity < B.popularity)
        return false;
}

int main()
{
    int no_of_special_friends, no_of_posts;
    scanf("%d %d", &no_of_special_friends, &no_of_posts);

    set <int> special_friends;
    for(int i = 1; i <= no_of_special_friends; i++)
    {
        int special_i;
        scanf("%d", &special_i);
        special_friends.insert(special_i);
    }

    vector <post> posts(no_of_posts); //Important to construct the vector first or the [] operator cannot access a location not existing.
    for(int i = 0; i < no_of_posts; i++)
    {
        scanf("%d %d %s",&posts[i].id, &posts[i].popularity, posts[i].content);

        posts[i].is_special = (special_friends.count(posts[i].id) == 1 ? true : false);
    }

    sort(posts.begin(), posts.end(), &Compare_Posts);

    for(int i = 0; i < no_of_posts; i++)
    {
        printf("%s\n",posts[i].content);
    }

    return 0;
}

