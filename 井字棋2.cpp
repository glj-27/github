//������

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iostream>

using namespace std;
unsigned short chessboard [ 3 ][ 3 ];   //����,1����ո�2������ң�5����AI
unsigned short scores [ 3 ][ 3 ];   //AI��������

void playerSet ();  //�������
void AISet ();  //��������
void display ();    //��ʾ����
bool isFull (); //�����Ƿ�����
bool isWin ();  //�Ƿ����˻�ʤ
void initChessboard (); //��ʼ������

int main ( void )
{
    initChessboard ();
    display ();
    while ( !isWin()  )
    {
        if ( isFull ( ) )
        {
            puts ( "ƽ�֣�" );
            exit ( 0 );
        }
        playerSet ();
        AISet ();
        display ();
    }
    system ( "pause" );
    return 0;
}

void initChessboard ()  //��ʼ������
{
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 3; j++ )
        {
            chessboard [ i ][ j ] = 1;
        }
    }
}

bool isFull ()  //�����Ƿ�����
{
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 3; j++ )
        {
            if ( chessboard [ i ][ j ] == 1 )
            {
                return false;
            }
        }
    }
    return true;
}

bool isWin ()   //�Ƿ����˻�ʤ
{
    int sum = 0;
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 3; j++ )
        {
            sum += chessboard [ i ][ j ];
        }
        if ( sum == 6 )
        {
            puts ( "�����ʤ" );
            return true;
        }
        if ( sum == 15 )
        {
            puts ( "���Ի�ʤ" );
            return true;
        }
        sum = 0;
    }
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 3; j++ )
        {
            sum += chessboard [ j ][ i ];
        }
        if ( sum == 6 )
        {
            puts ( "�����ʤ" );
            return true;
        }
        if ( sum == 15 )
        {
            puts ( "���Ի�ʤ" );
            return true;
        }
        sum = 0;
    }
    for ( int i = 0; i < 3; i++ )
    {
        sum += chessboard [ i ][ i ];
        if ( sum == 6 )
        {
            puts ( "�����ʤ" );
            return true;
        }
        if ( sum == 15 )
        {
            puts ( "���Ի�ʤ" );
            return true;
        }
        sum = 0;
    }
    for ( int i = 0; i < 3; i++ )
    {
        sum += chessboard [ i ][ 2 - i ];
        if ( sum == 6 )
        {
            puts ( "�����ʤ" );
            return true;
        }
        if ( sum == 15 )
        {
            puts ( "���Ի�ʤ" );
            return true;
        }
        sum = 0;
    }
    return false;
}

void display () //��ʾ����
{
    for ( int i = 0; i < 3; i++ )
    {
        for ( int j = 0; j < 3; j++ )
        {
            switch ( chessboard [ i ][ j ] )
            {
                case 1:
                    printf ( " " );
                    break;
                case 2:
                    printf ( "X" );
                    break;
                case 5:
                    printf ( "O" );
                    break;
            }
        }
        printf ( "\n" );
    }
}

void playerSet ()   //�������
{
    int x , y;
    puts ( "����������X��Y:" );
    //scanf_s ( "%d%d" , &x , &y );
    cin>>x>>y; 
    while ( chessboard [ 3 - y ][ x - 1 ] != 1 )
    {
        fprintf ( stderr , "THIS CELL HAS BEEN SETED!\n" );
        //scanf_s ( "%d%d" , &x , &y );
        cin>>x>>y;
    }
    chessboard [ 3 - y ][ x - 1 ] = 2;
}

