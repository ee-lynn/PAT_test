#progrma warning (disable: 4996)
#include <stdio.h>
using namespace std;
int main()
{
    int g1,s1,k1;
    int g2,s2,k2;
    scanf("%d.%d.%d",g1,s1,k1);
    scanf("%d.%d.%d",g2,s2,k2);
    int g3,s3,k3;
    k3 = (k1+k2)%29;
    s3 = (s1+s2)+(k1+k2)/29;
    g3 = s3/17+g1+g2;
    s3 = s3%17;
    printf("%d.%d.%d\n",g3,s3,k3);
    return 0;
}