#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int long_a = 0;
    int long_b = 0;
    int chars_a[26] = { 0 }, chars_b[26] = { 0 }; // 26 letras en el abc

    for (int i = 0; a[i] != '\0'; i++) {
        if (chars_a[a[i] - 'a'] == 0) {
            chars_a[a[i] - 'a'] = 1;
            long_a++;
        }
    }

    for (int i = 0; b[i] != '\0'; i++) { // obteniendo letras unicas (rep. 1 vez)
        if (chars_b[b[i] - 'a'] == 0) {
            chars_b[b[i] - 'a'] = 1;
            long_b++;
        }
    }

    if (long_a == long_b) {
        return strcmp(a, b); // ordenar por alfabeto
    }
    return long_a - long_b;
}

int sort_by_length(const char* a, const char* b) {
    int long_a = strlen(a);
    int long_b = strlen(b);

    if (long_a == long_b) {
        return strcmp(a, b); // ordenar por alfabeto
    }
    return long_a - long_b;
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len; i++) { //bubble sort
        for (int j = 0; j < len - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                // swap
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}