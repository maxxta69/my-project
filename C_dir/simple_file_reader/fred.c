#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //VERIFY THE ARGUMENT PASSED BY USER
    if(argc < 2)
    {
        printf("ERROR: Invalid/No argument was passed\n");
        return 1;
    }

    //SET FILE POINTER, BUFFER, LINECOUNT
    FILE *fp;
    char s[1024];
    int linecount = 0;

    //OPEN FILE YOU WANT TO READ FROM
    fp = fopen(argv[1], "r");

    //LOOP THROUGH THE CONTENT OF THE FILE AND READ IT LINE BY LINE
    while(fgets(s, sizeof s, fp) != NULL)
    {
        printf("%d: %s", ++linecount, s);
    }

    //CLOSE THE FILE WHEN DONE
    fclose(fp);

    return 0;
}