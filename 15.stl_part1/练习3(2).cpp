// #include <iostream>
// #include <algorithm>

// using namespace std;

// int main(){
//     int arr[]={1,2,3,4,5,6,7,8,9};
//     int count1=count_if(arr,arr+9,bind2nd(greater<int>(),3));
//     cout<<count1<<endl;
//     int count2=count_if(arr,arr+9,bind1st(greater<int>(),3));
//     cout<<count2<<endl;
//     int count3=count_if(arr,arr+9,not1(bind1st(greater<int>(),3)));
//     cout<<count3<<endl;
//     return 0;
// }

// #include <stdio.h>

// int calculatePrice(int price);
// int main()
// {

//     int finalPrice = calculatePrice(6);
//     printf("Tina bought 1 kg of potato by paying s%d", finalPrice);
// }

// int calculatePrice(int price)
// {
//     if (price < 10 && price > 0)
//     {
//         return price + 1 * calculatePrice(price + 1);
//     }
//     else
//     {
//         return 0;
//     }
// }

// #include <stdio.h>

// int main()
// {
//     int n[] = {5.4, 2.3, 4, 4.8, 5};
//     int i, *p = n, *q = n;
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d", *n);
//         ++q;
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d", *p);
//         ++p;
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maxmarks(int input1, int input2[])
{
    // 对分数进行排序
    qsort(input2, input1, sizeof(int), compare);

    int minTotalScore = 0;
    for (int i = 0; i < input1; i++)
    {
        minTotalScore += input2[i] * (input1 - i);
    }

    return minTotalScore;
}

int main()
{
    int input1;
    scanf("%d", &input1);

    int input2[input1];
    for (int i = 0; i < input1; i++)
    {
        scanf("%d", &input2[i]);
    }

    int result = maxmarks(input1, input2);
    printf("%d\n", result);

    return 0;
}
