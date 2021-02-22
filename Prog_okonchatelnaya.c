//Колб Вера Б20-901
//Сортировать шейкером и пузырьком по фамилиям;
//найти студентов, средний балл которых находится в заданном диапазоне значений

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct data {
    char surname[60];
    int group;
    double mark;
    struct data* Next;
    struct data* Prev;
} data;

data* Head = NULL;
data* Last = NULL;

int  Add(char surname[60], int group, float mark) {

    data* r = (data*)malloc(sizeof(data));
    if (!r) return -1;
    memcpy(r->surname, surname, sizeof(r->surname));
    r->group = group;
    r->mark = mark;
    r->Next = 0;
    r->Prev = 0;
    if (Last) { Last->Next = r; r->Prev = Last; }
    if (!Head) Head = r;
    Last = r;
    return 0;
}


void Clear() {
    if (!Head) return;
    for (Last = Head->Next; Last; Last = Last->Next) {
        Last->Prev = NULL;
        Head = Last;
    }
    Head = NULL;
}

void swap(data* lst1, data* lst2)
{
    data* prev1, * prev2, * next1, * next2;
    prev1 = lst1->Prev;  // узел предшествующий lst1
    prev2 = lst2->Prev;  // узел предшествующий lst2
    next1 = lst1->Next; // узел следующий за lst1
    next2 = lst2->Next; // узел следующий за lst2
    if (lst2 == next1)  // обмениваются соседние узлы
    {
        lst2->Next = lst1;
        lst2->Prev = prev1;
        lst1->Next = next2;
        lst1->Prev = lst2;
        if (next2 != NULL)
            next2->Prev = lst1;
        if (lst1 != Head)
            prev1->Next = lst2;
    }
    else if (lst1 == next2)  // обмениваются соседние узлы
    {
        lst1->Next = lst2;
        lst1->Prev = prev2;
        lst2->Next = next1;
        lst2->Prev = lst1;
        if (next1 != NULL)
            next1->Prev = lst2;
        //else Last = lst2;
        if (lst2 != Head)
            prev2->Next = lst1;
       // else Head = lst1;
    }
    else  // обмениваются отстоящие узлы
    {
        if (lst1 != Head)  // указатель prev можно установить только для элемента,
            prev1->Next = lst2; // не являющегося корневым
        lst2->Next = next1;
        if (lst2 != Head)
            prev2->Next = lst1;
        lst1->Next = next2;
        lst2->Prev = prev1;
        if (next2 != NULL) // указатель next можно установить только для элемента,
            next2->Prev = lst1; // не являющегося последним
        lst1->Prev = prev2;
        if (next1 != NULL)
            next1->Prev = lst2;


    }
    if (lst1 == Head) Head = lst2;
    else if (lst2 == Head) Head = lst1;
    if (lst1 == Last) Last = lst2;
    else if (lst2 == Last) Last = lst1;

}

void sort() {
    data* left = Head;                 //Первый элемент — это пусть будет голова
    data* right = Head->Next;          //Второй элемент — это пусть будет следующий за головой элемент
    data* right_swap;

    while (left->Next) {                 //Обходим по всем звеньям, за исключением крайнего правого
        while (right) {              //Обходим по всем звеньям, включая крайний правый (по всем относительно первого левого на текущий момент)
            if (((left->surname[1]) > (right->surname[1]))||(((left->surname[1]) == (right->surname[1]))&&((left->surname[3]) > (right->surname[3])))) {        //Проверяем необходимость перестановки
                swap(left, right);
                right_swap = right;
                right = left->Next;
                left = right_swap;//иначе бы  нужно было это проделывать для каждого несвязующего элемента
            }
            else right = right->Next;
            //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
        }
        left = left->Next;                              //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
        right = left->Next;                             //Поскольку второй указатель убежал немного вперёд, обязательно возвращаем его назад, это следующий элемент относительно текущего первого
    }
}


