/* This file should contain the 9 functions defined in prototypes.h */

#include <prototypes.h>

void InitializeCircle(Circle *c, double radius, double originX, double originY)
{
  c->radius = radius;
  c->origin[0] = originX;
  c->origin[1] = originY;
}
void InitializeRectangle(Rectangle *r, double minX, double maxX, double minY, double maxY)
{
  r->pt1[0] = minX;
  r->pt1[1] = minY;

  r->pt2[0] = maxX;
  r->pt2[1] = minY;

  r->pt3[0] = minX;
  r->pt3[1] = maxY;

  r->pt4[0] = maxX;
  r->pt4[1] = maxY;
}

void InitializeTriangle(Triangle *t, double pt1X, double pt2X, double minY, double maxY)
{
  t->pt1[0] = pt1X;
  t->pt1[1] = minY;

  t->pt2[0] = pt2X;
  t->pt2[1] = minY;

  t->pt3[0] = (pt1X + pt2X)/2;
  t->pt3[1] = maxY;
}

double GetCircleArea(Circle *c)
{
  return 3.14159*c->radius*c->radius;
}

double GetRectangleArea(Rectangle *r)
{
  return (r->pt2[0] - r->pt1[0]) * (r->pt4[1] - r->pt2[1]);
}

double GetTriangleArea(Triangle *t)
{
  return (t->pt2[0] - t->pt1[0]) * (t->pt3[1] - t->pt1[1])/2;
}

void GetCircleBoundingBox(Circle *c, double *box)
{
  box[0] = c->origin[0] - c->radius;
  box[1] = c->origin[0] + c->radius;
  box[2] = c->origin[1] - c->radius;
  box[3] = c->origin[1] + c->radius;
}
void GetRectangleBoundingBox(Rectangle *r, double *box)
{
  box[0] = r->pt1[0];
  box[1] = r->pt2[0];
  box[2] = r->pt2[1];
  box[3] = r->pt4[1];
}

void GetTriangleBoundingBox(Triangle *t, double *box)
{
  box[0] = t->pt1[0];
  box[1] = t->pt2[0];
  box[2] = t->pt2[1];
  box[3] = t->pt3[1];
}

