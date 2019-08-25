#include <stdaf.h>
#include <cstdio>
#include <iostream>
#include <ctime> //��ȡʱ��
#include <string>
#include <cmath>
using namespace std;

class dian
{
private:
    char allnumber[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };//ȫ��������
    double a, b, c, d;
    double number[4];//������ѡ�����ĸ�����
    string result[4];//���������ʽ
public:
    void choice();//��1~13���������4����
    bool calculate(int n);//����24�㲢������
};
int flag = 0;//ͳ����ʽ�������ж��Ƿ��н��
void dian::choice()
{
    srand((unsigned)time(NULL));//��ȡ��ǰʱ����Ϊ��������������ʱ��仯�������
    a = allnumber[rand() % 13 ];//rand�����������������
    b = allnumber[rand() % 13 ];
    c = allnumber[rand() % 13 ];
    d = allnumber[rand() % 13 ];

    for (int i = 0; i < 4; i++)//��ֵ
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

    for (int i=0; i < 4; i++)//���������ݸ����ַ���������
    {
        int A = a;//Ϊ�˲����������㣬ȡ����
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

    cout << "�ĸ�����Ϊ��" << endl;
    cout <<a<<" "<<b << " " <<c << " " <<d << " " <<endl;
}

bool dian::calculate(int n)//����24��
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

            result[i] = '(' + expa + '+' + expb + ')';//�ӷ�
            number[i] = x + y;
            if (calculate(n - 1))
                return true;

            result[i] = '(' + expa + '-' + expb + ')';//����
            number[i] = x- y;
            if (calculate(n - 1))
                return true;

            result[i] = '(' + expa + '*' + expb + ')';//�˷�
            number[i] = x*y;
            if (calculate(n - 1))
                return true;

            if (y!= 0)
            {
                result[i] = '(' + expa + '/' + expb + ')';//��ĸ��Ϊ��,����
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
            cout << "�������㲻��24�㣡" << endl;
        }
        cout << "�Ƿ�������ɣ���Y/N��" << endl;
        cin >> choice;
        if (choice == 'Y')
            continue;
        if (choice == 'N')
            break;
    }
    return 0;
}
