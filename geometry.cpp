//solution by Wsl_F
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#define author Wsl_F
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <x86intrin.h>

using namespace std;

typedef long long LL;
typedef double dbl;
typedef vector<int> vi;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)


#define sqr(x) ((x)*(x))
 const double eps= 1e-8;

template <typename tPoint>
class Point
{
typedef double real;

    protected:
     tPoint x;
     tPoint y;

    public:
     Point(tPoint x0, tPoint y0) { x= x0; y= y0; }
     Point()                     { x= 0;  y= 0;  }
     Point(const Point<tPoint> & p0)     { x= p0.x; y= p0.y;}

     tPoint getX()           { return x; }
     void setX( tPoint x0)   { x= x0;    }

     tPoint getY()           { return y; }
     void setY( tPoint y0)   { y= y0;    }

     void setXY(tPoint x0, tPoint y0) {x= x0; y= y0;}

     real distance(tPoint p2) //distance between this and p2
     {
        return sqrt(sqr(x-p2.x)+sqr(y-p2.y));
     }

    Point<tPoint> & operator = (Point<tPoint> & p2)
	{
		if(this != &p2)
		{
		    setX(p2.getX());
		    setY(p2.getY());
		}
		return *this;
	}
};



    template <typename tPoint>
    std::istream & operator >>(std::istream & is, Point<tPoint> & p)
    {
        tPoint x0,y0;
        is>>x0>>y0;
        p.setX(x0);  p.setY(y0);
        return is;
    }

    template <typename tPoint>
    std::ostream & operator <<(std::ostream & os, Point<tPoint> & p)
    {
        os<<p.getX()<<" "<<p.getY();
        return os;
    }


    template <typename tPoint>
    bool operator==(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        if (p1.getX()==p2.getX() && p1.getY()==p2.getY()) return true;
        else return false;
    }

    template <typename tPoint>
    bool operator!=(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        if (p1.getX()!=p2.getX() || p1.getY()!=p2.getY()) return true;
        else return false;
    }

























template <typename tPoint>
class Vector : public Point<tPoint>
{
  public:
      Vector() : Point<tPoint>() {  }
      Vector(tPoint x0, tPoint y0) : Point<tPoint>(x0,y0) {  }
  public:
      bool collinear(Vector<tPoint> v2)
      // if this collinear v2 return true else return false
      {
        if (fabs((*this).x*v2.y-(*this).y*v2.x)<eps) return true;
        else return false;
      }

      bool sameDirection(Vector<tPoint> v2)
      // if this has same direction with v2 return true else return false
      // WARNINGS!!!method doesn't check that vectors are collinear
      {
        if ( (  ( (*this).x>-eps && v2.x>-eps )  ||  ( (*this).x<eps && v2.x<eps )  ) &&
             (  ( (*this).y>-eps && v2.y>-eps )  ||  ( (*this).y<eps && v2.y<eps )  ) )
             return true;
        else return false;
      }

      int multiplyVectorSgn(Vector<tPoint> v2)
      { // if vectors multiply >= 0  return 1 else return -1
          if (((*this).x*v2.y-(*this).y*v2.x)<eps) return 1;
          return -1;
      }

      tPoint multiplyVector(Vector<tPoint> v2)
      { // return vectors multiply
          return ((*this).x*v2.y-(*this).y*v2.x);
      }

};

    template <typename tPoint>
    bool operator==(Vector<tPoint>  & v1, Vector<tPoint>  & v2)
    { // vectors are collinear and have same direction
        return (v1.collinear(v2) && v1.sameDirection(v2));
    }




























template <typename tPoint>
class Segment
{
    protected:
     Point<tPoint> p1,p2;

    public:

     Segment()                                      { p1.setX(0); p1.setY(0);   p2.setX(0); p2.setY(0); }
     Segment(Point<tPoint> p10, Point<tPoint> p20)  { p1= p10;                  p2= p20;                }

     void setP1(Point<tPoint> p10)         {p1= p10;   }
      Point<tPoint> getP1()           {return p1; }

     void setP2(Point<tPoint> p20)         {p2= p20;   }
      Point<tPoint> getP2()           {return p2; }

    Segment<tPoint> & operator = (Segment<tPoint> & sg2)
	{
		if(this != &p2)
		{
		    setP1(sg2.getP1());
		    setP2(sg2.getP2());
		}
		return *this;
	}

