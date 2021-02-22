//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//    srand(time(NULL));	
//    int x;
//    scanf("%d", &x);
//    int prev = -1;
//    int chto = rand() % 4;
//    for (int i = 0; i < x; i++) {
//        char c;
//        //       char t;
//               //chto=rand()%3;
//        //       printf("Start %d \n%d %d %c %d\n",i,chto,prev,c, c);
//        int m;
//        if (chto == 0 && prev != -1 && prev != 0)m = 32;
//        //Bol
//        else if (chto == 1 && prev != 3) { m = rand() % 25 + 65; }
//        //Mal
//        else if (chto == 2 && prev != 3) { m = rand() % 25 + 97; }
//        //Cif
//        else if (chto == 3 && prev != 1 && prev != 2) { m = rand() % 10 + 48; }
//        else
//        {
//            i--;
//            chto = rand() % 4;
//            continue;
//        }
//
//        c = (char)m;
//        //       printf("%d %d %c %d\n",chto,prev,c, m);
//        //       printf("%c",c);
//        prev = chto;
//        chto = rand() % 4;
//        //       printf("%d %d %c %d\nEnd\n",chto,prev,c, c);
//        printf("%c", c);
//    }
//    printf("\n");
//    return 0;
//}
