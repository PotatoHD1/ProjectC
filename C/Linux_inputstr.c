//#define _CRT_SECURE_NO_WARNINGS
// ���� �20-901
//������ ������ �� ���������� ���������� ����. ����� �������� � 
//������ ����� �������. ����� � ������ ����� � ���������� (�����������), 
//��������, ����� ��� ���.

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//char* get_str(int* len) {
//    char buf[81] = { 0 };
//    char* res = NULL;
//    int n = 0;
//    do {
//        n = scanf("%80[^\n]", buf);
//        if (n < 0) {
//            if (!res) {
//                return NULL;
//            }
//        }
//        else if (n > 0) {
//            int chunk_len = strlen(buf);
//            int str_len = *len + chunk_len;
//            res = realloc(res, str_len + 1);
//            memcpy(res + *len, buf, chunk_len);
//            *len = str_len;
//        }
//        else {
//            scanf("%*c");
//        }
//    } while (n > 0);
//    if (*len > 0) {
//        res[*len] = '\0';
//    }
//    else {
//        res = calloc(1, sizeof(char));
//    }
//
//    return res;
//}
//int main()
//{
//    char* s = NULL;
//    int len = 0;
//    do {
//        printf("������� ������:\n");
//        s = get_str(&len);
//        printf("����������: ");
//        if (len > 0)
//        {
//            char seps[] = ", \0";
//            char* token;
//
//            token = strtok(s, seps);
//            while (token != NULL)
//            {
//                int i;
//                int print = 1;
//                len = strlen(token);
//
//                for (i = 0; i < len / 2; i++)
//                {
//                    if (token[i] != token[len - i - 1])
//                    {
//                        print = 0;
//                        break;
//                    }
//                }
//                if (print || len == 1)
//                {
//                    printf("%s ", token);
//                }
//                token = strtok(NULL, seps);
//            }
//
//            printf("\n");
//        }
//        len = 0;
//        free(s);
//    } while (s);
//    return 0;
//}