#include <stdio.h>

typedef struct {
    char name[50];
    float rate;
}movie_properties;

void sorting_proc(movie_properties *movie, unsigned int banyak_line) {
    movie_properties temp;
    
    for (int i = 0 ; i < banyak_line ; i++)
        for (int j = 0 ; j < banyak_line - 1; j++)
            if (movie[j].rate > movie[j+1].rate) {
                temp = movie[j];
                movie[j] = movie[j+1];
                movie[j+1] = temp;
            }
}

int main() {
    FILE *movie_file, *ascending_file, *descending_file;
    movie_file = fopen("movie.txt", "r");
    ascending_file = fopen("ascending.txt", "w");
    descending_file = fopen("descending.txt", "w");
    
    unsigned int banyak_line = 0;
    char temp[50];

    while(fgets(temp, 50, movie_file)) banyak_line++;
    fseek(movie_file, 0, SEEK_SET);

    movie_properties movie[banyak_line];
    for (int i = 0 ; i < banyak_line ; i++)
        fscanf(movie_file, "%s %f", movie[i].name, &(movie[i].rate));
    
    sorting_proc(movie, banyak_line);

    for (int i = 0 ; i < banyak_line ; i++)
        fprintf(ascending_file, "%s %.1f\n", movie[i].name, movie[i].rate);
    fclose(ascending_file);

    for (int i = banyak_line - 1 ; i >= 0 ; i--)
        fprintf(descending_file, "%s %.1f\n", movie[i].name, movie[i].rate);
    fclose(descending_file);

    fclose(movie_file);
    return 0;
}