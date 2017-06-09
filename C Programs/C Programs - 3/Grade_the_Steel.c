#include <stdio.h>

#define true 1
#define false 0

void solve()
{
    const int minimum_hardness = 50, minimum_tensile_strength = 5600;
    const float maximum_carbon_content = 0.7;

    int hardness_met, carbon_content_met, tensile_strength_met;
    int hardness, tensile_strength;
    float carbon_content;

    scanf("%d %f %d",&hardness, &carbon_content, &tensile_strength);

    hardness_met = (hardness > minimum_hardness ? true : false);
    carbon_content_met = (carbon_content < maximum_carbon_content ? true : false);
    tensile_strength_met = (tensile_strength > minimum_tensile_strength ? true : false);

    if(hardness_met && carbon_content_met && tensile_strength_met)
        printf("%d\n",10);
    else if(hardness_met && carbon_content_met)
        printf("%d\n",9);
    else if(carbon_content_met && tensile_strength_met)
        printf("%d\n",8);
    else if(hardness_met && tensile_strength_met)
        printf("%d\n",7);
    else if(hardness_met || carbon_content_met || tensile_strength_met)
        printf("%d\n",6);
    else
        printf("%d\n",5);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    while(no_of_test_cases-- != 0)
        solve();

    return 0;
}
