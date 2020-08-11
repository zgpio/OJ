#include <cstdio>
int main()
{
    short a = 65;
    char b;
    b = char(a);
    printf("%c\n", a);

    if (b == 'A')
        printf("小端\n");
    else
        printf("大端\n");

    return 0;
}
