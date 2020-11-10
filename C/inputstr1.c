#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* get_str(int* len) {
    char buf[81] = { 0 };
    char* res = NULL;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = *len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + *len, buf, chunk_len);
            *len = str_len;
        }
        else {
            scanf("%*c");
        }
    } while (n > 0);
    if (*len > 0) {
        res[*len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }

    return res;
}
void delChar(char inp[], char charToDel)
{
    char const* in = inp;
    char* out = inp;

    while (*in) {
        if (*in != charToDel)
            *out++ = *in;
        ++in;
    }

    *out = '\0';
}
int main()
{
    char* s = NULL;
    int len = 0;
    s = get_str(&len);
    if (strlen(s) > 0)
    {
        char seps[] = " ,\n";
        char* token;

        token = strtok(s, seps);
        while (token != NULL)
        {
            char* temp = token;
            delChar(token, -48);
            int print = 1;
            len = strlen(token);
            for (int i = 0; i < len / 2; i++)
            {
                if (token[i] != token[len - i - 1])
                {
                    print = 0;
                    break;
                }
            }
            if (print || len == 1)
            {
                printf("%s\n", temp);
            }
            token = strtok(NULL, seps);
        }
    }
    printf("\n");
    return 0;
}