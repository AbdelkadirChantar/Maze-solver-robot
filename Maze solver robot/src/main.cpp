#include <IR.h>
//#include "Algorithm.h"
#include "Motors.h"
#define d 1000
int A = 0;
int d1 = 300;
int d2 = 500;
#define minDistance 12
char path[50];
char path_op[50];
int i=0, j=0, counter = 0;
void setup() 
{
    Serial.begin(9600);
    //dclrCompass();
    dclrEncoder();
    attachInterrupt(digitalPinToInterrupt(ENCL), readEcoder, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCR), readEcoder, RISING);
    

    
}

void loop() 
{ 
   moveForward(); 
 if (leftDistance() > minDistance || rightDistance() > minDistance || frontDistance() < 5)
    {
        ready();
        delay(150);
        stop();
        delay(200);
    if (leftDistance() > minDistance)
    {
        
        stop();

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
        delay(1000);

        path[counter] = 'R';
        counter++;
        turnR_P();
        moveForward();
        delay(500);
        //stepsL = 0;
        //stepsR = 0;
    }
    else if (frontDistance() < 6)
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
}
    /*
  moveForward();

      Serial.println("caseX");
 
    if (leftDistance() > minDistance)
    {
        Serial.println("case0");
        
        

        path[counter] = 'L';
        counter++;
        delay(200);
        turnL_P();
        delay(500);
        moveForward();
        
        //stepsL = 0;
        //stepsR = 0;
    }

    else if (frontDistance() > minDistance && rightDistance() > minDistance)
    {
        Serial.println("case1");
        path[counter] = 'S';
        counter++;
        
    }
    else if (rightDistance() > minDistance)
    {
        Serial.println("case2");
        
        delay(200);

        path[counter] = 'R';
        counter++;
        turnR_P();
        delay(500);
        moveForward();
        
        //stepsL = 0;
        //stepsR = 0;
    }
    else if (frontDistance() < 3)
    {
        Serial.println("case3");
        stop();
        delay(1000);

        path[counter] = 'B';
        counter++;
        turn_180();
        //stepsL = 0;
        //stepsR = 0;
    }

    
    
    
    }

  
  
    





    /*
    if (line == true && A == 0)
    {
        A = 1;
        delay(d);
    }
    else if (line == true && A == 1)
    {
        A = 2;  
        delay(d);
        turn_180();
        stepsL = 0;
        stepsR = 0;
        delay(d);
    }
    else if (line == true && A == 2)
    {
        stop();
        A = 0;
    }
  
    if (A == 1)
    {
        moveForward();

        selfCenter();

        LSRB();

        LSRB_OP();
    }
  
    if (A == 2)
    {
        moveForward();

        selfCenter();

        shortestPath();  
    }
 

*/