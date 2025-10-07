#include <stdio.h>

int main(int argc, char **argv)
{
    int sum = 0;

    // 6 циклов для шести цифр и дальнейшее сравнение сумм
    for (int i_1 = 0; i_1 < 10; i_1++)
    {
        for(int i_2 = 0; i_2 < 10; i_2++)
        {
            for(int i_3 = 0; i_3 < 10; i_3++)
            {
                for(int i_4 = 0; i_4 < 10; i_4++)
                {
                    for (int i_5 = 0; i_5 < 10; i_5++)
                    {
                        for (int i_6 = 0; i_6 < 10; i_6++)
                        {
                            if(i_1 + i_2 + i_3 == i_4 + i_5 + i_6)
                            {
                                sum++;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}
