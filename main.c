#include <stdio.h>
#include <stdlib.h>
#include "header.h"


    /* Array Holds Initial Values */
    char x_0_matrix [3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    /* Variable Used to Identify The Player */
    short int  status = 1;
    /* Variable Holds The Data comes From the user */
    short int entry = 0 ;
    /* Variable Used When The user Enter Error Number */
    short int error = 0 ;
    /* Variable used to Detect The Symbol For The User */
    char symbol ;
    /* Variable Holds The Value Return from  Check Winner Function */
    short int score ;

/* Main Function */
int main()
{
    do
    {
    // Call The  View Function
    view();
    // Detect Which Player will Play
    status = (status % 2 ) ? 1 : 2 ;
    /* Ask The User To Enter The Number Who wants to Play in */
    printf("                Player %d :  Enter Number : " ,status) ;
    // Take The Value Form The User
    scanf("%d",&entry);
    /* Check Entry between 0 and 9 */


    // Choose X or O Symbol
    symbol = (status == 1) ? 'X' : 'O';
    // Switch on the Entry
    switch (entry)
    {

    case 1 :
            if (x_0_matrix[0][0] != 'X' && x_0_matrix[0][0] != 'O'  )
                x_0_matrix[0][0]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;

    case 2 :
            if (x_0_matrix[0][1] != 'X' && x_0_matrix[0][1] != 'O'  )
                x_0_matrix[0][1]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;

     case 3 :
            if (x_0_matrix[0][2] != 'X' && x_0_matrix[0][2] != 'O'  )
                x_0_matrix[0][2]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;
    case 4 :
            if (x_0_matrix[1][0] != 'X' && x_0_matrix[1][0] != 'O'  )
                x_0_matrix[1][0]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;

    case 5 :
            if (x_0_matrix[1][1] != 'X' && x_0_matrix[1][1] != 'O'  )
                x_0_matrix[1][1]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;

    case 6:
            if (x_0_matrix[1][2] != 'X' && x_0_matrix[1][2] != 'O'  )
                x_0_matrix[1][2]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;

    case 7 :
            if (x_0_matrix[2][0] != 'X' && x_0_matrix[2][0] != 'O'  )
                x_0_matrix[2][0]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;

    case 8 :
            if (x_0_matrix[2][1] != 'X' && x_0_matrix[2][1] != 'O'  )
                x_0_matrix[2][1]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;

    case 9 :
            if (x_0_matrix[2][2] != 'X' && x_0_matrix[2][2] != 'O'  )
                x_0_matrix[2][2]=symbol ;
            else
            {
                error = 1 ;
                status -- ;
            }
            break ;

    }

     // Increase Status to Change The Player
    status ++ ;
    // Command To Clear The Screen
   system("@cls||clear");
   score = Check_Winner();
   /* Close The Game in case of Win or Draw */
     if ((score == 1) || (score == 0 ) )
     {
         view();
          break ;
     }

    }


    while ( score == -1) ;

        return 0;
}

void view (void)
{
        /* Design View of The Game */
    printf("\n\n");
    printf("                    Welcome To XO Game \n\n ");
    printf("               ---------------------------- \n");
    printf("                |   %c   |   %c    |    %c   | \n",x_0_matrix[0][0],x_0_matrix[0][1],x_0_matrix[0][2]);
    printf("                ---------------------------- \n");
    printf("                |   %c   |   %c    |    %c   |\n",x_0_matrix[1][0],x_0_matrix[1][1],x_0_matrix[1][2]);
    printf("                ---------------------------- \n");
    printf("                |   %c   |   %c    |    %c   |\n",x_0_matrix[2][0],x_0_matrix[2][1],x_0_matrix[2][2]);
    printf("                ---------------------------- \n");

    /* if User makes Error will print */
    if (error == 1 )
        {
            printf("                    Try A free Number \n");
            error = 0 ;
        }
   /* Take The Value Comes from check Winner Function */
    score = Check_Winner();
    /* If Winner Happen */
    if (score ==1)
        printf("                        Player %d Win  \n" , status-1);
    /* Draw Happen */
    else if (score == 0 )
        printf("                            Draw  \n" );
    /* in case of The Data Enter not Between 0 and 9 */
      if ((entry > 10) || (entry < 0))
    {

        printf("            Enter Valid Number Between 0 and 9 \n ");
    }
}

/* Function to Check The Winner */
short int  Check_Winner (void)
{
    /* In case Of Winner */
    if ((x_0_matrix[0][0] == x_0_matrix[0][1]) && (x_0_matrix[0][1] == x_0_matrix[0][2]))
        return 1 ;

    else if ((x_0_matrix[1][0] == x_0_matrix[1][1]) && (x_0_matrix[1][1] == x_0_matrix[1][2]))
        return 1 ;

    else if ((x_0_matrix[2][0] == x_0_matrix[2][1]) && (x_0_matrix[2][1] == x_0_matrix[2][2]))
        return 1 ;

    else if ((x_0_matrix[0][0] == x_0_matrix[1][1]) && (x_0_matrix[1][1] == x_0_matrix[2][2]))
        return 1 ;

    else if ((x_0_matrix[0][2] == x_0_matrix[1][1]) && (x_0_matrix[1][1] == x_0_matrix[2][0]))
        return 1 ;

    else if ((x_0_matrix[0][0] == x_0_matrix[1][0]) && (x_0_matrix[1][0] == x_0_matrix[2][0]))
        return 1 ;

    else if ((x_0_matrix[0][2] == x_0_matrix[1][2]) && (x_0_matrix[1][2] == x_0_matrix[2][2]))
        return 1 ;
    /* In Case Of Draw */
    else if (x_0_matrix[0][0] != '1' && x_0_matrix[0][1] != '2' && x_0_matrix[0][2] != '3' &&
        x_0_matrix[1][0]!= '4' && x_0_matrix[1][1] != '5' && x_0_matrix[1][2] != '6' &&
        x_0_matrix[2][0]!= '7' && x_0_matrix[2][1] != '8' && x_0_matrix[2][2] != '9')

        return 0;

    else
        return -1 ;

}

