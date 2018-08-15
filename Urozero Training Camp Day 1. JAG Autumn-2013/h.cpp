#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
const double pi = acos(-1.0);
const double eps = 1e-6;
double w, h, a, b, c;
double xa, ya, xb, yb, ra, rb;
int dcmp(int x) {
  if (x>eps) return 1;
  if (x<-eps) return -1;
  return 0;
}

double area(double x1, double y1, double x2, double y2) {
  double dis = sqrt((y1-y2)*(y1-y2)+(x2-x1)*(x2-x1));
  if (dcmp(dis-ra-rb) != -1) return 0.0;
  if (dcmp(dis-rb) != -1) {
    double alpha = 2.0*acos((ra*ra+dis*dis-rb*rb)/2.0/dis/ra);
    if (dcmp(alpha) == -1) alpha += 2*pi;
    double beta = 2.0*acos((rb*rb+dis*dis-ra*ra)/2.0/dis/rb);
    if (dcmp(beta) == -1) beta += 2*pi;
    double s1 = ra*ra*alpha/2.0-ra*ra*sin(alpha)/2.0;
    double s2 = rb*rb*beta/2.0-rb*rb*sin(beta)/2.0;
    return s1+s2;
  } else {
    double alpha = acos((ra*ra+dis*dis-rb*rb)/2.0/ra/dis);
    if (dcmp(alpha) == -1) alpha += 2*pi;
    double beta = acos((rb*rb+dis*dis-ra*ra)/2.0/rb/dis);
    if (dcmp(beta) == -1) beta += 2*pi;
    beta *= 2.0;
    alpha *= 2.0;
    double s1 = ra*ra*alpha/2.0;
    alpha = 2.0*pi-alpha;
    s1 += ra*ra*sin(alpha)/2.0;
    double s2 = rb*rb*beta/2.0-rb*rb*sin(beta)/2.0;
    return s1+s2;
  }
}
int main() {
  scanf("%lf%lf%lf%lf%lf", &w, &h, &a, &b, &c);
  if (dcmp(w-h) == -1) std::swap(w, h);
  if (dcmp(a-b) == 1) std::swap(a, b);
  ra = sqrt(a/pi), rb = sqrt(b/pi);
  xa = ya = ra, xb = w-rb, yb = h-rb;
  double len = sqrt((xa-xb)*(xa-xb)+(ya-yb)+(ya-yb));
  if (dcmp(area(xa, ya, xb, yb)-c)==1) {
    puts("impossible");
    return 0;
  }
  double l = 0.0, r = len;
  while (1) {
    double mid = (l+r)/2;
    double x1 = xa+(xb-xa)*mid/len;
    double y1 = ya+(yb-ya)*mid/len;
    if (dcmp(area(x1,y1,xb,yb)-c) == 0) {
      printf("%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf", x1, y1, ra, xb, yb, rb);
      return 0;
    }
    else if (dcmp(area(x1,y1,xb,yb)-c)>0) r=mid;
    else l=mid;
  }
  
}
