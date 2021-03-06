/*
  Peatit.pde
  
                                    
 #####  ######   ##   ##### # ##### 
 #    # #       #  #    #   #   #   
 #    # #####  #    #   #   #   #   
 #####  #      ######   #   #   #   
 #      #      #    #   #   #   #   
 #      ###### #    #   #   #   #   
                                   

 
  Hit dots in correct order

*/
   
// Arrays Tutorial: http://arduino.cc/en/Reference/Array


#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

// global variables go here
int xcoord = 4;
int ycoord = 3; 
boolean EasyMode = false;
boolean HardMode = true; // "hard" mode is default

int p1_x = random(8);  int p1_y = random(8); // dots
int p2_x = random(6);  int p2_y = random(8);
int p3_x = random(4);  int p3_y = random(8);
int p4_x = random(2);  int p4_y = random(8);

struct Point
{
  int x;
  int y;
  boolean visited;
};

Point p1 = {p1_x, p1_y, false};
Point p2 = {p2_x, p2_y, false};
Point p3 = {p3_x, p3_y, false};
Point p4 = {p4_x, p4_y, false};

Point PointArray[64] = {p1, p2, p3, p4};

// Call p1 [0], p2 [1], p3 [2], etc

/*

OBJECTIVE: Hit dots in correct order



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

1. Show pattern when sitting on origin
2. Hit the dots in the right order

PSEUDO CODE Jan. 2015
1. Draw four dots in 4 random locations
2. Visit dots in the correct order
3. After visiting the 4th and final dot, clear the old dots
4. Draw four dots in 4 random locations, different from the previous locations

*/

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code 
  Serial.begin(9600);
  
}

void loop()  // run over and over again
{
  Serial.print("xcoord is ");  // things in quotes show up literally
  Serial.println(xcoord);  // println is print line
  Serial.print("ycoord is ");
  Serial.println(ycoord);
  Serial.println();
  
  DrawPx(4,3,White); // shows player origin dot
  
  controls();
  core();
  
  DrawPx(xcoord,ycoord,Blue); // draw cursor dot
  
  DisplaySlate();
  delay(150);
  ClearSlate(); 
}


void controls() // taken from Maze_Game
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
  
  if (Button_A) // press A to turn on "hard" mode
  {
    HardMode = true;
    EasyMode = false;
  }
  
  if (Button_B) // press A to turn on "easy" mode
  {
    EasyMode = true;
    HardMode = false;
  }

}

void core()
{
  
if (EasyMode == false)  
{
  if (xcoord == 4)
  {
    if (ycoord == 3) // show dots if on origin dot
    {  
      DrawPx(PointArray[0].x,PointArray[0].y,Yellow);
      DrawPx(PointArray[1].x,PointArray[1].y,Green);
      DrawPx(PointArray[2].x,PointArray[2].y,Red);
      DrawPx(PointArray[3].x,PointArray[3].y,Violet);
    }
  }
}

if (EasyMode == true)  
{
  DrawPx(PointArray[0].x,PointArray[0].y,Yellow);
  DrawPx(PointArray[1].x,PointArray[1].y,Green);
  DrawPx(PointArray[2].x,PointArray[2].y,Red);
  DrawPx(PointArray[3].x,PointArray[3].y,Violet);
}  

if (HardMode == true)  
{
  if (xcoord == 4)
  {
    if (ycoord == 3) // show dots if on origin dot
    {  
      DrawPx(PointArray[0].x,PointArray[0].y,Yellow);
      DrawPx(PointArray[1].x,PointArray[1].y,Green);
      DrawPx(PointArray[2].x,PointArray[2].y,Red);
      DrawPx(PointArray[3].x,PointArray[3].y,Violet);
    }
  }
} 

if (HardMode == false)  
{
  DrawPx(PointArray[0].x,PointArray[0].y,Yellow);
  DrawPx(PointArray[1].x,PointArray[1].y,Green);
  DrawPx(PointArray[2].x,PointArray[2].y,Red);
  DrawPx(PointArray[3].x,PointArray[3].y,Violet);
} 
    
    
  if (xcoord == PointArray[0].x) // checks if cursor hit first dot
  {
    if (ycoord == PointArray[0].y) // [0].x is first point in array
    {
      PointArray[0].visited = true; // must be single equal sign
      Tone_Start(ToneC5, 150); // first dot in order hit confirmed
      // sound is 150 so same as delay so no repeat sounds
    }
  } 
    
  if (PointArray[0].visited == true) // checks first dot visited, MUST BE DOUBLE EQUAL SIGN
  {
    if (xcoord == PointArray[1].x) // checks if cursor hit second dot
    {
      if (ycoord == PointArray[1].y)
      {
        PointArray[1].visited = true; // second dot hit. must be single equal sign
        Tone_Start(ToneD5, 150); // confirms dots have been visited in order
      }
    }
  } 
  else
  {
    PointArray[0].visited = false;
    
    if (xcoord == PointArray[1].x) // second dot hit, first dot not visited
    {
      if (ycoord == PointArray[1].y)
      {
        Tone_Start(ToneC3, 100); // error sound
        xcoord = 4; ycoord = 3; // return to origin if hit dots in wrong order
        delay(150);
      }
    }   
  }
  
  if (PointArray[1].visited == true) // checks second dot visited
        {
          if (xcoord == PointArray[2].x)
          {
            if (ycoord == PointArray[2].y)
            {
              PointArray[2].visited = true; // second dot hit. must be single equal sign
              Tone_Start(ToneE5, 150); // confirms dots have been visited in order
            } 
          }
        }  
        
  else
  {
    PointArray[1].visited = false;
  
    if (xcoord == PointArray[2].x) // second dot hit, first dot not visited
    {
      if (ycoord == PointArray[2].y)
      {
      Tone_Start(ToneC3, 150); // error sound
      xcoord = 4; ycoord = 3; // return to origin if hit dots in wrong order
      delay(150);
      }
    }
  }
  
  if (PointArray[2].visited == true) // checks third dot visited
  {
    if (xcoord == PointArray[3].x) 
    {
      if (ycoord == PointArray[3].y) // if on fourth dot
      {
        PointArray[3].visited = true; // third dot hit. must be single equal sign
        Tone_Start(ToneF5, 200); // confirms all dots have been visited in order
        delay(250);
        PointArray[0].x = random(8); PointArray[0].y = random(8);
        PointArray[0].visited = false; // make all dots unvisited for new level
        PointArray[1].x = random(8); PointArray[1].y = random(8);
        PointArray[1].visited = false;
        PointArray[2].x = random(8); PointArray[2].y = random(8);
        PointArray[2].visited = false;
        PointArray[3].x = random(8); PointArray[3].y = random(8);
        PointArray[3].visited = false;
        xcoord = 4; ycoord = 3; // return to origin if hit dots in wrong order
        Tone_Start(ToneG5, 200); delay(250); // success music
        Tone_Start(ToneA5, 125); delay(150);
        Tone_Start(ToneB5, 125); delay(150);
        Tone_Start(ToneC6, 125); 
      }
    }
  }  
        
  else
  {
    PointArray[2].visited = false;
  
    if (xcoord == PointArray[3].x) // fourth dot hit, first dot not visited
    {
      if (ycoord == PointArray[3].y)
      {
      Tone_Start(ToneC3, 100); // error sound
      xcoord = 4; ycoord = 3; // return to origin if hit dots in wrong order
      delay(150);
      }
    }
  } 
  
}
