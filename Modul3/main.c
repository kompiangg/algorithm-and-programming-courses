#include <stdio.h>

typedef struct {
    int baris, kolom;
} atribut_matriks;

void print_matriks(atribut_matriks atribut_A, atribut_matriks atribut_B, int A[atribut_A.baris][atribut_A.kolom],\
                    int B[atribut_B.baris][atribut_B.kolom]);

int main() {
    atribut_matriks atribut_A, atribut_B;

    puts("\n\t============================================");
    puts("\t= Kompiang Gede Sukadharma      2008561083 =");
    puts("\t============================================\n");
    puts("Masukkan ordo dari matriks pertama sesuai contoh");
    
    puts("Contoh : 3 x 3 (baris x kolom)");
    printf("Ordo : ");
    scanf("%d x %d", &atribut_A.baris, &atribut_A.kolom);
    getchar();
    
    puts("\nMasukkan ordo dari matriks kedua sesuai contoh");
    puts("Contoh : 3 x 3 (baris x kolom)");
    printf("Ordo : ");
    scanf("%d x %d", &atribut_B.baris, &atribut_B.kolom);
    getchar();
    
    while (atribut_A.baris != atribut_B.kolom) {
        puts("\nMohon maaf,\njumlah baris pada matriks A dan kolom pada Matriks B tidak sama");
        puts("Silakan masukkan kembali");
        puts("Contoh : 3 x 3 (baris x kolom)");
        printf("Ordo : ");
        scanf("%d x %d", &atribut_A.baris, &atribut_A.kolom);
        getchar();
        
        puts("\nMasukkan ordo dari matriks kedua sesuai contoh");
        puts("Contoh : 3 x 3 (baris x kolom)");
        printf("Ordo : ");
        scanf("%d x %d", &atribut_B.baris, &atribut_B.kolom);
        getchar();
    }

    int A[atribut_A.baris][atribut_A.kolom], B[atribut_B.baris][atribut_B.kolom];
    int hasil[atribut_A.baris][atribut_B.kolom];

    puts("\nSesi memasukkan nilai ke matriks A");
    for (int i = 0 ; i < atribut_A.baris ; i++) {
        for (int j = 0 ; j < atribut_A.kolom ; j++) {
            printf("\tMasukkan nilai pada [%d][%d] : ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
            getchar();
        }
    }

    puts("\nSesi memasukkan nilai ke matriks B");
    for (int i = 0 ; i < atribut_B.baris ; i++) {
        for (int j = 0 ; j < atribut_B.kolom ; j++) {
            printf("\tMasukkan nilai pada [%d][%d] : ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
            getchar();
        }
    }

    puts("\nMatriks yang akan dikalikan");
    print_matriks(atribut_A, atribut_B, A, B);



    puts("\nHasil dari perkalian matriks");
    for (int i = 0 ; i < atribut_A.baris ; i++)
        for (int j = 0 ; j < atribut_B.kolom ; j++)
            hasil[i][j] = 0;
    
    for (int i = 0 ; i < atribut_A.baris ; i++)
        for (int j = 0 ; j < atribut_B.kolom ; j++)
            for (int k = 0 ; k < atribut_A.kolom ; k++)
                hasil[i][j] += A[i][k] * B[k][j];

    for (int i = 0 ; i < atribut_A.baris ; i++) {
        printf("|%-4d", hasil[i][0]);
        for (int j = 1 ; j < atribut_B.kolom ; j++)
            printf(" %-4d", hasil[i][j]);
        printf("|");
        puts(" ");
    }
    getchar();

    return 0;
}

void print_matriks(atribut_matriks atribut_A, atribut_matriks atribut_B,\
                   int A[atribut_A.baris][atribut_A.kolom], int B[atribut_B.baris][atribut_B.kolom])
{    
    if (atribut_A.baris >= atribut_B.baris) {
        for (int i = 0 ; i < atribut_B.baris; i++) {
            printf("|");
            printf("%-3d", A[i][0]);
            for(int j = 1 ; j < atribut_A.kolom ; j++)
                printf(" %-3d", A[i][j]);
            printf("|");

            printf("|");
            printf("%-3d", B[i][0]);
            for(int j = 1 ; j < atribut_B.kolom ; j++)
                printf(" %-3d", B[i][j]);
            printf("|\n");
        }

        if (atribut_A.baris != atribut_B.baris) {
            printf("|");
            for (int i = 0 ; i < atribut_A.baris - atribut_B.baris ; i++) {
                printf("%-3d", A[i][0]);
                for(int j = 1 ; j < atribut_A.kolom ; j++)
                    printf(" %-3d", A[i][j]);
                printf("|\n");
            }
        }
    }

    else {
        for (int i = 0 ; i < atribut_A.baris; i++) {
            printf("|");
            printf("%-3d", A[i][0]);
            for(int j = 1 ; j < atribut_A.kolom ; j++)
                printf(" %-3d", A[i][j]);
            printf("| ");

            printf("|");
            printf("%-3d", B[i][0]);
            for(int j = 1 ; j < atribut_B.kolom ; j++)
                printf(" %-3d", B[i][j]);
            printf("|\n");
        }

        for (int i = 0 ; i < atribut_A.kolom * 4 + 2 ; i++)
            printf(" ");

        for (int i = 0 ; i < atribut_B.baris - atribut_A.baris ; i++) {
            printf("|");
            printf("%-3d", A[i][0]);
            for(int j = 1 ; j < atribut_B.kolom ; j++)
                printf(" %-3d", B[i][j]);
            printf("|\n");
        }
    }
}