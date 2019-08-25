#include <stdaf.h>
#include <cstdio>
#include <iostream>
#include <ctime> //获取时间
#include <string>
#include <cmath>
using namespace std;

class dian
{
private:
    char allnumber[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };//全部的数字
    double a, b, c, d;
    double number[4];//用来存选出的四个数字
    string result[4];//存输出的算式
public:
    void choice();//从1~13中随机生成4个数
    bool calculate(int n);//计算24点并输出结果
};
int flag = 0;//统计算式个数，判断是否有结果
void dian::choice()
{
    srand((unsigned)time(NULL));//获取当前时间作为参数，生可以随时间变化的随机数
    a = allnumber[rand() % 13 ];//rand（）用来生成随机数
    b = allnumber[rand() % 13 ];
    c = allnumber[rand() % 13 ];
    d = allnumber[rand() % 13 ];

    for (int i = 0; i < 4; i++)//赋值
    {
        if (i == 0)
            number[i] =a;
        if (i == 1)
            number[i] = b;
        if (i == 2)
            number[i] = c;
        if (i == 3)
            number[i] = d;
    }

    for (int i=0; i < 4; i++)//将整型数据赋到字符串数组中
    {
        int A = a;//为了不输出多余的零，取整型
        int B = b;
        int C = c;
        int D = d;
        if (i == 0)
            result[i] = to_string(A);
        if (i == 1)
            result[i] = to_string(B);
        if (i == 2)
            result[i] = to_string(C);
        if (i == 3)
            result[i] = to_string(D);
    }

    cout << "四个数字为：" << endl;
    cout <<a<<" "<<b << " " <<c << " " <<d << " " <<endl;
}

bool dian::calculate(int n)//计算24点
{
    if (n == 1)
    {
        if (number[0]==24)
        {
            cout << result[0] << endl;
            flag++;
        }
        else
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double x, y;
            string expa, expb;

            x = number[i];
            y = number[j];
            number[j] = number[n - 1];

            expa=result[i];
            expb = result[j];
            result[j] = result[n - 1];

            result[i] = '(' + expa + '+' + expb + ')';//加法
            number[i] = x + y;
            if (calculate(n - 1))
                return true;

            result[i] = '(' + expa + '-' + expb + ')';//减法
            number[i] = x- y;
            if (calculate(n - 1))
                return true;

            result[i] = '(' + expa + '*' + expb + ')';//乘法
            number[i] = x*y;
            if (calculate(n - 1))
                return true;

            if (y!= 0)
            {
                result[i] = '(' + expa + '/' + expb + ')';//分母不为零,除法
                number[i] = x / y;
                if (calculate(n - 1))
                    return true;
            }
            number[i] = x;
            number[j] = y;
            result[i] = expa;
            result[j] = expb;
        }
    }
    return false;
}

int main()
{
    dian turn1;
    while (1)
    {
        char choice;
        turn1.choice();
        turn1.calculate(4);
        if (flag == 0)
        {
            cout << "这组数算不出24点！" << endl;
        }
        cout << "是否继续生成？（Y/N）" << endl;
        cin >> choice;
        if (choice == 'Y')
            continue;
        if (choice == 'N')
            break;
    }
    return 0;
}
