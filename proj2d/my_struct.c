/* This file should contain the 9 functions defined in prototypes.h */

#include <prototypes.h>

void InitializeCircle(struct Shape *s, double radius, double originX, double originY)
{
  s->t = CIR;
  s->ft.GetArea = GetCircleArea;
  s->ft.GetBoundingBox = GetCircleBoundingBox;
  Circle c;
  c.radius = radius;
  c.origin[0] = originX;
  c.origin[1] = originY;
  s->u.c = c;
}
void InitializeRectangle(struct Shape *s, double minX, double maxX, double minY, double maxY)
{
  s->t = REC;
  s->ft.GetArea = GetRectangleArea;
  s->ft.GetBoundingBox = GetRectangleBoundingBox;
  Rectangle r;
  r.pt1[0] = minX;
  r.pt1[1] = minY;

  r.pt2[0] = maxX;
  r.pt2[1] = minY;

  r.pt3[0] = minX;
  r.pt3[1] = maxY;

  r.pt4[0] = maxX;
  r.pt4[1] = maxY;
  s->u.r = r;
}

void InitializeTriangle(struct Shape *s, double pt1X, double pt2X, double minY, double maxY)
{
  s->t = TRI;
  s->ft.GetArea = GetTriangleArea;
  s->ft.GetBoundingBox = GetTriangleBoundingBox;
  Triangle t;
  t.pt1[0] = pt1X;
  t.pt1[1] = minY;

  t.pt2[0] = pt2X;
  t.pt2[1] = minY;

  t.pt3[0] = (pt1X + pt2X)/2;
  t.pt3[1] = maxY;
  s->u.t = t;
}

double GetCircleArea(struct Shape *s)
{
  double radius = s->u.c.radius;
  return 3.14159*radius*radius;
}

double GetRectangleArea(struct Shape *s)
{
  Rectangle r = s->u.r;
  return (r.pt2[0] - r.pt1[0]) * (r.pt4[1] - r.pt2[1]);
}

double GetTriangleArea(struct Shape *s)
{
  Triangle t = s->u.t;
  return (t.pt2[0] - t.pt1[0]) * (t.pt3[1] - t.pt1[1])/2;
}

void GetCircleBoundingBox(struct Shape *s, double *box)
{
  Circle c = s->u.c;
  box[0] = c.origin[0] - c.radius;
  box[1] = c.origin[0] + c.radius;
  box[2] = c.origin[1] - c.radius;
  box[3] = c.origin[1] + c.radius;
}
void GetRectangleBoundingBox(struct Shape *s, double *box)
{
  Rectangle r = s->u.r;
  box[0] = r.pt1[0];
  box[1] = r.pt2[0];
  box[2] = r.pt2[1];
  box[3] = r.pt4[1];
}

void GetTriangleBoundingBox(struct Shape *s, double *box)
{
  Triangle t = s->u.t;
  box[0] = t.pt1[0];
  box[1] = t.pt2[0];
  box[2] = t.pt2[1];
  box[3] = t.pt3[1];
}

