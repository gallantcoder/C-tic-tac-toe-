#include <stdio.h>
#include <stdlib.h>

char a[3][3]; int stop = 0; char player1 = ' ', player2 = ' '; char turn = ' ';  int score1 = 0, score2 = 0; int location1=0, location2=0;
int field = 0;
void printscreen();
void setindex(int f);
int checkplayer1wins(char player1);
int checkplayer2wins(char player2);
int boardfull();
int main()
{

    printf("Tictactoe game by Mathew Fortune , mail : mathewfortune54@gmail.com!\n\n\t\t\tNEW GAME\n\n");
    printf("player1 score : %d\t\t\t player2 score : %d\n\n", score1, score2);
    printf("\nInstruction : Every field is represented between 1 - 9, to play a field you enter an input between 1 - 9\n\n\n");
    a[0][0] = '1';
    a[0][1] = '2';
    a[0][2] = '3';
    a[1][0] = '4';
    a[1][1] = '5';
    a[1][2] = '6';
    a[2][0] = '7';
    a[2][1] = '8';
    a[2][2] = '9';

    for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {

            printf("| %c | \t", a[i][k]);
        }
        printf("\n\n\n");
    }
    for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {
            a[i][k] = '_';

        }
    }


    printf("Please as player one you are to choose between X or O : ");
    scanf("%c", &player1);
    if(player1 == 'X')
        player2 = 'O';
    else if(player1 == 'x')
        {
            player1 = 'X';
            player2 = 'O';
        }
    else if(player1 == 'O')
        player2 = 'X';
    else if(player1 == 'o')
    {
        player1 = 'O';
      player2 = 'X';
    }
    else
        return 0;

    turn = player1;

    while(stop == 0)
    {

        printf("player = %c\n",turn);
        printf("please input between numbers 1 - 9 to play a field any character apart from this terminates the game : ");
        scanf("%d",&field);


    printf("\n");



        while(checkifindexisoccupied(field) == 1)
        {
            printscreen();
            printf("That field has been occupied or does not exist,\nplease input another field : ");
        scanf("%d",&field);

        printf("\n");
        }

        setindex(field);

            printscreen();



        if(turn == player1)
        {

           if(checkplayer1wins(player1) == 1)
        {
            score1 += 2;
            int conti = 0;
            printf("player one : %c has won the game \n", turn);
            printscreen();
            printf("do you wish to continue : press 1 to continue or any other key to terminate :");
            scanf("%d", &conti);

            if(conti == 1)
            {
                 for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {
            a[i][k] = '_';

        }



    }
    printf("\n Game Continues \n");
    printscreen();
    turn = player2;
            }
            else
                stop = 1;

        }


    else{
        if(boardfull() == 1)
        {
            printf("No winner\nPlayer one : %c\nDo you wish to continue, press 1 to continue or any other character to end : ", turn);
            int contdraw = 0;
            scanf("%d",&contdraw);
            if(contdraw == 1)
            {
                printf("\n\n");
                 a[0][0] = '1';
    a[0][1] = '2';
    a[0][2] = '3';
    a[1][0] = '4';
    a[1][1] = '5';
    a[1][2] = '6';
    a[2][0] = '7';
    a[2][1] = '8';
    a[2][2] = '9';

    for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {

            printf("| %c | \t", a[i][k]);
        }
        printf("\n\n\n");
    }
    for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {
            a[i][k] = '_';

        }
    }
    printscreen();

            }else
            stop = 1;

        }
    }


        }




        if(turn == player2)
        {

            if(checkplayer2wins(player2) == 1)
        {
            score2 += 2;
            int conti = 0;
            printf("player two : %c has won the game \n", turn);
            printscreen();
             printf("do you wish to continue : press 1 to continue or any other key to terminate :");
            scanf("%d", &conti);
            if(conti == 1)
            {
                 for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {
            a[i][k] = '_';

        }

    }
printf("\n Game Continues \n");
printscreen();
    turn = player1;
            }
            else
                stop = 1;

        }

    else
    {

      if(boardfull() == 1)
        {
            printf("No winner\nPlayer two : %c\nDo you wish to continue, press 1 to continue or any other character to end :", turn);
            int contdraw = 0;
            scanf("%d",&contdraw);
            if(contdraw == 1)
            {
                printf("\n\n");
                 a[0][0] = '1';
    a[0][1] = '2';
    a[0][2] = '3';
    a[1][0] = '4';
    a[1][1] = '5';
    a[1][2] = '6';
    a[2][0] = '7';
    a[2][1] = '8';
    a[2][2] = '9';

    for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {

            printf("| %c | \t", a[i][k]);
        }
        printf("\n\n\n");
    }
    for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {
            a[i][k] = '_';

        }
    }
    printscreen();

            }else
            stop = 1;

        }
    }
        }

        if(turn == player1)
            turn = player2;
            else
            turn =  player1;



    }



    return 0;
}
 int checkplayer1wins(char playee1)
{

    if(((a[0][0] == a[1][1])&& (a[0][0] == a[2][2])) && (a[0][0] == playee1))
        return 1;
    else if(((a[0][2] == a[1][1])&& (a[0][2] == a[2][0])) && (a[0][2] == playee1))
        return 1;
        else if(((a[0][0] == a[1][0])&& (a[0][0] == a[2][0])) && (a[0][0] == playee1))
        return 1;
    else if(((a[0][1] == a[1][1])&& (a[0][1] == a[2][1])) && (a[0][1] == playee1))
        return 1;
        else if(((a[0][2] == a[1][2])&& (a[0][2] == a[2][2])) && (a[0][2] == playee1))
        return 1;
        else if(((a[0][0] == a[0][1])&& (a[0][0] == a[0][2])) && (a[0][0] == playee1))
        return 1;
    else if(((a[1][0] == a[1][1])&& (a[1][0] == a[1][2])) && (a[1][0] == playee1))
        return 1;
        else if(((a[2][0] == a[2][1])&& (a[2][0] == a[2][2])) && (a[2][0] == playee1))
        return 1;
        else
            return 0;


}

