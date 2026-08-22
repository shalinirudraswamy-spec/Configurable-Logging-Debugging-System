#include <stdio.h>
#include <string.h>
#include "preprocessor.h"

#define MAX 100

struct Macro
{
    char name[50];
    char value[100];
};

void remove_comments(char *line, int *comment)
{
    char temp[MAX];
    int i = 0;
    int j = 0;

    while (line[i] != '\0')
    {
        if (*comment)
        {
            if (line[i] == '*' && line[i + 1] == '/')
            {
                *comment = 0;
                i = i + 2;
            }
            else
            {
                i++;
            }
        }
        else
        {
            if (line[i] == '/' && line[i + 1] == '/')
            {
                break;
            }
            else if (line[i] == '/' && line[i + 1] == '*')
            {
                *comment = 1;
                i = i + 2;
            }
            else
            {
                temp[j] = line[i];
                j++;
                i++;
            }
        }
    }

    temp[j] = '\0';
    strcpy(line, temp);
}

void substitute(char *line, struct Macro m[], int count)
{
    char result[MAX];
    char *p;
    int i;

    for (i = 0; i < count; i++)
    {
        result[0] = '\0';

        while ((p = strstr(line, m[i].name)) != NULL)
        {
            *p = '\0';

            strcat(result, line);
            strcat(result, m[i].value);

            strcpy(line, p + strlen(m[i].name));
        }

        strcat(result, line);
        strcpy(line, result);
    }
}

void preprocess(char *filename)
{
    FILE *fp;
    FILE *out;

    char line[MAX];
    char output[100];

    struct Macro macros[20];

    int macro_count = 0;
    int comment = 0;
    int i;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Input file cannot be opened.\n");
        return;
    }

    strcpy(output, filename);

    for (i = 0; output[i] != '\0'; i++)
    {
        if (output[i] == '.')
        {
            output[i + 1] = 'i';
            output[i + 2] = '\0';
            break;
        }
    }

    out = fopen(output, "w");

    if (out == NULL)
    {
        printf("Output file cannot be created.\n");
        fclose(fp);
        return;
    }

    while (fgets(line, MAX, fp) != NULL)
    {
        /* Task 1: Remove comments */
        remove_comments(line, &comment);

        if (line[0] == '\0' || line[0] == '\n')
            continue;

        /* Task 2: Header file inclusion */
        if (strncmp(line, "#include", 8) == 0)
        {
            fputs(line, out);
            continue;
        }

        /* Task 3: Macro substitution */
        if (strncmp(line, "#define", 7) == 0)
        {
            if (sscanf(line, "#define %49s %99s",
                       macros[macro_count].name,
                       macros[macro_count].value) == 2)
            {
                macro_count++;
            }

            continue;
        }

        substitute(line, macros, macro_count);

        fputs(line, out);
    }

    fclose(fp);
    fclose(out);

    printf("Input  : %s\n", filename);
    printf("Output : %s\n", output);
    printf("Preprocessing completed.\n");
}
