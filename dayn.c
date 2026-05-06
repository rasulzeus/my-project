#include <stdio.h>
#include <string.h>
int main() {
    FILE *f = fopen("filename.txt", "r+");
    if (f == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    char line[1024];
    char lines[11][256];
    int i;
    int number;
    int k =0;
    while (fgets(line, sizeof(line), f) != NULL) {
        k++;
        line[strcspn(line, "\n")] = '\0';
        
        if (line[0] == '\0') {
            long empty_pos = ftell(f) - 1;
            
            printf("Введите число: ");
            scanf("%d", &number);
            
            fseek(f, empty_pos, SEEK_SET);
            fprintf(f, "%d\n\n", number);
            break;

        }
    }
    if (k==10) {
        rewind(f);
        for (i = 0; i < 11; i++) {
            if (fgets(lines[i], 256, f) == NULL) {
            strcpy(lines[i], "0");  // На случай ошибки
        }
            lines[i][strcspn(lines[i], "\n")] = '\0';
        }
        fclose(f);
        for (i = 0; i < 10; i++) {
            strcpy(lines[i], lines[i + 1]);
        }
        f = fopen("filename.txt", "w");
            if (f == NULL) {
                printf("Ошибка открытия файла для записи\n");
        return 1;
        }
            
        for (i = 0; i < 11; i++) {
        fprintf(f, "%s\n", lines[i]);
    }
    fclose(f);
    return 0;
}
}


