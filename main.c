#include <stdio.h>
#include "preprocessor.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./my_Preprocessor <input_file>\n");
        return 1;
    }

    preprocess(argv[1]);

    return 0;
}
