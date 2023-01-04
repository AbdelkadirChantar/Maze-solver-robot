#include <Arduino.h>
#include "Motors.h"
#include <stdlib.h>



#define minDistance 12
char path[50];
char path_op[50];
int i=0, j=0, counter = 0;

bool left = (leftDistance() >= minDistance);
bool front_right = (frontDistance() >= 6 && rightDistance() >= minDistance);
bool right = (rightDistance() >= minDistance);
bool dead_end = (frontDistance() <= 6);
bool intersection = (frontDistance() >= minDistance || rightDistance() >= minDistance || leftDistance() >= minDistance);


void LSRB()

{
     moveForward();

      
 if (leftDistance() > minDistance || rightDistance() > minDistance || frontDistance() > 5)
    {
        ready();
        delay(150);
        stop();
        delay(200);
    if (leftDistance() > minDistance)
    {
        
        //stop();

        path[counter] = 'L';
        counter++;
        
        turnL_P();
        moveForward();
        delay(500);
        //stepsL = 0;
        //stepsR = 0;
    }

    else if (frontDistance() > minDistance && rightDistance() > minDistance)
    {
        path[counter] = 'S';
        counter++;
        moveForward();
    }
    else if (rightDistance() > minDistance)
    {
        
        stop();
        delay(500);

        path[counter] = 'R';
        counter++;
        turnR_P();
        moveForward();
        delay(500);
        //stepsL = 0;
        //stepsR = 0;
    }
    else if (frontDistance() < 4)
    {
        
        stop();
        delay(1000);

        path[counter] = 'B';
        counter++;
        turn_180();
        //stepsL = 0;
        //stepsR = 0;
    }
    
    }

   // selfCenter();
    

    
}


void LSRB_OP()
{
    for (i = 0, j = 0; i < counter; j++)
    {
        if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='R')
        {
            path_op[j] = 'B';
            i = i+3;
        }
        else if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='S')
        {
            path_op[j] = 'R';
            i=i+3;
        }
        else if (path[i]=='R' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'B';
            i=i+3;
        }
        else if (path[i]=='S' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'R';
            i=i+3;
        }
        else if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'S';
            i=i+3;
        }  
        else //in case none of the optimisations is possible
        {
            path_op[j] = path[i];
            i++;
        }
    }
}



void shortestPath()
{
    if(intersection == true)
    {
        if(path_op[j] == 'L')
        {
            stop();
            turnR_P();
            stepsL = 0;
            stepsR = 0;
            moveForward();
            j--;
            selfCenter();
        }
        else if (path_op[j] == 'S')
        {
            moveForward();
            j--;
            selfCenter();
        }
        else if (path_op[j] == 'R')
        {
            stop();
            turnL_P();
            stepsL = 0;
            stepsR = 0;
            moveForward();
            j--;
            selfCenter();
        }
    }
}





/*

void shortPath()  // while running
{
    if (path[counter] == '?' && path[counter-1] == '?' && path[counter-2] == '?')
        counter-=2;
        path[counter] = '?'
}


turnLeft();
path[counter] = 'L';

if (counter >= 2)
{
    shortPath();
}
counter++;
*/