void AISet ()   //��������
{
    int sum = 0;

    for ( int i = 0; i < 3; i++ )   //��ʼ����������
    {
        for ( int j = 0; j < 3; j++ )
        {
            scores [ i ][ j ] = 0;
        }
    }

    for ( int i = 0; i < 3; i++ )   //��ÿһ�н��д���
    {
        for ( int j = 0; j < 3; j++ )
        {
            sum += chessboard [ i ][ j ];
        }
        switch ( sum )
        {
            case 3: //1+1+1 ���ȼ�2    Ȩ��5
                for ( int j = 0; j < 3; j++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 5;
                    }
                }
                break;
            case 4: //1+1+2 ���ȼ�1    Ȩ��25
                for ( int j = 0; j < 3; j++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 25;
                    }
                }
                break;
            case 7: //1+1+5 ���ȼ�3    Ȩ��30
                for ( int j = 0; j < 3; j++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 30;
                    }
                }
                break;
            case 5: //1+2+2 ����Ҫ�䣬���ȼ��θ� 4    Ȩ��300
                for ( int j = 0; j < 3; j++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 300;
                    }
                }
                break;
            case 11:    //1+5+5 ����ҪӮ�����ȼ���� 5    Ȩ��1000
                for ( int j = 0; j < 3; j++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 1000;
                    }
                }
                break;
        }
        sum = 0;
    }

    for ( int j = 0; j < 3; j++ )   //��ÿ�н��д���
    {
        for ( int i = 0; i < 3; i++ )
        {
            sum += chessboard [ i ][ j ];
        }
        switch ( sum )
        {
            case 3: //1+1+1 ���ȼ�2    Ȩ��5
                for ( int i = 0; i < 3; i++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 5;
                    }
                }
                break;
            case 4: //1+1+2 ���ȼ�1    Ȩ��25
                for ( int i = 0; i < 3; i++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 25;
                    }
                }
                break;
            case 7: //1+1+5 ���ȼ�3    Ȩ��30
                for ( int i = 0; i < 3; i++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 30;
                    }
                }
                break;
            case 5: //1+2+2 ����Ҫ�䣬���ȼ��θ� 4    Ȩ��300
                for ( int i = 0; i < 3; i++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 300;
                    }
                }
                break;
            case 11:    //1+5+5 ����ҪӮ�����ȼ���� 5    Ȩ��1000
                for ( int i = 0; i < 3; i++ )
                {
                    if ( chessboard [ i ][ j ] == 1 )
                    {
                        scores [ i ][ j ] += 1000;
                    }
                }
                break;
        }
        sum = 0;
    }
    for ( int i = 0; i < 3; i++ )   //б��
    {
        sum += chessboard [ i ][ i ];
    }
    switch ( sum )
    {
        case 3: //1+1+1 ���ȼ�2    Ȩ��5
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ i ] == 1 )
                {
                    scores [ i ][ i ] += 5;
                }
            }
            break;
        case 4: //1+1+2 ���ȼ�1    Ȩ��25
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ i ] == 1 )
                {
                    scores [ i ][ i ] += 25;
                }
            }
            break;
        case 7: //1+1+5 ���ȼ�3    Ȩ��30
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ i ] == 1 )
                {
                    scores [ i ][ i ] += 30;
                }
            }
            break;
        case 5: //1+2+2 ����Ҫ�䣬���ȼ��θ� 4    Ȩ��300
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ i ] == 1 )
                {
                    scores [ i ][ i ] += 300;
                }
            }
            break;
        case 11:    //1+5+5 ����ҪӮ�����ȼ���� 5    Ȩ��1000
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ i ] == 1 )
                {
                    scores [ i ][ i ] += 1000;
                }
            }
            break;
    }
    sum = 0;

    for ( int i = 0; i < 3; i++ )   //��б��
    {
        sum += chessboard [ i ][ 2 - i ];
    }
    switch ( sum )
    {
        case 3: //1+1+1 ���ȼ�2    Ȩ��5
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ 2 - i ] == 1 )
                {
                    scores [ i ][ 2 - i ] += 5;
                }
            }
            break;
        case 4: //1+1+2 ���ȼ�1    Ȩ��25
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ 2 - i ] == 1 )
                {
                    scores [ i ][ 2 - i ] += 25;
                }
            }
            break;
        case 7: //1+1+5 ���ȼ�3    Ȩ��30
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ 2 - i ] == 1 )
                {
                    scores [ i ][ 2 - i ] += 30;
                }
            }
            break;
        case 5: //1+2+2 ����Ҫ�䣬���ȼ��θ� 4    Ȩ��300
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ 2 - i ] == 1 )
                {
                    scores [ i ][ 2 - i ] += 300;
                }
            }
            break;
        case 11:    //1+5+5 ����ҪӮ�����ȼ���� 5    Ȩ��1000
            for ( int i = 0; i < 3; i++ )
            {
                if ( chessboard [ i ][ 2 - i ] == 1 )
                {
                    scores [ i ][ 2 - i ] += 1000;
                }
            }
            break;
    }
    sum = 0;
    int maxI = 0 , maxJ = 0;
    for ( int i = 0; i < 3; i++ )   //�ҳ�Ȩ�����ĸ���
    {
        for ( int j = 0; j < 3; j++ )
        {
            if ( scores [ maxI ][ maxJ ] < scores [ i ][ j ] )
            {
                maxI = i;
                maxJ = j;
            }
        }
    }
    chessboard [ maxI ][ maxJ ] = 5;
}

