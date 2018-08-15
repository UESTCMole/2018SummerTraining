#include <bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){};
};

typedef Point Vector;

const Vector x_pos_semi_axis=Point(1,0);
const Vector y_pos_semi_axis=Point(0,1); 

const double PI=acos(-1.0);
const double eps=1e-6;
int dcmp (double x){if(fabs(x)<eps)return 0;else return x<0?-1:1;}

Vector operator + (Vector A,Vector B) {return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Vector A,Vector B) {return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double p) {return Vector(A.x*p,A.y*p);}
Vector operator / (Vector A,double p) {return Vector(A.x/p,A.y/p);}

bool operator < (const Point &a,const Point &b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator > (const Point &a,const Point &b){return a.x>b.x||(a.x==b.x&&a.y>b.y);}
bool operator == (const Point &a,const Point &b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}

double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double angle(Vector A){return atan2(A.y,A.x);}
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}

Vector Rotate(Vector A,double rad){return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}
Vector Normal(Vector A){double L=Length(A);return Vector(-A.y/L,A.x/L);}


struct Circle{
	Point c;double r;
	Circle (Point c,double r):c(c),r(r){}
	Point point(double angle){
		return Point(c.x+r*cos(angle),c.y+r*sin(angle));
	}
};

double Circle_Circle_Area_of_overlap(Circle c1, Circle c2){
    double d=Length(c1.c-c2.c);
    if(dcmp(c1.r+c2.r-d)<=0) return 0;
    if(dcmp(fabs(c1.r-c2.r)-d)>=0){
        double minr = min(c1.r,c2.r);
        return PI*minr*minr;
    }
    double x=(d*d + c1.r*c1.r - c2.r*c2.r)/(2*d);
    double t1=acos(x/c1.r);
    double t2=acos((d-x)/c2.r);
    return c1.r*c1.r*t1 + c2.r*c2.r*t2 - d*c1.r*sin(t1);
}

double W,H;
double S1,S2,S3;

double r1,r2;

int main(){
	cin>>W>>H;
	cin>>S1>>S2>>S3;
	double r1=sqrt(S1/PI),r2=sqrt(S2/PI);
	
	if(2*max(r1,r2)>min(W,H)){puts("impossible");return 0;}
	
	double l=0;double r=sqrt((W-r1-r2)*(W-r1-r2)+(H-r1-r2)*(H-r1-r2));
	
	Circle C1=Circle(Point(0,0),r1);
	Circle C2=Circle(Point(0,r),r2);
	double S=Circle_Circle_Area_of_overlap(C1,C2);//最远下能否小于等于所求 
	
	if(S>S3){puts("impossible");return 0;}
	
	double dis;
	while(true){
		double mid = (r + l)/2;
		C2.c=Point(0,mid);
		double S=Circle_Circle_Area_of_overlap(C1,C2);
		if(dcmp(S-S3)==0){
			dis=mid;
			break;
		}
		if(S<S3)r=mid;else l=mid;
		
		//cout << S << " " << mid << " " << l << endl;
		//system("pause");
	}
	
	bool flag=false;
	if(r1<r2)swap(C1,C2),swap(r1,r2),flag=true;
	C1.c=Point(W-r1,H-r1);
	Vector x = Point(r2,r2)-Point(W-r1,H-r1);
	double L = Length(x);
	C2.c=C1.c+x*(dis/L);
	if(flag)swap(C1,C2);
	
	printf("%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf",C1.c.x,C1.c.y,C1.r,C2.c.x,C2.c.y,C2.r);
	
	return 0;
}
