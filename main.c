#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30], surname[30], gender[30];
    unsigned short year_birth, height;
} people;

people sorting(const char option[20], people *list, unsigned short n) {
    switch (option[0]) {
        case 'n': {
            for (unsigned short i = 0; i < n; i++) {
                for (unsigned short j = 0; j < n - 1; j++) {
                    if (strcmp(list[j].name, list[j+1].name) > 0) {
                        people change = list[j];
                        list[j] = list[j+1];
                        list[j+1] = change;
                    }
                }
            }
            return *list;
            break;
        }
        case 's': {
            for (unsigned short i = 0; i < n; i++) {
                for (unsigned short j = 0; j < n - 1; j++) {
                    if (strcmp(list[j].surname, list[j+1].surname) > 0) {
                        people change = list[j];
                        list[j] = list[j+1];
                        list[j+1] = change;
                    }
                }
            }
            return *list;
            break;
        }
        case 'b': {
            for (unsigned short i = 0; i < n; i++) {
                for (unsigned short j = 0; j < n - 1; j++) {
                    if (list[j].year_birth > list[j+1].year_birth) {
                        people change = list[j];
                        list[j] = list[j+1];
                        list[j+1] = change;
                    }
                }
            }
            return *list;
            break;
        }
        case 'g': {
            for (unsigned short i = 0; i < n; i++) {
                for (unsigned short j = 0; j < n - 1; j++) {
                    if (strcmp(list[j].gender, list[j+1].gender) > 0) {
                        people change = list[j];
                        list[j] = list[j+1];
                        list[j+1] = change;
                    }
                }
            }
            return *list;
            break;
        }
        case 'h': {
            for (unsigned short i = 0; i < n; i++) {
                for (unsigned short j = 0; j < n - 1; j++) {
                    if (list[j].height > list[j+1].height) {
                        people change = list[j];
                        list[j] = list[j+1];
                        list[j+1] = change;
                    }
                }
            }
            return *list;
            break;
        }
    }
}

int main() {
    system("chcp 65001");

    FILE *f;
    f = fopen("people.txt", "r");
    if (f == NULL) {
        printf("Ошибка открытия файла для чтения");
        return -1;
    }

    unsigned short n = 0;
    while (!feof(f)) if (fgetc(f) == '\n') n++;
    n++;
    people list[n];
    fseek(f,0,SEEK_SET);

    for (unsigned short i = 0; i < n; i++) fscanf(f, "%s %s %hu %s %hu", list[i].surname, list[i].name, &list[i].year_birth, list[i].gender, &list[i].height);
    fclose(f);
    for (unsigned short i = 0; i < n; i++) printf("%s %s %hu %s %hu\n", list[i].surname, list[i].name, list[i].year_birth, list[i].gender, list[i].height);
    printf("= = = = = = = = = = = = = = = = = = = =\n\n");

    char option[20] = "";
    printf("Опции: name surname birth gender height\n\n");
    do {
        printf("По какому полю хотите сортировать?");
        scanf("%s", option);}
    while ((strcmp(option, "name") != 0) && (strcmp(option, "surname") != 0) && (strcmp(option, "birth") != 0) && (strcmp(option, "gender") != 0) && (strcmp(option, "height") != 0));
    sorting(option, list, n);
    printf("Отсортированный список людей по параметру: %s\n\n", option);

    FILE *fw;
    fw = fopen("people_sorted.txt", "w");
    if (fw == NULL) {
        printf("Ошибка открытия файла для записи");
        return -2;
    }
    for (unsigned short i = 0; i < n; i++) fprintf(fw,"%s %s %hu %s %hu\n", list[i].surname, list[i].name, list[i].year_birth, list[i].gender, list[i].height);
    fclose(fw);
    for (unsigned short i = 0; i < n; i++) printf("%s %s %hu %s %hu\n", list[i].surname, list[i].name, list[i].year_birth, list[i].gender, list[i].height);

    return 0;
}