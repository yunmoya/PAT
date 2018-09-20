#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
#define MAX 10000
#define NUM 20
#define LM 21
typedef struct Mark
{
        char no[LM]; //学号
        int GB; //编程
        int GZ; //期中
        int GM; //期末
        int sum; //总
}Mark;

int cmp(const void *p1,const void *p2)
{
    Mark *p = (Mark*)p1;
    Mark *q = (Mark*)p2;
    if(q->sum - p->sum)
        return q->sum - p->sum;
    return strcmp(p->no,q->no);
}
int cmp1(const void *p1,const void *p2)
{
    Mark *p = (Mark*)p1;
    Mark *q = (Mark*)p2;
    return strcmp(p->no,q->no);
}
int cmp_search(const void *p1,const void *p2)
{
    char *p = (char *)p1;
    Mark *q = (Mark *)p2;
    return strcmp(p,q->no);
}
int main()
{
    int p,q,m,n,i,j,score;
    char no[LM];
    float sum;
    Mark *result;
    scanf("%d %d %d",&p,&m,&n);
    Mark info[MAX];
    j = 0;
    for(i = 0,q = 0;q < p;i ++,q ++)
    {
        scanf("%s %d",info[i].no,&info[i].GB);
        if(info[i].GB < 200 || info[i].GB > 900)
            i --;
        else
        {
            info[i].GZ = -1;
            info[i].GM = -1;
            info[i].sum = 0;
            j ++;
        }
    }
    qsort(info,j,sizeof(Mark),cmp1);
    for(i = 0;i < m;i ++)
    {
        scanf("%s %d",no,&score);

        if(score < 0 || score > 100)
        {
            score = -1;
        }
        result = (Mark *)bsearch(no,info,j,sizeof(Mark),cmp_search);
        if(result == NULL)
            continue;
        else
        {
            result->GZ = score;
        }
    }

    for(i = 0;i < n;i ++)
    {
        scanf("%s %d",no,&score);
        if(score < 0 || score > 100)
        {
            score = -1;
        }
        result = (Mark *)bsearch(no,info,j,sizeof(Mark),cmp_search);
        if(result == NULL)
            continue;
        else
        {
            result->GM = score;
        }
        if(result->GZ > result->GM)
        {

            sum = 0.4*result->GZ + 0.6*result->GM;
            result->sum = (int)(sum + 0.5);

        }else
        {
            result->sum = result->GM;
        }
    }
    qsort(info,j,sizeof(Mark),cmp);
    for(i = 0;i < j;i ++)
    {
        if(info[i].sum < 60)
            break;
        printf("%s %d %d %d %d\n",info[i].no,info[i].GB,info[i].GZ,info[i].GM,info[i].sum);
    }

    return 0;
}
