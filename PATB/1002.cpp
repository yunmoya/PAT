/*1002 写出这个数 （20 分）
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10
​100
​​ 。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <vector>
#define MAX 1e100
using namespace std;
int numToseq(int *seq,int num)
{
    vector<int> v;
    while(num != 0)
    {
        v.push_back(num % 10);
        num /= 10;
    }
    int i,j;
    for(i = v.size()-1,j = 0;i >= 0;i --,j ++)
    {
        seq[j] = v[i];
    }
    return j;
}
int numTohan(int *num,int n,string *s)
{
    int m = 0;
    for(int i = 0;i < n;i ++)
    {
        string tmp;
        switch(num[i])
        {
            case 0:tmp = "ling";break;
            case 1:tmp = "yi";break;
            case 2:tmp = "er";break;
            case 3:tmp = "san";break;
            case 4:tmp = "si";break;
            case 5:tmp = "wu";break;
            case 6:tmp = "liu";break;
            case 7:tmp = "qi";break;
            case 8:tmp = "ba";break;
            case 9:tmp = "jiu";break;
        }
        s[m++] = tmp;
    }
    return m;
}
int main()
{
    string s;
    int n,m,sum;
    int num[10000];
    cin >> s;
    string s1[10000] ;
    sum = 0;
    for(int i = 0;i < s.length();i ++)
    {
        //printf("%d",s[i]);
        sum += (s[i]-48);
    }
    m = numToseq(num,sum);
    n = numTohan(num,m,s1);
    for(int i = 0;i < n;i ++)
    {
        cout << s1[i];
        if(i != n-1)
            cout << " ";
    }

    return 0;
}
