// 最大公共子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longest_common_substring(char *str1, char *str2)
{
    int i,j,k, len1, len2, max, x, y;
    len1 = strlen(str1);
    len2 = strlen(str2);
    int** c = new int* [len1 + 1];
    for (i = 0; i < len1 + 1; i++)
        c[i] = new int[len2 + 1];
    for (i = 0; i < len1 + 1; i++)
        c[i][0] = 0;
    for (j = 0; j < len2 + 1; j++)
        c[0][j] = 0;
    max = -1;
    for (i = 1; i < len1 + 1; i++)
    {
        for (j = 1; j < len2 + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = 0;
            if (c[i][j] > max)
            {
                max = c[i][j];
                x = i;
                y = j;
            }
        }
    }
    char s[1000];
    k = max;
    i = x - 1, j = y - 1;
    s[k--] = '\0';
    while (i >= 0 && j >= 0)
    {
        if (str1[i] == str2[j])
        {
            s[k--] = str1[i];
            i--;
            j--;
        }
        else
            break;
    }
    printf("最大公共子串为：");
    puts(s);
    for (i = 0; i < len1 + 1; i++)
        delete[] c[i];
    delete[] c;
    return max;
}
int main(void)
{
    char str1[1000], str2[1000];
    printf("请输入第一个字符串：");
    gets_s(str1);
    _strlwr_s(str1);
    printf("请输入第二个字符串：");
    gets_s(str2);
    _strlwr_s(str2);
    int len = longest_common_substring(str1, str2);
    printf("最大公共子串的长度为：%d\n", len);
    system("pause");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
