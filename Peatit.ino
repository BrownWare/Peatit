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

struct Point
{
  int x;
  int y;
  boolean visited;
};

Point p1 = {3, 4, false};
Point p2 = {4, 4, false};
Point p3 = {5, 4, false};
Point p4 = {6, 4, false};

Point PointArray[64] = {p1,p2,p3,p4};

int marker = 4;

/*

IDEAS: Make the dots like a diamond so the user is more challenged.

1. Show dots pattern
2. Hide dots pattern
3. Play sound if user goes in correct order and hits dots

REVISION: The game isn't fun or very possible if the user has to memorize the patterns on this screen.
It's better if they can get a little help. So, here's the new alternative gameplay method:

1. Show level one: three different colored dots, each playing a sound on appearing. *NON-LOOPING ANIMATION*
2. The dots stay on screen, but the user must remember in what order they appeared
  i.e. First: Red (3,4), Second: Blue(4,4), Third: Yellow(5,4)
3. Player must move cursor, in this example, first to red, then to blue, then to yellow.
  *Computer must recognize which was done first*
      if Touch First Dot, if Touch Second Dot, if Touch Third Dot, then play WinMusic
      if Touch Third Dot, then Touch Second Dot, then play FailMusic
      
1. Go on Dot1, make Dot 1 visited true and stay true when off dot
2. Go on Dot2, make Dot 2 visited true and stay true when off dot

*/

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code 
}

void loop()  // run over and over again
{
  DrawPx(p1.x,p1.y,Yellow);
  DrawPx(p2.x,p2.y,Green);
  DrawPx(p3.x,p3.y,Red);
  DrawPx(p4.x,p4.y,Violet);
  shift();
  DrawPx(xcoord,ycoord,Blue); // draw cursor dot
  DisplaySlate();
  delay(150);
  ClearSlate(); 
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
  
  if (xcoord == PointArray[1].x) 
  {
    if (ycoord == PointArray[1].y) // checks if cursor hit first dot
    {
      PointArray[1].visited = true; // must be single equal sign
    }
  } 
  
  if (PointArray[1].visited == true) // checks first dot visited, MUST BE DOUBLE EQUAL SIGN
  {
    if (xcoord == PointArray[2].x) // checks if cursor hit second dot
    {
      if (ycoord == PointArray[2].y) 
      {
        PointArray[2].visited = true; // must be single equal sign
        Tone_Start(ToneE5, 100); delay(125); // confirms dots have been visited in order
      }
    }
  } 
  else
  PointArray[1].visited = false;
}
