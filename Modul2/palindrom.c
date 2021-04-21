#include <stdio.h>

int main() {
    unsigned int angka_input, angka_input_dibalik = 0;
    printf("Masukkan angka yang ingin dicek : ");
    scanf("%u", &angka_input);
    unsigned int var_bantu = angka_input;

    while (var_bantu != 0) {
        angka_input_dibalik *= 10;
        angka_input_dibalik += var_bantu % 10;
        var_bantu /= 10;
    }

    angka_input_dibalik == angka_input ? printf("%u adalah bilangan palindrom", angka_input):\
                                         printf("%u bukan bilangan palindrom", angka_input);

    getchar();
    getchar();
    return 0;
}