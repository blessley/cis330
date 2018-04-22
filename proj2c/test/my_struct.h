/* This file should contain your struct definitions for Circle, Triangle, and 
   Rectangle */

typedef struct
{
  double radius;
  double origin[2];
} Circle;

typedef struct
{
  double pt1[2]; //Base point
  double pt2[2]; //Base point
  double pt3[2];
} Triangle;

typedef struct
{
  double pt1[2]; //Bottom left
  double pt2[2]; //Bottom right 
  double pt3[2]; //Top left
  double pt4[2]; //Top right
} Rectangle;


