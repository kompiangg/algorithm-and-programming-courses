#include <stdio.h>
#include <string.h>

int monthToNumber(char* month_born);

int main() {
    int year_now = 2021, date_now = 16, month_now = 2;
    int year_born, date_born, month_born_number, umur;
    char name[50], nim[20], class, address[75];
    char handphone_number[13], month_born[10];

    printf("Nama: ");
    scanf("%[^\n]", name);
    getchar();

    printf("NIM: ");
    scanf("%s", nim);
    getchar();

    printf("Kelas: ");
    scanf("%c", &class);
    getchar();

    printf("Alamat: ");
    scanf("%[^\n]", address);
    getchar();

    printf("No HP: ");
    scanf("%s", handphone_number);
    getchar();

    printf("Tanggal Lahir (dd month yyyy): ");
    scanf("%d %s %d", &date_born, month_born, &year_born);
    getchar();

    puts(" ");
    puts("===============================\
        Terima kasih\
        ===============================");
    puts(" ");

    printf("Nama: %s\n", name);
    printf("NIM: %s\n", nim);
    printf("Kelas: %c\n", class);
    printf("Alamat: %s\n", address);
    printf("No HP: %s\n", handphone_number);
    printf("Tanggal Lahir: %d %s %d\n", \
            date_born, month_born, year_born);
    
    umur = 2021 - year_born;
    if ((2 - monthToNumber(month_born)) < 0)
        umur = umur - 1; 
    else if ((2 - monthToNumber(month_born)) == 0) {
        if ((16 - date_born) < 0)
            umur = umur - 1;
    }
        
    printf("Umur: %d", umur);

    getchar();
    return 0;
}

int monthToNumber(char* month_born) {
    if (!strcmp(month_born,"Januari")) {
        return 1;
    }
    else if (!strcmp(month_born,"Februari")) {
        return 2;
    }
    else if (!strcmp(month_born,"Maret")) {
        return 3;
    }
    else if (!strcmp(month_born,"April")) {
        return 4;
    }
    else if (!strcmp(month_born,"Mei")) {
        return 5;
    }
    else if (!strcmp(month_born,"Juni")) {
        return 6;
    }
    else if (!strcmp(month_born,"Juli")) {
        return 7;
    }
    else if (!strcmp(month_born,"Agustus")) {
        return 8;
    }
    else if (!strcmp(month_born,"September")) {
        return 9;
    }
    else if (!strcmp(month_born,"Oktober")) {
        return 10;
    }
    else if (!strcmp(month_born,"November")) {
        return 11;
    }
    else if (!strcmp(month_born,"Desember")) {
        return 12;
    }
}