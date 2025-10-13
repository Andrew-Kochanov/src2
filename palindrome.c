#include <stdio.h>
#include <string.h>

void palindrome(char* str)
{
    // индексы для сравнения элементов строк
    int start = 0;
    int finish = strlen(str) - 1;
    bool flag = true;

    while (finish > start) {

        // игнорирование пробелов и переход на следующий индекс
        while (str[start] == ' ') {
            start++;
        }
        while (str[finish] == ' ') {
            finish--;
        }
        if (str[start] != str[finish]) {
            flag = false;
            break;
        }
        start++;
        finish--;
    }

    if (flag) {
        printf("Строка палиндром\n");
    } else {
        printf("Строка не палиндром\n");
    }
}

int main(int argc, char** argv)
{
    // проверка палиндрома
    char* strPalindrome = "l wqe req wl";
    palindrome(strPalindrome);

    // проверка не палиндрома
    char* strNotPalindrome = "iui guvv vhv";
    palindrome(strNotPalindrome);
    return 0;
}