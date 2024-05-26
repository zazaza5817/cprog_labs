#include <stdio.h>
#include <math.h>

#define NAME_LEN 3
#define MAX_POINTS 10

#define OK 0
#define FILE_OPEN_ERR -1
#define TOO_MUCH_POINTS -2
#define NO_FILTERED -3
#define ERROR_OPENING_BINARY_FILE -4
#define ERROR_OPENING -5

typedef struct
{
    char name[NAME_LEN + 1];
    double x;
    double y;
} point_t;

int read_txt(const char *src, point_t points[], size_t *n);
double calc_avg_distance(point_t points[], size_t n);
int process_points(point_t src[], point_t dst[], size_t n_src, size_t *n_dst);
int save_points_to_file(point_t *points, size_t n_filtered, const char *filename);
int save_points_to_text_file(const char *input_filename, const char *output_filename);