    bool contain(Point<tPoint> p)
    // if this contain p return true else return false
    {
     if (p1==p || p2==p) return true;
     Vector<tPoint> v1(p.getX()-p1.getX(),p.getY()-p1.getY()); // vector (P1;P)
     Vector<tPoint> v2(p.getX()-p2.getX(),p.getY()-p2.getY()); // vector (P2;P)

     return (v1.collinear(v2) && !v1.sameDirection(v2));
    }

    bool intersection(Segment<tPoint> sg2)
    {// if this intersections sg2 return true else return false
        if (contain(sg2.getP1()) || contain(sg2.getP2())) return true;
        if (sg2.contain(p1)      || sg2.contain(p2)     ) return true;

        Vector<tPoint> ab(p2.getX()-p1.getX(),p2.getY()-p1.getY()); //p1 - a, p2 - b
        Vector<tPoint> v1(sg2.p1.getX()-p1.getX(),sg2.p1.getY()-p1.getY());
        Vector<tPoint> v2(sg2.p2.getX()-p1.getX(),sg2.p2.getY()-p1.getY());

        if (ab.multiplyVectorSgn(v1)==ab.multiplyVectorSgn(v2)) return false; // if line AB doesn't intersect segment CD

        ab.setXY(sg2.p2.getX()-sg2.p1.getX(),sg2.p2.getY()-sg2.p1.getY());
        v1.setXY(p1.getX()-sg2.p1.getX(),p1.getY()-sg2.p1.getY());
        v2.setXY(p2.getX()-sg2.p1.getX(),p2.getY()-sg2.p1.getY());

        if (ab.multiplyVectorSgn(v1)==ab.multiplyVectorSgn(v2)) return false; // if line CD doesn't intersect segment AB

        v1.setXY(p2.getX()-p1.getX(),p2.getY()-p1.getY());
        if (!ab.collinear(v1)) return true;

        return false;
    }

};



    template <typename tPoint>
    std::istream & operator >>(std::istream & is, Segment<tPoint> & sg)
    {
        Point<tPoint> p1,p2;
        is>>p1>>p2;
        sg.setP1(p1); sg.setP2(p2);
        return is;
    }

    template <typename tPoint>
    std::ostream & operator <<(std::ostream & os, Segment<tPoint> & sg)
    {
        Point<tPoint> p1(sg.getP1());
        Point<tPoint> p2(sg.getP2());
        os<<p1<<" "<<p2;
        return os;
    }

    template <typename tPoint>
    bool operator==(Segment<tPoint>  & sg1, Segment<tPoint>  & sg2)
    {
        if ( (sg1.getP1()== sg2.getP1() && sg1.getP2()== sg2.getP2()) ||
             (sg1.getP1()== sg2.getP2() && sg1.getP2()== sg2.getP1())  )
             return true;
        else return false;
    }

    template <typename tPoint>
    bool operator!=(Segment<tPoint>  & sg1, Segment<tPoint>  & sg2)
    {
        return (!(sg1==sg2));
    }

































int RectanglesIntersects(double x1,double y1,double x2,double y2,

                         double x3,double y3,double x4,double y4)

{

  if ((x3 - x2)*(x4 - x1) > 0) return 0;

  if ((y3 - y2)*(y4 - y1) > 0) return 0;

  return 1;

}

double intersect(double x1,double y1, double x2, double y2,

                 double x3,double y3, double x4, double y4)

{

  double ABx, ABy, ACx, ACy, ADx, ADy;

  double CAx, CAy, CBx, CBy, CDx, CDy;

  double ACxAB, ADxAB, CAxCD, CBxCD;

  if (!RectanglesIntersects(min(x1,x2),min(y1,y2),max(x1,x2),max(y1,y2),

      min(x3,x4),min(y3,y4),max(x3,x4),max(y3,y4))) return 0;

  ACx = x3 - x1; ACy = y3 - y1;

  ABx = x2 - x1; ABy = y2 - y1;

  ADx = x4 - x1; ADy = y4 - y1;

  CAx = x1 - x3; CAy = y1 - y3;

  CBx = x2 - x3; CBy = y2 - y3;

  CDx = x4 - x3; CDy = y4 - y3;

  ACxAB = ACx * ABy - ACy * ABx;

  ADxAB = ADx * ABy - ADy * ABx;

  CAxCD = CAx * CDy - CAy * CDx;

  CBxCD = CBx * CDy - CBy * CDx;

  return ACxAB * ADxAB <= 0 && CAxCD * CBxCD <= 0;

}

