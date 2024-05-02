#include <stdio.h>
#include "tests.h"



int main(void)
{
    int result_diff = 0;
    result_diff += test_my_strpbrk();
    result_diff += test_my_strspn();
    result_diff += test_my_strcspn();
    result_diff += test_my_strchr();
    result_diff += test_my_strrchr();

    printf("result %d", result_diff);
    return 0;
}
