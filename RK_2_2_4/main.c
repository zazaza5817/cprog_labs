/*
Неделин Никита 26Б
*/

#include "process.h"

int main(void)
{
    point_t points[MAX_POINTS];
    size_t n;
    int rc = read_txt("first.txt", points, &n);
    if (rc != 0)
        return rc;

    size_t n_filtered;
    point_t points_filtered[MAX_POINTS];
    rc = process_points(points, points_filtered, n, &n_filtered);
    if (rc != 0)
        return rc;

    rc = save_points_to_file(points_filtered, n_filtered, "second.bin");
    if (rc != 0)
        return rc;

    rc = save_points_to_text_file("second.bin", "result.txt");
    if (rc != 0)
        return rc;

    return OK;
}