void test()
{

 Segment<int> s1,s2;
 //cin>>s1>>s2;
// if (s1.intersection(s2)) cout<<"Yes"<<endl;
 //else cout<<"No"<<endl;
 Point <int> p1,p2,p3,p4;

 LL x1,x2,x3,x4,y1,y2,y3,y4;
 #define fr(t) for (t=-1; t<=1; t++)

   fr(x1)
   fr(y1)
 {
     p1.setXY(x1,y1);
     s1.setP1(p1);
     fr(x2)
     {
         fr(y2)
         {
             p2.setXY(x2,y2);
             s1.setP2(p2);
             fr(x3)
             {
                 fr(y3)
                 {
                     p3.setXY(x3,y3);
                     s2.setP1(p3);
                     fr(x4)
                     {
                         fr(y4)
                         {
                             p4.setXY(x4,y4);
                             s2.setP2(p4);
                             if (s1.intersection(s2)!=intersect(x1,y1,x2,y2,x3,y3,x4,y4))
                             {
                                 cout<<s1<<endl<<s2<<endl<<endl;
                             }
                         }
                     }
                 }
             }
         }
     }
 }


}



























real det (real a, real b, real c, real d)
 {
	return a * d - b * c;
 }

template <typename tPoint>
class Point
{

    protected:
     tPoint x;
     tPoint y;

    public:
     Point(tPoint x0, tPoint y0) { x= x0; y= y0; }
     Point()                     { x= 0;  y= 0;  }
     Point(const Point<tPoint> & p0)     { x= p0.x; y= p0.y;}

     tPoint getX()           { return x; }
     void setX( tPoint x0)   { x= x0;    }

     tPoint getY()           { return y; }
     void setY( tPoint y0)   { y= y0;    }

     void setXY(tPoint x0, tPoint y0) {x= x0; y= y0;}

     real distance(tPoint p2) //distance between this and p2
     {
        return sqrt(sqr(x-p2.x)+sqr(y-p2.y));
     }

    Point<tPoint> & operator = (Point<tPoint> & p2)
	{
		if(this != &p2)
		{
		    setX(p2.getX());
		    setY(p2.getY());
		}
		return *this;
	}
};



    template <typename tPoint>
    std::istream & operator >>(std::istream & is, Point<tPoint> &  p)
    {
        tPoint x0,y0;
        is>>x0>>y0;
        p.setX(x0);  p.setY(y0);
        return is;
    }

    template <typename tPoint>
    std::ostream & operator <<(std::ostream & os, Point<tPoint>  p)
    {
        os<<p.getX()<<" "<<p.getY();
        return os;
    }


    template <typename tPoint>
    bool operator==(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        if (p1.getX()==p2.getX() && p1.getY()==p2.getY()) return true;
        else return false;
    }

    template <typename tPoint>
    bool operator!=(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        if (p1.getX()!=p2.getX() || p1.getY()!=p2.getY()) return true;
        else return false;
    }

























template <typename tPoint>
class Vector : public Point<tPoint>
{
  public:
      Vector()                                      : Point<tPoint> ()                                          {  }
      Vector(tPoint x0, tPoint y0)                  : Point<tPoint> (x0,y0)                                     {  }
      Vector(Point<tPoint> p)                       : Point<tPoint> (p)                                         {  }
      Vector(Point<tPoint> p1, Point<tPoint> p2)    : Point<tPoint> (p2.getX()-p1.getX(),p2.getY()-p1.getY())   {  }

  public:
      bool collinear(Vector<tPoint> v2)
      // if this collinear v2 return true else return false
      {
        if (fabs((*this).x*v2.y-(*this).y*v2.x)<eps) return true;
        else return false;
      }

      bool sameDirection(Vector<tPoint> v2)
      // if this has same direction with v2 return true else return false
      // WARNINGS!!!method doesn't check that vectors are collinear
      {
        if ( (  ( (*this).x>-eps && v2.x>-eps )  ||  ( (*this).x<eps && v2.x<eps )  ) &&
             (  ( (*this).y>-eps && v2.y>-eps )  ||  ( (*this).y<eps && v2.y<eps )  ) )
             return true;
        else return false;
      }

      int multiplyVectorSgn(Vector<tPoint> v2)
      { // if vectors multiply >= 0  return 1 else return -1
          if (((*this).x*v2.y-(*this).y*v2.x)<eps) return 1;
          return -1;
      }

