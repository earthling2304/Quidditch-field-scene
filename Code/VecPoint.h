#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define PI 3.14159265358979323846
using namespace std;

class Vec{ /** class Vec defines a vector- instantiated to keep track of the basis vectors at point where camera is located */
public:
  float x,y,z;
  void set(float a, float b, float c){
    x = a;
    y = b;
    z = c;
  }
 float dot(Vec v){
    return (x*v.x + y*v.y + z*v.z);
  }

};

class Point{ /** class Point defines a point vector; instantiated to keep track of the point where the camera is located*/
public:
  float x,y,z;
  float dot(Vec v){
    return (x*v.x + y*v.y + z*v.z);
  }

};


