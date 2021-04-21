#include <stdio.h>
#include <string.h>

int main() {
    char string_input[100];
    puts("Masukkan kata/kalimat yang ingin diperiksa");
    scanf("%[^\n]", string_input);
    getchar();

    char string_reversed[strlen(string_input)];
    for (int i = strlen(string_input) - 1 ; i >= 0 ; i--) {
        static int reverse_index;
        *(string_reversed + reverse_index) = *(string_input + i);
        reverse_index++;
    }
    
    strcmp(string_input, string_reversed) == 0 ? puts("Kata/kalimat tersebut palindrom") :\
                                  puts("Bukan palindrom");
    
    getchar();
    return 0;
}