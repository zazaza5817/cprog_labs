#include "process.h"

int read_txt(const char *src, point_t points[], size_t *n)
{
    FILE *fp = fopen(src, "r");
    if (!fp)
        return FILE_OPEN_ERR;
    *n = 0;
    while (fscanf(fp, "%3s %lf %lf", points[*n].name, &points[*n].x, &points[*n].y) == 3)
    {
        (*n)++;
        if (*n > MAX_POINTS)
        {
            return TOO_MUCH_POINTS;
        }
    }
    fclose(fp);
    return OK;
}

double calc_avg_distance(point_t points[], size_t n)
{
    double sum = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        sum += sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
    }
    return sum / n;
}

int process_points(point_t src[], point_t dst[], size_t n_src, size_t *n_dst)
{
    double avg_distance = calc_avg_distance(src, n_src);
    *n_dst = 0;
    for (size_t i = 0; i < n_src; i++)
    {
        double distance = sqrt(src[i].x * src[i].x + src[i].y * src[i].y);
        if (distance < avg_distance)
        {
            dst[(*n_dst)++] = src[i];
        }
    }
    if (*n_dst == 0)
        return NO_FILTERED;
    return OK;
}

int save_points_to_file(point_t *points, size_t n_filtered, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return ERROR_OPENING_BINARY_FILE;
    }
    fwrite(points, sizeof(point_t), n_filtered, file);
    fclose(file);
    return OK;
}

int save_points_to_text_file(const char *input_filename, const char *output_filename)
{
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL)
    {
        return ERROR_OPENING;
    }
    point_t point;
    while (fread(&point, sizeof(point_t), 1, input_file) == 1)
    {
        fprintf(output_file, "%s: (%lf, %lf)\n", point.name, point.x, point.y);
    }
    fclose(input_file);
    fclose(output_file);
    return OK;
}