      tPoint multiplyVector(Vector<tPoint> v2)
      { // return vectors multiply
          return ((*this).x*v2.y-(*this).y*v2.x);
      }

};

    template <typename tPoint>
    bool operator==(Vector<tPoint>  & v1, Vector<tPoint>  & v2)
    { // vectors are collinear and have same direction
        return (v1.collinear(v2) && v1.sameDirection(v2));
    }




























template <typename tPoint>
class Segment
{
    protected:
     Point<tPoint> p1,p2;

    public:

     Segment()                                      { p1.setX(0); p1.setY(0);   p2.setX(0); p2.setY(0); }
     Segment(Point<tPoint> p10, Point<tPoint> p20)  { p1= p10;                  p2= p20;                }

     void setP1(Point<tPoint> p10)          { p1= p10;   }
     Point<tPoint> getP1()                  { return p1; }

     void setP2(Point<tPoint> p20)          { p2= p20;   }
     Point<tPoint> getP2()                  { return p2; }

     void setP1P2(Point<tPoint> p10, Point<tPoint> p20) { p1= p10; p2= p20; }

    Segment<tPoint> & operator = (Segment<tPoint> & sg2)
	{
		if(this != &p2)
		{
		    setP1(sg2.getP1());
		    setP2(sg2.getP2());
		}
		return *this;
	}

    bool contain(Point<tPoint> p)
    // if this contain p return true else return false
    {
     if (p1==p || p2==p) return true;
     Vector<tPoint> v1(p.getX()-p1.getX(),p.getY()-p1.getY()); // vector (P1;P)
     Vector<tPoint> v2(p.getX()-p2.getX(),p.getY()-p2.getY()); // vector (P2;P)

     return (v1.collinear(v2) && !v1.sameDirection(v2));
    }

    bool intersection(Segment<tPoint> sg2)
    {// if this intersections sg2 return true else return false
        if (contain(sg2.getP1()) || contain(sg2.getP2())) return true;
        if (sg2.contain(p1)      || sg2.contain(p2)     ) return true;

        Vector<tPoint> ab(p2.getX()-p1.getX(),p2.getY()-p1.getY()); //p1 - a, p2 - b
        Vector<tPoint> v1(sg2.p1.getX()-p1.getX(),sg2.p1.getY()-p1.getY());
        Vector<tPoint> v2(sg2.p2.getX()-p1.getX(),sg2.p2.getY()-p1.getY());

        if (ab.multiplyVectorSgn(v1)==ab.multiplyVectorSgn(v2)) return false; // if line AB doesn't intersect segment CD

        ab.setXY(sg2.p2.getX()-sg2.p1.getX(),sg2.p2.getY()-sg2.p1.getY());
        v1.setXY(p1.getX()-sg2.p1.getX(),p1.getY()-sg2.p1.getY());
        v2.setXY(p2.getX()-sg2.p1.getX(),p2.getY()-sg2.p1.getY());

        if (ab.multiplyVectorSgn(v1)==ab.multiplyVectorSgn(v2)) return false; // if line CD doesn't intersect segment AB

        v1.setXY(p2.getX()-p1.getX(),p2.getY()-p1.getY());
        if (!ab.collinear(v1)) return true;

        return false;
    }

};



    template <typename tPoint>
    std::istream & operator >>(std::istream & is, Segment<tPoint> & sg)
    {
        Point<tPoint> p1,p2;
        is>>p1>>p2;
        sg.setP1(p1); sg.setP2(p2);
        return is;
    }

    template <typename tPoint>
    std::ostream & operator <<(std::ostream & os, Segment<tPoint> & sg)
    {
        Point<tPoint> p1(sg.getP1());
        Point<tPoint> p2(sg.getP2());
        os<<p1<<" "<<p2;
        return os;
    }

    template <typename tPoint>
    bool operator==(Segment<tPoint>  & sg1, Segment<tPoint>  & sg2)
    {
        if ( (sg1.getP1()== sg2.getP1() && sg1.getP2()== sg2.getP2()) ||
             (sg1.getP1()== sg2.getP2() && sg1.getP2()== sg2.getP1())  )
             return true;
        else return false;
    }

    template <typename tPoint>
    bool operator!=(Segment<tPoint>  & sg1, Segment<tPoint>  & sg2)
    {
        return (!(sg1==sg2));
    }










