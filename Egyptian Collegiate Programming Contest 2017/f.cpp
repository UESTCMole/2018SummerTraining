#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;
struct Point {
    double x, y;
    Point (double x = 0, double y =  0) : x(x), y(y) {}
    friend bool operator < (const Point& a, const Point& b) {
        return a.x < b.x || (a.x==b.x && a.y < b.y);
    }
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y / p); }

const double eps = 1e-10;
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

bool operator == (const Point& A, const Point& B) {
    return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}

double dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double length(Vector A) { return sqrt(dot(A, A)); }
double angle(Vector A, Vector B) { return acos(dot(A, B) / length(A) / length(B)); }
double cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }

Vector rotate(Vector A, double rad) {
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
struct Line {
    Point p;
    Vector v;
};

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = cross(a2-a1, b1-a1), c2 = cross(a2-a1, b2-a1),
           c3 = cross(b2-b1, a1-b1), c4 = cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}

Point GetLineIntersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p-q;
    double t = cross(w, u) / cross(v, w);
    return p + v*t;
}

double DistanceToLine(Point p, Point a, Point b) {
    Vector v1 = b-a, v2 = p-a;
    return fabs(cross(v1, v2)) / length(v1);
}

double DistanceToSegment(Point p, Point a, Point b) {
    if (a == b) return length(p-a);
    Vector v1 = b-a, v2 = p-a, v3 = p-b;
    if (dcmp(dot(v1, v2)) < 0) return length(v2);
    else if (dcmp(dot(v1, v3)) > 0) return length(v3);
    else return fabs(cross(v1, v2)) / length(v1);
}

Point GetLineProjection(Point p, Point a, Point b) {
    Vector v = b-a;
    return a+v*(dot(v,p-a) / dot(v,v));
}

bool OnSegment(Point p, Point a1, Point a2) {
    return dcmp(cross(a1-p, a2-p)) == 0 && dcmp(dot(a1-p, a2-p)) < 0;
}

bool OnLine(Point p, Point a1, Point a2) {
    return dcmp(cross(a1-p, a2-p)) == 0;
}

double PolygonArea(Point* p, int n) {
    double area = 0;
    for (int i = 1; i < n-1; i++) area += cross(p[i]-p[0], p[i+1]-p[0]);
    return area/2;
}

int n;
Point p[50005];

int main() {
  freopen("flags.in", "r", stdin);
  int T, cas = 0; scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
    int q; scanf("%d", &q);
    printf("Case %d:\n", ++cas);
    while (q--) {
      double ans = 100000000000.0;
      double ansx, ansy;
      Point Ans;
      double x1, y1, x2, y2; scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
      for (int i = 1; i <= n; i++) {
        Point A = p[i];
        Point B; 
        if(i == n) B = p[1];
        else B = p[i+1];
        Point tmp = GetLineProjection((Point){x1, y1}, A, B);
        double x0 = tmp.x, y0 = tmp.y;
        Point another = (Point) {2*x0-x1, 2*y0-y1};
        if (dcmp(ans-length(another - (Point){x2, y2})) > 0) {
          ans = length(another - (Point){x2,y2});
          Ans = GetLineIntersection(A, B-A, (Point){x2, y2}, another- (Point){x2, y2});
        }
      }
      printf("%.7f %.7f %.7f\n", ans, Ans.x, Ans.y);
    }
  }
}















