int    get_rows(char *filename)
{   
    int rows;
    int fd;

    rows = 0;
    fd = open(filename, O_RDONLY, 0);
    while (get_next_line(fd))
        rows++;
    close(fd);
    return(rows);
}

int get_colums(char *filename)
{
    int colums;
    int fd;
    char *line;

    fd = open(filename, O_RDONLY, 0);
    line = get_next_line(fd);
    colums = words_count();
    free(line);
    close(fd);
    return(colums);
}

void    fill_map(int *row, char *line)
{
    char **tmp;
    int i;

    i = 0;
    tmp = ft_split(line, ' ');
    while(tmp[i])
    {
        row[i] = ft_atoi(tmp[i]);
        free(tmp[i]);
        i++;
    }
    free(tmp);
}

void read_fdf(char *filename, t_fdf *fdf)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(filename, O_RDONLY, 0);
    fdf->rows = get_rows(filename);
    fdf->colums = get_colums(filename);
    fdf->map = (int **)malloc(sizeof(int *) * (fdf->rows + 1));
    while(i <= fdf->rows)
    {
        fdf->map[i] = (int *)malloc(sizeof(int) * (fdf->colums + 1));
        i++;
    }
    i = 0;
    while(line = get_next_line(fd) && line != NULL)
    {
        fill_map(fdf->map[i], line);
        free(line);
        i++;
    }
    free(line);
    fdf->map[i] = NULL;
    close(fd);
}