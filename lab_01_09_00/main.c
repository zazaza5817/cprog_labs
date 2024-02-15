#include <stdio.h>
#include <math.h>


float get_f_value(void)
{
    float result = 0;
    float input;
    int n = 0;
    int scan_result;
    float new_term;

    printf("enter first x: ");
    scan_result = scanf("%f", &input);
    if (scan_result != 1)
    {
        printf("only float must be inputted");
        return -1;
    }

    while (input >= 0)
    {
        n += 1;
        new_term = input / n;
        result += new_term;

        printf("enter next x: ");
        scan_result = scanf("%f", &input);
        if (scan_result != 1)
        {
            printf("only float must be inputted");
            return -1;
        }
    }
    return result;
}


int main(void)  
{
    float result;
    result = get_f_value();
    if (result < 0)
    {
        return 1;
    }
    printf("Result: %.6lf", sqrtf(result));
    return 0;
}