int sort_range(float min, float max) {
    int i = 0;
    data* last;
    FILE* file_write;
    file_write = fopen("Result.txt", "a");
    fprintf(file_write, "Студенты со средним баллом в диапазоне от %f до %f : \n", min, max);
    printf("Студенты со средним баллом в диапазоне от %f до %f : \n", min, max);
    if (min > max) {
        printf("Веден некорректный диапазон\n");
        fprintf(file_write, "Веден некорректный диапазон \n");
        fclose(file_write);
        return 0;
    }
    for (last = Head; last; last = last->Next) {
        if ((last->mark >= min) && (last->mark <= max)) {
            printf("%s \n", last->surname);
            fprintf(file_write, "%s \n", last->surname);
            i = 1;
        }
    }
    if (i == 0) {
        printf("Таких студентов не найдено\n");
        fprintf(file_write, "Таких студентов не найдено\n");
    }
    fclose(file_write);
    return 0;
}


void shekerSort()
{
    data* left = Head;
    data* right = Last; // левая и правая границы сортируемой области структуры
    data* left_swap, * right_swap; // дополнительные переменные для обмена
    data* left_mem = left, * right_mem = right; // текущие значения
    data* left_next, * right_prev; // следующее и предыдущее значения для текущего
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой и пока имеются перемещения
    while ((left != right) && flag > 0)
    {
        flag = 0;
        left_next = left_mem->Next;
        for (left_mem = left; left_mem != right; left_mem = left_mem->Next)
        {
            if ((left_next)&&( (left_mem->surname[1]) > (left_next->surname[1])||((left_mem->surname[1]) == (left_next->surname[1])&&(left_mem->surname[3]) > (left_next->surname[3])))) // если следующий элемент меньше текущего, меняем их местами
            {
                swap(left_mem, left_next);
                left_swap = left_next;
                left_next = left_mem->Next;
                left_mem = left_swap;
                if ((left_next) && (left == left_next->Prev)) left = left_mem; // меняем значение левой границы, если оно поменялось
                if (right == left_mem) right = left_mem->Next; // меняем значение правой границы, если оно поменялось
                flag = 1;      // перемещения в этом цикле были
            }
            else if (left_next) left_next = left_next->Next; // сдвигаем на слудущее значение
        }
        right->Prev; // сдвигаем правую границу на предыдущий элемент
        right_prev = right->Prev;
        for (right_mem = right; right_mem != left; right_mem = right_mem->Prev)  //двигаемся справа налево
        {
            if ((right_prev) &&( (right_mem->surname[1]) < (right_prev->surname[1])||((right_mem->surname[1]) == (right_prev->surname[1])&&(right_mem->surname[3]) < (right_prev->surname[3]))))// если предыдущий элемент больше текущего, меняем их местами
            {
                swap(right_prev, right_mem);
                right_swap = right_prev;
                right_prev = right_mem->Prev;
                right_mem = right_swap;
                if ((right_prev) && (right == right_prev->Next)) right = right_mem;
                if (left == right_mem) left = right_mem->Prev;
                flag = 1;    // перемещения в этом цикле были
            }
            else if (right_prev) right_prev = right_prev->Prev;
        }
        left->Next; // сдвигаем левую границу на следующий элемент
    }
}

void Write(int i) {
    data* last;
    for (last = Head; last; last = last->Next) {
      if (i==1)  printf("%s \n", last->surname);
      else printf("%s ", last->surname);
        printf("%d \n", last->group);
        printf("%1.1f \n", last->mark);
    }
}

void Write_file(int i) {
    FILE *file_write;
    file_write = fopen("Result.txt", "a");
    data* last;
    for (last = Head; last; last = last->Next) {
        if (i==1) fprintf(file_write, "%s \n", last->surname);
        else fprintf(file_write, "%s", last->surname);
        fprintf(file_write, "%d \n", last->group);
        fprintf(file_write, "%1.1f \n", last->mark);
    }
    fclose(file_write);
}

