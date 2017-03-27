#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include"VecPoint.h"
#define PI 3.14159265358979323846
using namespace std;


class Camera{ ///Camera class to contain attributes for moving the camera
public:
  Point eye; ///The struct Point contains attributes of a point. eye is the point where camera is located
  Vec u, v, n; /// u,v and n vectors from the camera

  Camera(){ /**The basis vectors are initialized as the x, y and z vectors as in the world coordinates employed by openGL when camera is initialized*/
    u.set(1,0,0);
    v.set(0,1,0);
    n.set(0,0,1);
  }

void setM(){ /**Function to set model view matrix after every transformation is applied so that the coordinates are transformed and displayed*/
    float M[16];
    Vec e;
    e.set(eye.x, eye.y, eye.z);
    M[0] = u.x;
    M[1] = v.x;
    M[2] = n.x;
    M[3] = 0;
    M[4] = u.y;
    M[5] = v.y;
    M[6] = n.y;
    M[7] = 0;
    M[8] = u.z;
    M[9] = v.z;
    M[10] = n.z;
    M[11] = 0;
    M[12] = -e.dot(u);
    M[13] = -e.dot(v);
    M[14] = -e.dot(n);
    M[15] = 1;  
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(M);
}

  void translate(float du, float dv, float dn){/**Function to translate the camera by du along u, dv along v, dn along n*/
    eye.x += du*u.x + dv*v.x + dn*n.x; /// projection along x direction to obtain the new x coords for eye
    eye.y += du*u.y + dv*v.y + dn*n.y; /// projection along x direction to obtain the new y coords for eye
    eye.z += du*u.z + dv*v.z + dn*n.z; /// projection along x direction to obtain the new z coords for eye
    setM();
  }
  void pitch(const float angle){ /**Function to rotate about u by angle given as argument*/
    float Cos = cos(angle*PI/180); ///convert to radians and take cosine
    float Sin = sin(angle*PI/180); ///convert to radians and take sine
    Vec p = n;
    n.set(p.x*Cos + v.x*Sin, p.y*Cos + v.y*Sin, p.z*Cos+v.z*Sin);
    Vec q = v;
    v.set(-p.x*Sin + q.x*Cos,-p.y*Sin + q.y*Cos,-p.z*Sin + q.z*Cos );
    setM();
  }
  void roll(const float angle){ /**Function to rotate about n by angle given as an argument*/
    float Cos = cos(angle*PI/180); ///convert to radians and take cosine
    float Sin = sin(angle*PI/180); ///convert to radians and take sine
    Vec p = u;
    u.set(p.x*Cos - v.x*Sin, p.y*Cos - v.y*Sin, p.z*Cos - v.z*Sin);
    Vec q = v;
    v.set(p.x*Sin + q.x*Cos,p.y*Sin + q.y*Cos,p.z*Sin + q.z*Cos );
    setM();
}
    void yaw(const float angle){ /**Function to rotate about v by angle given as an argument*/
    
    float Cos = cos(angle*PI/180); ///convert to radians and take cosine
    float Sin = sin(angle*PI/180); ///convert to radians and take cosine
    Vec p = u;
    u.set(p.x*Cos + n.x*Sin, p.y*Cos + n.y*Sin, p.z*Cos+n.z*Sin);
    Vec q = n;
    n.set(-p.x*Sin + q.x*Cos,-p.y*Sin + q.y*Cos,-p.z*Sin + q.z*Cos);
    setM();
}
    


};



