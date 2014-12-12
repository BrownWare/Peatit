/*
  Peatit.pde
  
                                    
 #####  ######   ##   ##### # ##### 
 #    # #       #  #    #   #   #   
 #    # #####  #    #   #   #   #   
 #####  #      ######   #   #   #   
 #      #      #    #   #   #   #   
 #      ###### #    #   #   #   #   
                                   

 
  Repeat what you see and hear.

*/
   
// Arrays Tutorial: http://arduino.cc/en/Reference/Array


#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

// global variables go here
int xcoord = 4;
int ycoord = 3;

int p1_c = Yellow; int p2_c = Green;
int p3_c = Red; int p4_c = DimViolet;

int p1_x = 7; // first point x
int p1_y = 4;

int p2_x = 3; // second point x
int p2_y = 7;

int p3_x = 0; // third point x
int p3_y = 4;

int p4_x = 3; // fourth point x
int p4_y = 0;

/*
int marker = 4;
boolean LevelOne = false;
boolean LevelTwo = false;
boolean LevelThree = false; 

struct Point
{
  int x;
  int y;
};

Point p1 = {3,4};
Point p2 = {4,4};
Point p3 = {5,4};
Point p4 = {6,4};

Point PointArray[64] = {p1,p2,p3,p4}; */

/*

IDEAS: Make the dots like a diamond so the user is more challenged.

1. Show dots pattern
2. Hide dots pattern
3. Play sound if user goes in correct order and hits dots
*/

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code
  
}

void loop()  // run over and over again
{
  Level();
  shift();
  DrawPx(xcoord,ycoord,Blue); // draw cursor dot
  DisplaySlate();
  delay(150);
  ClearSlate();
  
}

void Level()
{
  DrawPx(p1_x,p1_y,p1_c); // draw first point
  DrawPx(p2_x,p2_y,p2_c); // draw second dot
  DrawPx(p3_x,p3_y,p3_c); // draw third point
  DrawPx(p4_x,p4_y,p4_c); // draw fourth dot
  
  if (xcoord == p1_x && ycoord == p1_y)
  {
    Tone_Start(ToneC5, 100); delay(125);  
    p1_c = Dark;
  }
  
  if (xcoord == p2_x && ycoord == p2_y)
  {
    Tone_Start(ToneC5, 100); delay(125);  
    p2_c = Dark;
  }
  
  if (xcoord == p3_x && ycoord == p3_y)
  {
    Tone_Start(ToneC5, 100); delay(125);  
    p3_c = Dark;
  }
  
  if (xcoord == p4_x && ycoord == p4_y)
  {
    Tone_Start(ToneC5, 100); delay(125);  
    p4_c = Dark;
  }  
}

void shift() // taken from Maze_Game
{
  
  CheckButtonsDown();
  if (Button_Right)
  {
    if (xcoord < 7)
      xcoord = xcoord + 1; // indented because belongs to inner if statement; could also say xcoord++ 
  }    
  if (Button_Left)
  {
    if (xcoord > 0)
      xcoord = xcoord - 1; 
  }    
    if (Button_Up)
  {
    if (ycoord < 7)
      ycoord = ycoord + 1;
  }    
  
  if (Button_Down)
  {
    if (ycoord > 0)
      ycoord = ycoord - 1;
  } 

  // Level One
/*  if (LevelOne == false)
    for (int i = 0; i < marker; i++)
    { 
      if (xcoord = PointArray[i].x && ycoord = PointArray[i].y)
      {
        if (xcoord = PointArray[i].x && ycoord = PointArray[i].y)
        {
          if (xcoord = PointArray[i].x && ycoord = PointArray[i].y)
          {
            if (xcoord = PointArray[i].x && ycoord = PointArray[i].y)
            {
              LevelTwo = true;
            }
          }
        }
      }
    }
  else
  {
    // Level One Content
    DrawPx (3,7,Red); DisplaySlate(); delay(250); 
    Tone_Start(ToneC5, 100); delay(125);
    DrawPx (7,3,Green); DisplaySlate(); delay(250);
    Tone_Start(ToneE5, 100); delay(125);
    DrawPx (3,0,Blue); DisplaySlate(); delay(250);
    Tone_Start(ToneG5, 100); delay(125);
    DrawPx (0,3,Violet); DisplaySlate(); delay(500);
    Tone_Start(ToneF5, 100); delay(125);
    ClearSlate();   
  } */  
}
