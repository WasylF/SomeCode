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


template <typename T>
class SegmentTree
{
 private:
     int nMax;      //maximum number of elements in the array
     T* a;          // segment tree as array
                    // a[i] has 2 sons: left - a[2*i], right - a[2*i+1]
     T (*f)(T,T);   //function:  a[i]= f(a[2*i],a[2*i+1])
                    //by default:   f(x,y)= x+y
     T zero;        //zero value
                    //by default:   zero = 0


 //constructors:
 public:
    SegmentTree()//+
    {//empty constructor.     !!!! never use it
        nMax= 0;
        a= NULL;
        f= NULL;
        zero= T();
    }


    SegmentTree(int n)//+
    {//constructor for tree with not more than n (nMax) elements
        zero= T();
        f= &_F;
        initialization(n);
    }

    SegmentTree(int n, T zero0)//+
    {//constructor for tree with not more than n (nMax) elements and zero value zero0
        zero= zero0;
        f= &_F;
        initialization(n);
    }


    SegmentTree(int n, T* b)//+
    {//constructor for array b with n elements
        zero= T();
        f= &_F;
        initialization(n);
        leafsFill(n,b);
        build();
    }

    SegmentTree(int n, T* b, T zero0)//+
    {//constructor for array b with n elements and zero value zero0
        zero= zero0;
        f= &_F;
        initialization(n);
        leafsFill(n,b);
        build();
    }


    SegmentTree(int n, T (*F)(T,T))//+
    {//constructor for tree with not more than n (nMax) elements, function - F
        zero= T();
        f= F;
        initialization(n);
    }

    SegmentTree(int n, T (*F)(T,T), T zero0)//+
    {//constructor for tree with not more than n (nMax) elements, function - F, and zero value zero0
        zero= zero0;
        f= F;
        initialization(n);
    }


    SegmentTree(int n, T* b, T(*F)(T,T))//+
    {//constructor for array b with n elements, function - F
        zero= T();
        f= F;
        initialization(n);
        leafsFill(n,b);
        build();
    }

    SegmentTree(int n, T* b, T(*F)(T,T), T zero0)//+
    {//constructor for array b with n elements, function - F
        zero= zero0;
        f= F;
        initialization(n);
        leafsFill(n,b);
        build();
    }



 //main methods:
 public:
    void update(int i, T value)//+
    { // change value of element with index i to "value"
       if (i>=nMax) return; //incorrect value
       a[nMax+i]= value;
       refresh(nMax+i);
    }

    T value(int i)//+
    {// return value of element with index i
       if (i>=nMax) return NULL; //incorrect value
        return a[nMax+i];
    }

    T query(int l, int r)//+
    {// return value function f on the segment [l;r]
        return query(max(l,0),min(r,nMax-1),0,nMax-1,1);
    }

    void clear()//+
    {// clear segment tree. set zero value for all elements in the tree
        arrayFillZero();
    }



 private:
    void initialization(int n)//+
    {// initializes nMax and a
     // n - number of elements in the array
     // calculate nMax
     // and create array for segment tree
        nMax= 1;
        while (nMax<n) nMax<<= 1;

        a= new T[nMax*2];
        arrayFillZero();
    }

    void arrayFillZero()//+
    {// set zero value for all elements in the array
        for (int i= 2*nMax-1; i>=0; i--)
            a[i]= zero;
    }

    void leafsFill(int n, T* b)//+
    { // array b from n elements copping to the leafs
        for (int i=0; i<n; i++)
            a[nMax+i]= b[i];
    }



    static T _F(T _a, T _b)//+
    {// default value of function f
        return _a+_b;
    }

    void build()//+
    {// build segment tree from leafs
        for (int i=nMax-1; i>0; i--)
            a[i]= f(a[2*i],a[2*i+1]);
    }

    void refresh(int i)//+
    {// calculate new values for parents
     // i - leaf
        while (i>1)
        {
          i/= 2;
          a[i]= f(a[2*i],a[2*i+1]);
        }
    }

    T query(int l, int r, int leftPosition, int rightPosition, int v) //+
    {// return value function f on the intersection segments [l;r] and [leftPosition;rightPosition]
     // l - left side of segment
     // r - right side of segment
     // v - vertex of segment tree
     // [leftPosition; rightPosition] - segment that corresponds v
        if (r<l) return zero;
        if (l==leftPosition && r==rightPosition) return a[v];
        int middle= (leftPosition+rightPosition)/2;

        return f(query(l,min(middle,r),leftPosition,middle,v*2),query(max(l,middle+1),r,middle+1,rightPosition,v*2+1));
    }

    void print() //for debug
    {//print tree to the output
        for (int i=1; i<nMax; i++)
            cout<<a[i]<<" ";
        cout<<endl<<endl;
        for (int i=0; i<nMax; i++)
            cout<<a[nMax+i]<<" ";
        cout<<endl;
    }
};



 int funct(int a, int b)
 {
     return max(a,b);
 }

 typedef pair<int, int> pii;

int main()
{

 ios_base::sync_with_stdio(0);
 cin.tie(0);

  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
 srand(__rdtsc());

 int a[]= {0,1,2,3,4,5,6,7,8,9,10};

 SegmentTree<char> chst();
 SegmentTree<int> sst(10);
 SegmentTree<int> st(11,a);
 //st.print();
 cout<<endl;

 int l,r;
 char c;
 while (cin>>c>>l>>r)
 {
     if (c=='?') cout<<st.query(l,r)<<endl;
     else st.update(l,r);
 }
 return 0;
}


