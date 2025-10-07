#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char str[1000];
    fgets(str, sizeof(str), stdin);

    // коэф для проверки вложености скобок во время пробежки по строке(если коэф меньше 0, вложенность нарушена)
    // открывающая скобка имеет коэф +1
    // закрывающая скобка имеет коэф -1
    int ratio = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
        {
            ratio++;

        }
        else if (str[i] == ')')
        {
            ratio -= 1;
        }
        if (ratio < 0)
        {
            printf("Баланса нет\n");
            return 0;
        }

    }

    // если после пробежки по строке коэф неравен 0, значит, количество открывающих и закрывающих скобок разное
    if (ratio == 0)
    {
        printf("Баланс есть\n");
    } else {
        printf("Баланса нет\n");
    }

    return 0;
}
