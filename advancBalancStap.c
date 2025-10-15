#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void balance(char* str)
{
    // флаг для вложенности
    bool flagEnclosure = true;

    // счетчик для ()
    int countParentheses = 0;

    // счетчик для {}
    int countBraces = 0;

    // счетчик для []
    int countBrackets = 0;

    // флаг, чтобы проверять,что закрылась та скобка, которая последней открывалась
    // каждому виду скобок дано значение от 1 до 3, если скобка открывается, флагу дается соответствующее значение
    // когда скобка закрывается, проверяем что флаг минус значение флага для этой скобке равно нулю
    // то есть закрывается та скобка, которая открывалась, иначе даем счетчику данного вида скобок отрицательное значение
    int flagCloseStap = 0;

    // коэф для проверки вложености скобок во время пробежки по строке(если коэф меньше 0, вложенность нарушена)
    // открывающая скобка имеет коэф +1
    // закрывающая скобка имеет коэф -1
    for (int i = 0; i < strlen(str); i++) {
        switch (str[i]) {
        case '(':
            countParentheses++;
            flagCloseStap = 1;
            break;
        case ')':
            countParentheses--;
            if (flagCloseStap - 1 != 0) {
                countParentheses = -1;
            }

            break;
        case '{':
            countBraces++;
            flagCloseStap = 2;
            break;
        case '}':
            countBraces--;
            if (flagCloseStap - 2 != 0) {
                countBraces = -1;
            }
            break;
        case '[':
            countBrackets++;
            flagCloseStap = 3;
            break;
        case ']':
            countBrackets--;
            if (flagCloseStap - 3 != 0) {
                countBrackets = -1;
            }
            break;
        }

        // если где-то в строке не сохранялась вложенность скобок один из счетчиков стал равен -1
        // тогда при прибавлении 1, один из множителей станет равен нулю, соответственно все
        // произведение станет равно нулю
        if ((countParentheses + 1) * (countBraces + 1) * (countBrackets + 1) == 0) {
            flagEnclosure = false;
            break;
        }
    }

    // если после пробежки по строке коэф неравен 0, значит, количество открывающих и закрывающих скобок разное
    if (countParentheses + countBraces + countBrackets == 0 && flagEnclosure) {
        printf("Баланс есть\n");
    } else {
        printf("Баланса нет\n");
    }
}

int main(int argc, char** argv)
{
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    balance(str);

    return 0;
}