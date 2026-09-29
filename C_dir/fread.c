#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "usage: %s your_file", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *fp;
        char s[1024];
        fp = fopen(argv[i], "r");

        if(fp == NULL)
        {
            perror(argv[i]);
            continue;
        }

        while(fgets(s, sizeof s, fp) != NULL)
        {
            printf("%s",s);
        }

        fclose(fp);
    }
    return 0;
}