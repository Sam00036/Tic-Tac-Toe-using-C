#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char game_struct[11][11];
void init()
{
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            if((j==3)||(j==7))
            {
                game_struct[i][j]='*';
            }
            else if((i==3)||(i==7))
            {
                game_struct[i][j]='*';
            }
            else
            {
                game_struct[i][j]=' ';
            }
        }
    }
}
void make_num()
{
    game_struct[1][1]='1';
    game_struct[1][5]='2';
    game_struct[1][9]='3';
    game_struct[5][1]='4';
    game_struct[5][5]='5';
    game_struct[5][9]='6';
    game_struct[9][1]='7';
    game_struct[9][5]='8';
    game_struct[9][9]='9';
}
void print_board()
{
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            printf("%c ",game_struct[i][j]);
        }
        printf("\n");
    }
}
char win_check(char n)
{
    if((game_struct[1][1]==n)&&(game_struct[1][5]==n)&&(game_struct[1][9]==n))
        return n;
    else if((game_struct[5][1]==n)&&(game_struct[5][5]==n)&&(game_struct[5][9]==n))
        return n;
    else if((game_struct[9][1]==n)&&(game_struct[9][5]==n)&&(game_struct[9][9]==n))
        return n;
    else if((game_struct[1][1]==n)&&(game_struct[5][1]==n)&&(game_struct[9][1]==n))
        return n;
    else if((game_struct[1][5]==n)&&(game_struct[5][5]==n)&&(game_struct[9][5]==n))
        return n;
    else if((game_struct[1][9]==n)&&(game_struct[5][9]==n)&&(game_struct[9][9]==n))
        return n;
    else if((game_struct[1][1]==n)&&(game_struct[5][5]==n)&&(game_struct[9][9]==n))
        return n;
    else if((game_struct[9][1]==n)&&(game_struct[5][5]==n)&&(game_struct[1][9]==n))
        return n;
    else
    {
        n=' ';
        return n;
    }
}
void convert(int a,int n)
{
    char b;
    if(n==1)
        b='O';
    if(n==2)
        b='X';
    if(a==1)
        game_struct[1][1]=b;
    else if(a==2)
        game_struct[1][5]=b;
    else if(a==3)
        game_struct[1][9]=b;
    else if(a==4)
        game_struct[5][1]=b;
    else if(a==5)
        game_struct[5][5]=b;
    else if(a==6)
        game_struct[5][9]=b;
    else if(a==7)
        game_struct[9][1]=b;
    else if(a==8)
        game_struct[9][5]=b;
    else if(a==9)
        game_struct[9][9]=b;
}
char check_pos(int n)
{
    if(n==1)
        return game_struct[1][1];
    else if(n==2)
        return game_struct[1][5];
    else if(n==3)
        return game_struct[1][9];
    else if(n==4)
        return game_struct[5][1];
    else if(n==5)
        return game_struct[5][5];
    else if(n==6)
        return game_struct[5][9];
    else if(n==7)
        return game_struct[9][1];
    else if(n==8)
        return game_struct[9][5];
    else if(n==9)
        return game_struct[9][9];
}
int main()
{
    int n;
    char w;
    printf("WELCOME TO GORIBAR KATAKUTI BOARD\n");
    printf("PLAYER 1 : O\n");
    printf("PLAYER 2 : X\n");
    printf("THE BOARD ORDER IS GIVEN BELOW\n");
    init();
    make_num();
    print_board();
    printf("LETS START THE GAME\n");
    init();
    for(int i=0;i<9;i++)
    {
        printf("TURN %d\n",i+1);
        printf("PLAYER %d ENTER THE BOX NUM : ",(i%2)+1);
        scanf("%d",&n);
        if((n>9)||(n<1))
        {
            printf("PLEASE ENTER A VALID MOVE\n");
            i--;
            continue;
        }
        char a=check_pos(n);
        if(a!=' ')
        {
            if(a=='O')
                printf("THE BOX IS ALREADY OCCUPIED BY PLAYER 1\n");
            if(a=='X')
                printf("THE BOX IS ALREADY OCCUPIED BY PLAYER 2\n");
            i--;
            continue;
        }
        char t;
        if(i%2==0)
        {
            convert(n,1);
            t='O';

        }
        if(i%2==1)
        {
            convert(n,2);
            t='X';
        }
        print_board();
        w=win_check(t);
        if(w=='O')
        {
            printf("PLAYER 1 WINS THE GAME");
            break;
        }
        if(w=='X')
        {
            printf("PLAYER 2 WINS THE GAME");
            break;
        }
    }
    if(w==' ')
    {
        printf("THE MATCH IS A DRAW");
    }
    return 0;
}