int main()
{
    int in, count, i, stan, cont3, type, cont4;
    char s[60];
    int g;
    int j = 1;
    float m, min, max;
    int cont1 = 1;
    int cont2 = 1;
    int first_open = 1;
    int inf;
    clock_t t;
    FILE* file, *fp, *file_write ;
    do {
        inf = 0;
        printf("Укажите способ ввода (1 - файл, 2 - вручную, 3 - случайные значения) : ");
        scanf("%d", &in);
        switch (in) {
        case 1:
        type = 1;
            if ((file = fopen("Test.txt", "r"))==NULL) {
               printf("Не удалось открыть файл\n");
               break;
            }
            else
            {
                while (fscanf(file, "%s%d%f", s, &g, &m) != EOF)
                {
                    Add(s, g, m);
                    inf = 1;
                }
                if (inf == 0) printf("Файл пустой\n");
            }
            fclose(file);
            break;
        case 2:
            type = 1;
            do {
                printf("Введите фамилию: ");
                scanf("%59s", s);
                printf("Введите номер группы: ");
                scanf("%d", &g);
                printf("Введите балл: ");
                scanf("%f", &m);
                Add(s, g, m);
                inf = 1;
                printf("Чтобы ввести еще данные введите 1(в другом случае любое число): ");
                scanf("%d", &cont2);
            } while (cont2 == 1);
            break;
        case 3:
              type = 0;
              srand(time(NULL));
              printf("Введите количество студентов: ");
              scanf("%d", &count);
              if (count < 1) {
                printf("Неверное число\n");
                break;
              }
              for(i = 0; i < count; i++ ){
                stan = 1 + rand() % 251337;
                fp = fopen("Surname.txt", "r");
                if (!fp){
                  printf("Не удалось открыть файл c фамилиями\n");
                  break;
                }
                j = 1;
                while(j<=stan) {
                  fgets(s, 58, fp);
                   j++;
                }
                fclose(fp);
                Add(s, rand() % 100 + 1, rand() % 5 + 0.1 * (rand() % 11));
                inf = 1;
              }
            break;
        default:
            printf("Введено неверное число\n");
            break;
        }
        if (inf == 1) {
        printf ("Введенные данные: \n");
        Write(type);
        if(first_open == 1)  file_write = fopen("Result.txt", "w");
        else file_write = fopen("Result.txt", "a");
        fprintf (file_write,"Введенные данные: \n");
        fclose(file_write);
        Write_file(type);
        file_write = fopen("Result.txt", "a");
        fprintf (file_write,"Отсортированные данные: \n");
        fclose(file_write);
        printf ("Выберите метод сортировки(1 - Шейкером, 2 - Пузырьком):  \n");
        scanf("%d", &cont4);
        switch(cont4){
          case 1:
            t = clock();
            shekerSort();
            t = clock() - t;
            break;
          case 2:
            t = clock();
            sort();
            t = clock() - t;
            break;
          default:
            printf("Введено неверное число\n");
            break;
        }
        printf("Отсортированные данные:\n");
        Write(type);
        Write_file(type);
        printf ("Сортировка заняла %8lf секунд\n", ((double)t)/CLOCKS_PER_SEC);
        file_write = fopen("Result.txt", "a");
        fprintf (file_write,"Сортировка заняла %8lf секунд\n", ((double)t)/CLOCKS_PER_SEC);
        fclose(file_write);
        printf("Для задания диапазона среднего балла введите 1(в другом случае любое число): ");
        scanf("%d", &cont3);
        if(cont3==1){
          printf("Введите нижнюю границу диапазона: ");
          scanf("%f", &min);
          printf("Введите верхнюю границу диапазона: ");
          scanf("%f", &max);
          sort_range(min, max);
        }
        Clear();
        printf("Чтобы продолжить введите 1(в другом случае любое число): ");
        scanf("%d", &cont1);
        first_open = 0;
      }
    } while (cont1 == 1);

    return 0;
}
