/*1001 �����˲�������(3n+1)���� ��15 �֣�
������(Callatz)���룺

���κ�һ�������� n���������ż������ô��������һ�룻���������������ô�� (3n+1) ����һ�롣����һֱ��������ȥ�����һ����ĳһ���õ� n=1���������� 1950 ���������ѧ�Ҵ���Ϲ�����������룬��˵��ʱҮ³��ѧʦ���붯Ա��ƴ����֤�����ò�ƺ�ɵ����������⣬����ֵ�ѧ��������ѧҵ��һ��ֻ֤ (3n+1)������������˵����һ����ı�����������������ӻ�������ѧ���ѧ����еĽ�չ����

���ǽ������Ŀ����֤�������Ȳ��룬���ǶԸ�������һ������ 1000 �������� n���򵥵���һ�£���Ҫ���ٲ��������£����ܵõ� n=1��

�����ʽ��
ÿ������������� 1 ������������������������ n ��ֵ��

�����ʽ��
����� n ���㵽 1 ��Ҫ�Ĳ�����

����������
3
���������
5*/
#include <iostream>

using namespace std;

int main()
{
    int m,cou = 0;
    cin >> m;
    while(m != 1){
        if(m % 2 == 0)
        {
            m = m/2;
        }else
        {
            m = (3*m+1)/2;
        }
        cou ++;
    }
    cout << cou;
    return 0;
}