template <typename tPoint, typename tParam>
class LineABC
{
 private:
     tParam a,b,c;
 public:
    LineABC() : a(0),b(0),c(0)                                      {   }
    LineABC(tParam a0, tParam b0, tParam c0)  : a(a0),b(b0),c(c0)   {   }
    LineABC(Segment<tPoint> sg)
    {
       makeLineABC(sg.getP1(),sg.getP2(),a,b,c);
    }

    LineABC(Point<tPoint> A, Point<tPoint> B)
    {
       makeLineABC(A,B,a,b,c);
    }

    void setA(tParam A)                         { a= A;             }
    void setB(tParam B)                         { b= B;             }
    void setC(tParam C)                         { c= C;             }
    void setABC(tParam A, tParam B, tParam C)   { a= A; b= B; c= C; }

    tParam getA()   { return a; }
    tParam getB()   { return b; }
    tParam getC()   { return c; }
    void getABC(tParam & A, tParam & B, tParam & C)   { A= a; B= b; C= c; }

 private:
    static void makeLineABC(Point<tPoint> A, Point<tPoint> B, tParam & a, tParam & b, tParam & c)
    {
        if (A==B) {a= 0; b= 0; c= 0; return;} // points the same

        a= B.getY()-A.getY();
        b= A.getX()-B.getX();
        c= B.getX()*A.getY()-A.getX()*B.getY();
        //cout<<"make Line: "<<A<<" , "<<B<<endl<<a<<" "<<b<<" "<<c<<endl<<endl;
        //cout<<"end"<<endl;
    }

 public:
    bool isIntersection(LineABC l2)
    {
        return !(fabs(a*l2.b-b*l2.a)<eps);
    }

    Point<tPoint> intersection(LineABC l2)
    {
        if (!isIntersection(l2))
        {
            cout<<"Lines are parallel or same"<<endl;
            return Point<tPoint> (0,0);
        }

        tPoint x,y;
        x= -((c*l2.b-b*l2.c)/(a*l2.b-b*l2.a));
        y= -((a*l2.c-c*l2.a)/(a*l2.b-b*l2.a));


        if (fabs(x)<eps) x= 0;
        if (fabs(y)<eps) y= 0;

        return Point<tPoint>((tPoint) x, (tPoint) y);
    }


    bool contain(Point<tPoint> p)
    {
        return (fabs(a*p.getX()+b*p.getY()+c)<eps);
    }

    tPoint distance(Point<tPoint> p)
    {
        return (fabs(a*p.getX()+b*p.getY()+c)/sqrt(sqr(a)+sqr(b)));
    }
};




    template <typename tPoint, typename tParam>
    std::istream & operator >>(std::istream & is, LineABC<tPoint,tParam> & l)
    {
        tParam a,b,c;
        is>>a>>b>>c;
        l.setABC(a,b,c);
        return is;
    }

    template <typename tPoint, typename tParam>
    std::ostream & operator <<(std::ostream & os, LineABC<tPoint,tParam> & l)
    {
        tParam a,b,c;
        l.getABC(a,b,c);
        os<<a<<" "<<b<<" "<<c;
        return os;
    }


    template <typename tPoint, typename tParam>
    bool operator==(LineABC<tPoint,tParam>  & l1, LineABC<tPoint,tParam>  & l2)
    {
        tParam a1,b1,c1,a2,b2,c2;
        l1.getABC(a1,b1,c1);
        l2.getABC(a2,b2,c2);


        if (fabs(a1)>eps && fabs(a2)>eps)
        {
            b1/= a1; c1/= a1;
            b2/= a2; c2/= a2;
            return ((fabs(b1-b2)<eps)&&(fabs(c1-c2)<eps));
        }

        if (fabs(b1)>eps && fabs(b2)>eps)
        {
            a1/= b1; c1/= b1;
            a2/= b2; c2/= b2;
            return ((fabs(a1-a2)<eps)&&(fabs(c1-c2)<eps));
        }

        if (fabs(c1)>eps && fabs(c2)>eps)
        {
            a1/= c1; b1/= c1;
            a2/= c2; b2/= c2;
            return ((fabs(a1-a2)<eps)&&(fabs(b1-b2)<eps));
        }

        return false;
    }


    template <typename tPoint, typename tParam>
    bool operator!=(LineABC<tPoint,tParam>  & l1, LineABC<tPoint,tParam>  & l2)
    {
        return !(l1==l2);
    }
