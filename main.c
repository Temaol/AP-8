#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Input(char**, int kst);
void Output(char**, int kst);
int CheckString(char* str);
void ChangeArray(char** arr, int kst, char** arr_min, int* kst_min, char** arr_Plus, int* kst_plus);

int main()
{
    
    int kst;
    puts("Введіть кількість рядків яку хочете ввести");
    scanf("%d", &kst);
    rewind(stdin);
    char** arr = (char**)malloc(sizeof(char*) * kst);

    puts("Вводьте ваші дані");
    Input(arr, kst);

    char** arr_minus = (char**)malloc(sizeof(char*) * kst), ** arr_plus = (char**)malloc(sizeof(char*) * kst);
    int kst_minus = 0, kst_plus = 0;

    ChangeArray(arr, kst, arr_minus, &kst_minus, arr_plus, &kst_plus);

    puts("Додатні");
    Output(arr_minus, kst_minus);
    puts("Відємні");
    Output(arr_plus, kst_plus);

    for (int i = 0; i < kst; i++)
        free(arr[i]);
    free(arr);
    free(arr_plus);
    free(arr_minus);
    getchar();
    getchar();
    return 0;
}


void ChangeArray(char** arr, int kst, char** arr_min, int* kst_min, char** arr_Plus, int* kst_plus)
{
    int num;
    for (int i = 0; i < kst; i++)
    {
        num = CheckString(arr[i]);
        if (num > 0) {
            arr_min[*kst_min] = arr[i];
            *kst_min += 1;
        }
        else {
            arr_Plus[*kst_plus] = arr[i];
            *kst_plus += 1;
        }
    }

}


void Input(char** arr, int kst)
{
    char buf[500];
    for (int i = 0; i < kst; i++)
    {
        fgets(buf, 500, stdin);
        arr[i] = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
        strcpy(arr[i], buf);
    }
}

void Output(char** arr, int kst)
{
    for (int i = 0; i < kst; i++)
    {
        printf("%d) %d %s", i + 1, CheckString(arr[i]), arr[i]);
    }

}


int CheckString(char* str)
{
    char* p = str;
    int num = 0;
    int znak = 0;
    if (*p == '0')
        znak = 0;
    else
        znak = 1;
    p++;
    if (znak == 0)    //  +
    {
        while (*p != '\0' && *p != '\n')
        {
            num *= 2;
            if (*p == '0')
                num += 0;
            else
                num += 1;

            p++;
        }
        return num;
    }
    else         //        -
    {
        while (*p != '\0' && *p != '\n')
        {
            num *= 2;
            if (*p == '1')
                num += 0;
            else
                num += 1;

            p++;
        }
        return -(num + 1);
    }
}
