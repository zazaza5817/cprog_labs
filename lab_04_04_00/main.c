#include "my_string.h"

int main(void)
{
    char input_s[MAX_CHARS + 1];

    // printf("Input string: ");
    if (input(input_s) != 0)
    {
        return 1;
    }

    char input_ip[MAX_CHARS + 1];
    strip(input_s, input_ip);

    if (is_valid_ip(input_ip))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