int checkplayer2wins(char playee2)
{
 if(((a[0][0] == a[1][1])&& (a[0][0] == a[2][2])) && (a[0][0] == playee2))
        return 1;
    else if(((a[0][2] == a[1][1])&& (a[0][2] == a[2][0])) && (a[0][2] == playee2))
        return 1;
        else if(((a[0][0] == a[1][0])&& (a[0][0] == a[2][0])) && (a[0][0] == playee2))
        return 1;
    else if(((a[0][1] == a[1][1])&& (a[0][1] == a[2][1])) && (a[0][1] == playee2))
        return 1;
        else if(((a[0][2] == a[1][2])&& (a[0][2] == a[2][2])) && (a[0][2] == playee2))
        return 1;
        else if(((a[0][0] == a[0][1])&& (a[0][0] == a[0][2])) && (a[0][0] == playee2))
        return 1;
    else if(((a[1][0] == a[1][1])&& (a[1][0] == a[1][2])) && (a[1][0] == playee2))
        return 1;
        else if(((a[2][0] == a[2][1])&& (a[2][0] == a[2][2])) && (a[2][0] == playee2))
        return 1;
        else
            return 0;

}

int checkifindexisoccupied(int b)
    {

        if(field == 1)
        {
          if(a[0][0] == '_')
            return 0;
            else
            return 1;
        }
        else if(field == 2)
        {
          if(a[0][1] == '_')
            return 0;
            else
            return 1;
        }
        else if(field == 3)
        {
          if(a[0][2] == '_')
            return 0;
            else
            return 1;
        }
        else if(field == 4)
        {
          if(a[1][0] == '_')
            return 0;
            else
            return 1;
        }
        else if(field == 5)
        {
          if(a[1][1] == '_')
            return 0;
            else
            return 1;
        }
        else if(field == 6)
        {
          if(a[1][2] == '_')
            return 0;
            else
            return 1;
        }
        else if(field == 7)
        {
          if(a[2][0] == '_')
            return 0;
            else
            return 1;
        }
        else if(field == 8)
        {
          if(a[2][1] == '_')
            return 0;
            else
            return 1;
        }
        else if(field == 9)
        {
          if(a[2][2] == '_')
            return 0;
            else
            return 1;
        }
        else
            return 1;



    }
void printscreen()
{

    printf("player1 score : %d\t\t\t player2 score : %d\n\n", score1, score2);
    for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {

            printf("| %c | \t", a[i][k]);
        }
        printf("\n\n\n");
    }
}
 void setindex(int f)
 {
     if(f == 1)
            a[0][0] = turn;
        else if(f == 2)
            a[0][1] = turn;
        else if(f == 3)
            a[0][2] = turn;
            else if(f == 4)
            a[1][0] = turn;
            else if(f == 5)
            a[1][1] = turn;
            else if(f == 6)
            a[1][2] = turn;
            else if(f == 7)
            a[2][0] = turn;
            else if(f == 8)
            a[2][1] = turn;
            else
                a[2][2] = turn;
 }




 int boardfull()
 {
     for(int i = 0; i<3; i++)
    {
        for(int k = 0; k<3; k++)
        {

            if(a[i][k] == '_')
            {
                return 0;
                break;
            }
        }

    }

    return 1;

 }
