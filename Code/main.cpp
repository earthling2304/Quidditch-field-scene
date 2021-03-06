
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "Camera.h"
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f }; ///RGBalpha of ambient light
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f }; ///RGBalpha of the diffusion light
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; ///RGBalpha of the specular light
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f }; ///x,y,z,w of the light

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f }; ///rgb values of the material the amt of each that should be emanating.
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void BuildSphere(float tx, float ty, float tz, float radius) /***Builds a Sphere with its center at tx, ty and tz with radius r */
{
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glutSolidSphere(radius, 32, 32);
    glPopMatrix();
    
}


void background()
{
    glBegin(GL_QUADS); ///First dark patch of field
    glColor3f(0.19, 0.79, 0.19);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(10, 0, 80);
    glVertex3f(0, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Second dark patch of field
    glColor3f(0.19, 0.79, 0.19);
    glVertex3f(20, 0, 0);
    glVertex3f(30, 0, 0);
    glVertex3f(30, 0, 80);
    glVertex3f(20, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Third dark patch of field
    glColor3f(0.19, 0.79, 0.19);
    glVertex3f(40, 0, 0);
    glVertex3f(50, 0, 0);
    glVertex3f(50, 0, 80);
    glVertex3f(40, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Last dark patch of field
    glColor3f(0.19, 0.79, 0.19);
    glVertex3f(60, 0, 0);
    glVertex3f(70, 0, 0);
    glVertex3f(70, 0, 80);
    glVertex3f(60, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///First light patch of field
    glColor3f(0.39, 0.99, 0.19);
    glVertex3f(10, 0, 0);
    glVertex3f(20, 0, 0);
    glVertex3f(20, 0, 80);
    glVertex3f(10, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Second dark patch of field
    glColor3f(0.39, 0.99, 0.19);
    glVertex3f(30, 0, 0);
    glVertex3f(40, 0, 0);
    glVertex3f(40, 0, 80);
    glVertex3f(30, 0, 80);
    glEnd();

    glBegin(GL_QUADS); ///Third dark patch of field
    glColor3f(0.39, 0.99, 0.19);
    glVertex3f(50, 0, 0);
    glVertex3f(60, 0, 0);
    glVertex3f(60, 0, 80);
    glVertex3f(50, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Last dark patch of field
    glColor3f(0.39, 0.99, 0.19);
    glVertex3f(70, 0, 0);
    glVertex3f(80, 0, 0);
    glVertex3f(80, 0, 80);
    glVertex3f(70, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Left wall of the bounding box
    glColor3f(0.627, 0.904, 0.976);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 80, 0);
    glVertex3f(0, 80, 80);
    glVertex3f(0, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Right wall of the bounding box
    glColor3f(0.627, 0.904, 0.976);
    glVertex3f(80, 0, 0);
    glVertex3f(80, 80, 0);
    glVertex3f(80, 80, 80);
    glVertex3f(80, 0, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Front wall of the bounding box
    glColor3f(0.627, 0.904, 0.976);
    glVertex3f(0, 0, 80);
    glVertex3f(80, 0, 80);
    glColor3f(0.59, 0.79, 0.99);
    glVertex3f(80, 80, 80);
    glVertex3f(0, 80, 80);
    glEnd();
    
    glBegin(GL_QUADS); ///Back wall of the bounding box
    glColor3f(0.627, 0.904, 0.976);
    glVertex3f(0, 0, 0);
    glVertex3f(80, 0, 0);
    glColor3f(0.59, 0.79, 0.99);
    glVertex3f(80, 80, 0);
    glVertex3f(0, 80, 0);
    glEnd();
    
    glBegin(GL_QUADS); ///Top wall of the bounding box
    glColor3f(0.59, 0.79, 0.99);
    glVertex3f(0, 80, 0);
    glVertex3f(80, 80, 0);
    glVertex3f(80, 80, 80);
    glVertex3f(0, 80, 80);
    glEnd();
    
}
vvoid wings(int a){

     if (a==1){  /// ball for only the snitch
    ///center ball for the snitch
    glEnable(GL_LIGHTING);  ///enable the lighting calculations
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);  ///set light source parameters attributes being(no of the light,parameter being set,values of the parameter)
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    ///set the material parameters for the object being drawn attributes being(the obj side being drawn,parameter,values of the parameter)
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);///exponent of the specular component
    glNormal3f(1.0,0.0,0.0); ///direction of the lighting frm the source
    glPushMatrix();
    glTranslatef(0, 0, -1.15);
    glColor3f(0.99,0.83,0);
    glutSolidSphere(.025, 32, 32);
    glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);  ///disable the lighting

    glColor3f(0.82, 0.82, 0.82);  ///change the color of the wings to grey
     }

     else if(a==0){
     glEnable(GL_LIGHTING);  ///enable the lighting calculations
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);///exponent of the specular component
    glNormal3f(0.0,1.0,0.0); ///direction of the lighting frm the source
    glPushMatrix();
    glTranslatef(0, 0, -1.15);
    glutSolidSphere(.020, 32, 32);
    glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);  ///disable the lighting
     }

    ///1st wing
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,-1.15);
    glVertex3f(-0.1,0.1,-1.15);
    glVertex3f(-0.3,0,-1.15);
    glEnd();

    ///3rd wing
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,-1.15);
    glVertex3f(-0.08,-0.05,-1.15);
    glVertex3f(-0.2,-0.02,-1.15);
    glEnd();

    ///2nd wing
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,-1.15);
    glVertex3f(0.3,0,-1.15);
    glVertex3f(0.1,0.1,-1.15);
    glEnd();

    ///4th wing
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,-1.15);
    glVertex3f(0.08,-0.05,-1.15);
    glVertex3f(0.2,-0.02,-1.15);
    glEnd();

}

void bats(){
    ///returns the time elapsed frm the time gluinit was called in milliseconds
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*10.0;

    int s=(int)a%2;
    double tr;

    if(s==0){tr=0.5;} ///translate +y for half time
    else{tr=-0.5;} ///translate -y for the next

    ///1st bat
    glPushMatrix();
    glTranslatef(-0.5, 0.4,-1.15); ///start drawing after this translation
    glPushMatrix();
    glTranslatef(0,tr/10,0); ///for the animated movement of the bat
    glScalef(0.3, 0.3, 0.3); ///decrease the size
    wings(0);
    glPopMatrix();
    glPopMatrix();
    glFlush();

    ///2nd bat
    glPushMatrix();
    glTranslatef(0.5,0.4,-1.15);
    glPushMatrix();
    glTranslatef(0,tr/10,0);
    glScalef(0.3, 0.3, 0.3);
    wings(0);
    glPopMatrix();
    glPopMatrix();
    glFlush();

    ///3rd bat
    glPushMatrix();
    glTranslatef(-1,0.4,-0.6);
    glPushMatrix();
    glTranslatef(0,tr/10,0);
    glScalef(0.3, 0.3, 0.3);
    wings(0);
    glPopMatrix();
    glPopMatrix();
    glFlush();

    ///4th bat
    glPushMatrix();
    glTranslatef(1,0.4,-0.6);
    glPushMatrix();
    glTranslatef(0,tr/10,0);
    glScalef(0.3, 0.3, 0.3);
    wings(0);
    glPopMatrix();
    glPopMatrix();
    glFlush();
}

void snitch(){
    wings(1);
}


void BuildTorus(float tx, float ty, float tz, float inner_radius, float outer_radius) /**The function builds a torus with given inner and outer radii at tx, ty, tz */
{
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glutSolidTorus(inner_radius, outer_radius, 32, 100);
    glPopMatrix();
}


void Quidditch_Balls()
{   glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glNormal3f(0.0,-1.0,0.0);
    glColor3f(0.44,0.148,0.085);
    BuildSphere(4,0.5,10,1.0);
    glColor3f(0.613,0.566,0.554);
    BuildSphere(20,0.75,10,1.5);
    glColor3f(0.44,0.148,0.085);
    BuildSphere(25,0.25,15,0.5);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}

void Cuboid(float tx, float ty, float tz, float length, float width, float height) /**The function builds a cuboid from quads with the bottom, right, backward facing vertex being positioned at tx, ty, tz with the given length, breadth and height parameters - length is along the X axis, height is along the Y axis and width is along the Z axis*/
{
    
    ///Bottom Face
    glBegin(GL_QUADS);
    glVertex3f(length, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, width);
    glVertex3f(length, 0, width);
    glEnd();
    
    ///Back Face
    glBegin(GL_QUADS);
    glVertex3f(length, 0, 0);
    glVertex3f(length, height, 0);
    glVertex3f(0, height, 0);
    glVertex3f(0, 0, 0);
    glEnd();
    
    ///Top Face
    glBegin(GL_QUADS);
    glVertex3f(length, height, 0);
    glVertex3f(0, height, 0);
    glVertex3f(0, height, width);
    glVertex3f(length, height, width);
    glEnd();
    
    ///Front Face
    glBegin(GL_QUADS);
    glVertex3f(length, 0, width);
    glVertex3f(length, height, width);
    glVertex3f(0, height, width);
    glVertex3f(0, 0, width);
    glEnd();
    
    ///Left Face
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, width);
    glVertex3f(0, height, width);
    glVertex3f(0, height, 0);
    glEnd();
    
    ///Right Face
    glBegin(GL_QUADS);
    glVertex3f(length, 0, 0);
    glVertex3f(length, 0, width);
    glVertex3f(length, height, width);
    glVertex3f(length, height, 0);
    glEnd();
    
}

void Trunk() /**The function uses three cuboids to generate a trunk making use of the Cuboid function */
{
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(20, 0, 20);
    glColor3f(0.6, 0.2980, 0);
    Cuboid(0, 0, 0, 4, 2, 2);
    glColor3f(0.8, 0.4, 0);
    glTranslatef(0, 2, 0);
    Cuboid(0, 0, 0, 4, 2, 0.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 0.6980, 0.4);
    glTranslatef(22, 2, 22);
    Cuboid(0, 0, 0, 0.5, 0.5, 0.5);
    glPopMatrix();
}

void Stands()
{
    
    glPushMatrix();
    glColor3f(0.83, 0.68, 0.214);
    glTranslatef(-2, 0, 15);
    glRotatef(90, 0, 1, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /**Cuboid in base colour for the stands */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /**Cuboid in base colour for the stands */
    glColor3f(0.99, 0.14, 0); /** Red - for Gryffindor */
    glTranslatef(0, -6, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /** Middle portion of the stand in the house colour */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 0.5, 4); /**Tallest seating step */
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 3);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 2);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 1); /**Shortest seating step */
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.83, 0.68, 0.214);
    glTranslatef(-2, 0, 21);
    glRotatef(90, 0, 1, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /**Cuboid in base colour for the stands */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /**Cuboid in base colour for the stands */
    glColor3f(0.99, 0.14, 0); /** Red - for Gryffindor */
    glTranslatef(0, -6, 0);
    Cuboid(0, 0, 0, 2, 2, 6);  /** Middle portion of the stand in the house colour */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 0.5, 4); /**Tallest seating step */
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 3);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 2);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 1); /**Shortest seating step */
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.83, 0.68, 0.214);
    glTranslatef(41, 0, 13);
    glRotatef(-90, 0, 1, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /**Cuboid in base colour for the stands */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /**Cuboid in base colour for the stands */
    glColor3f(0, 0, 1); /**Blue - for Ravenclaw */
    glTranslatef(0, -6, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /** Middle portion of the stand in the house colour */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 0.5, 4); /**Tallest seating step */
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 3);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 2);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 1); /**Shortest seating step */
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.83, 0.68, 0.214);
    glTranslatef(41, 0, 19);
    glRotatef(-90, 0, 1, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /**Cuboid in base colour for the stands */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 2, 6); /**Cuboid in base colour for the stands */
    glColor3f(0, 0, 1); /**Blue - for Ravenclaw */
    glTranslatef(0, -6, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /** Middle portion of the stand in the house colour */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 0.5, 4); /**Tallest seating step */
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 3);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 2);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 1); /**Shortest seating step */
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.83, 0.68, 0.214);
    glTranslatef(13, 0, -2);
    Cuboid(0, 0, 0, 2, 2, 6);   /**Cuboid in base colour for the stands */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /**Cuboid in base colour for the stands */
    glColor3f(0.99, 0.99, 0.39);
    glTranslatef(0, -6, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /** Middle portion of the stand in the house colour */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 0.5, 4); /**Tallest seating step */
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 3);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 2);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 1); /**Shortest seating step */
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.83, 0.68, 0.214);
    glTranslatef(19, 0, -2);
    Cuboid(0, 0, 0, 2, 2, 6);   /**Cuboid in base colour for the stands */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /**Cuboid in base colour for the stands */
    glColor3f(0.99, 0.99, 0.39);
    glTranslatef(0, -6, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /** Middle portion of the stand in the house colour */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 0.5, 4);   /**Tallest seating step */
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 3);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 2);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 1);  /**Shortest seating step */
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.83, 0.68, 0.214);
    glTranslatef(15, 0, 41);
    glRotatef(-180, 0, 1, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /**Cuboid in base colour for the stands */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /**Cuboid in base colour for the stands */
    glColor3f(0, 0.39, 0);
    glTranslatef(0, -6, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /** Middle portion of the stand in the house colour */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 0.5, 4);  /**Tallest seating step */
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 3);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 2);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 1);     /**Shortest seating step */
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.83, 0.68, 0.214);
    glTranslatef(21, 0, 41);
    glRotatef(-180, 0, 1, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /**Cuboid in base colour for the stands */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 2, 6);   /**Cuboid in base colour for the stands */
    glColor3f(0, 0.39, 0);
    glTranslatef(0, -6, 0);
    Cuboid(0, 0, 0, 2, 2, 6);    /** Middle portion of the stand in the house colour */
    glTranslatef(0, 12, 0);
    Cuboid(0, 0, 0, 2, 0.5, 4);  /**Tallest seating step */
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 3);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 2);
    glTranslatef(0, 0, 0.5);
    Cuboid(0, 0, 0, 2, 0.5, 1);  /**Shortest seating step */
    glPopMatrix();
    
}

void BuildCone(float tx, float ty, float tz, float base, float height) /**This function builds a Cone with center of base at tx, ty, tz given the height and radius parameter (base), along the Z-axis */
{
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(base, height, 32, 32);
    glPopMatrix();
}

void BuildCylinder(GLUquadricObj* temp, float tx, float ty, float tz, float top_radius, float bottom_radius, float height)
/**This function builds a Frustum with center of base at tx, ty, tz given the height and radii, along the Z-axis */
{
    temp=gluNewQuadric();
    gluQuadricNormals(temp, GLU_SMOOTH);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(temp, top_radius, bottom_radius, height, 32, 32);
    glPopMatrix();
    
}

void Trees()
/**The function builds Trees using cylinders and cones along the left and right edges of the field */
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glColor3f(0, 1, 0);
    BuildCone(-27,10,-10,4,10);
    BuildCone(-27,10,0,4,10);
    BuildCone(-27,10,10,4,10);
    BuildCone(-27,10,20,4,10);
    BuildCone(-27,10,30,4,10);
    BuildCone(-27,10,40,4,10);
    BuildCone(-27,10,50,4,10);
    BuildCone(-27,10,60,4,10);
    BuildCone(-27,10,70,4,10);
    BuildCone(-27,10,80,4,10);
    BuildCone(-27,10,90,4,10);
    
    glColor3f(0.6, 0.2980, 0);
    GLUquadricObj *tree1, *tree2, *tree3, *tree4, *tree5;
    BuildCylinder(tree1, -27, 0, -10, 1.2, 1.2, 10);
    BuildCylinder(tree2, -27, 0, 0, 1.2, 1.2, 10);
    BuildCylinder(tree3, -27, 0, 10, 1.2, 1.2, 10);
    BuildCylinder(tree4, -27, 0, 20, 1.2, 1.2, 10);
    BuildCylinder(tree4, -27, 0, 30, 1.2, 1.2, 10);
    BuildCylinder(tree4, -27, 0, 40, 1.2, 1.2, 10);
    BuildCylinder(tree4, -27, 0, 50, 1.2, 1.2, 10);
    BuildCylinder(tree4, -27, 0, 60, 1.2, 1.2, 10);
    BuildCylinder(tree4, -27, 0, 70, 1.2, 1.2, 10);
    BuildCylinder(tree4, -27, 0, 80, 1.2, 1.2, 10);
    BuildCylinder(tree4, -27, 0, 90, 1.2, 1.2, 10);
    
    
    glColor3f(0, 1, 0);
    BuildCone(100,10,-10,4,10);
    BuildCone(100,10,0,4,10);
    BuildCone(100,10,10,4,10);
    BuildCone(100,10,20,4,10);
    BuildCone(100,10,30,4,10);
    BuildCone(100,10,40,4,10);
    BuildCone(100,10,50,4,10);
    BuildCone(100,10,60,4,10);
    BuildCone(100,10,70,4,10);
    BuildCone(100,10,80,4,10);
    BuildCone(100,10,90,4,10);
    glColor3f(0.6, 0.2980, 0);
    BuildCylinder(tree1, 100, 0, -10, 1.2, 1.2, 10);
    BuildCylinder(tree2, 100, 0, 0, 1.2, 1.2, 10);
    BuildCylinder(tree3, 100, 0, 10, 1.2, 1.2, 10);
    BuildCylinder(tree4, 100, 0, 20, 1.2, 1.2, 10);
    BuildCylinder(tree4, 100, 0, 30, 1.2, 1.2, 10);
    BuildCylinder(tree4, 100, 0, 40, 1.2, 1.2, 10);
    BuildCylinder(tree4, 100, 0, 50, 1.2, 1.2, 10);
    BuildCylinder(tree4, 100, 0, 60, 1.2, 1.2, 10);
    BuildCylinder(tree4, 100, 0, 70, 1.2, 1.2, 10);
    BuildCylinder(tree4, 100, 0, 80, 1.2, 1.2, 10);
    BuildCylinder(tree4, 100, 0, 90, 1.2, 1.2, 10);
    glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}
void flag(float tx, float ty, float tz, float height, float width)
/**The function builds a flag '|>' with the bottom-left vertex at tx, ty, tz, the height (along Y) and the width (here, along X) are given as parameters */
 
{
    glBegin(GL_TRIANGLES);
    glVertex3f(tx, ty, tz);
    glVertex3f(tx, ty+height, tz);
    glVertex3f(tx+width, ty+(float)height/2, tz+(float)width/2);
    glEnd();
}
void tower()
/** A tower is assembled from a flag mounted on the apex of a cone that is mounted appropriately on a cylinder with the same radius as the cone */
{
    glColor3f(0.23, 0.45, 0.678); /** Steel grey for the cylinder and cones */
    BuildCone(0,15,-3, 0.3, 2);
    BuildCone(12,15,-3, 0.3, 2);
    BuildCone(24,15,-3, 0.3, 2);
    BuildCone(36,15,-3, 0.3, 2);
    
    GLUquadricObj *quadric1, *quadric2, *quadric3, *quadric4;
    BuildCylinder(quadric1, 0, 0, -3, 0.3, 0.3, 15);
    BuildCylinder(quadric2, 12, 0, -3, 0.3, 0.3, 15);
    BuildCylinder(quadric3, 24, 0, -3, 0.3, 0.3, 15);
    BuildCylinder(quadric4, 36, 0, -3, 0.3, 0.3, 15);
    
    glColor3f(0.99, 0.14, 0); /** Red - Gryffindor */
    flag(0, 17, -3, 1, 1);
    glColor3f(0, 0, 1); /** Blue - Ravenclaw */
    flag(12, 17, -3, 1, 1);
    glColor3f(0.99, 0.99, 0.39); /**Canary Yellow - Hufflepuff */
    flag(24, 17, -3, 1, 1);
    glColor3f(0, 0.39, 0); /** Green - Slytherin */
    flag(36, 17, -3, 1, 1);
    
}

void Quidditch_Poles()
/**Three Quidditch Poles build from Cylinders and Torii are placed on the Field */
{
    glColor3f(0.23, 0.45, 0.678);
    GLUquadricObj *qdc1, *qdc2, *qdc3;
    glPushMatrix();
    glTranslatef(15, 0, 25);
    BuildCylinder(qdc1, 2, 0, 0, 0.4, 0.4, 15);
    BuildTorus(2, 16.5, 0, 0.1, 1.75);
    
    glTranslatef(10, 0, 0);
    BuildCylinder(qdc2, 2, 0, 0, 0.4, 0.4, 15);
    BuildTorus(2, 16.5, 0, 0.1, 1.75);
    
    glTranslatef(-5, 0, -8);
    BuildCylinder(qdc3, 2, 0, 0, 0.4, 0.4, 15);
    BuildTorus(2, 16.5, 0, 0.1, 1.75);
    glPopMatrix();
    
}

void drawGrid()
/**A grid function (not displayed) - Used as reference for placing objects */
{
    int i;
    for(i=0; i<160; i++)
    {
        glPushMatrix();
        glTranslatef(-10, 0, -10);
        glPushMatrix();
        if(i<80) glTranslatef(0, 0, (float)i);
        if(i>=80)
        {
            glTranslatef(i-80, 0, 0);
            glRotatef(-90, 0, 1, 0);
            
        }
        
        glColor3f(0.121, 0.9141, 0.311);
        glBegin(GL_LINES);
        glLineWidth(1);
        glVertex3f(0, 0, 0);
        glVertex3f(79, 0, 0);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();
}

void init()
{
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
    ///Allocate colour display buffer and depth buffer
    glEnable(GL_DEPTH_TEST);									///Enable depth testing for hidden surface removal
    glDepthMask(GL_TRUE);                   ///enable for writing into the depth buffer
    glDepthFunc(GL_LEQUAL);                ///for comapring the values 
    glDepthRange(0.0f, 1.0f);              
    
    glShadeModel(GL_SMOOTH);		/// Enable smooth shading
    glClearColor(1, 1, 1, 1.0f);	///Set default clear colour
    glClearDepth(1.0);
}

void display()   ///rendering occurs here
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///clear the color and the depth buffer before each rendering occurs
    
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*2000.0;
    
    glPushMatrix();
    glRotatef(30,1,0,0);   ///rotate 30 degrees counterclockwise about the y axis
    glTranslatef(-0.775, -1.6, -2.8);   ///after rotation translate
    glScalef(0.043, 0.043, 0.043);     ///scale down the size of the elements being drawn
    ///drawGrid();
    tower();
    Quidditch_Poles();
    Stands();
    Trunk();
    Quidditch_Balls();
    glColor3d(0.99,0.83,0);
    Trees();
    
    glPushMatrix();
    glTranslatef(-20, 0, -20);
    background();
    glPopMatrix();
    
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.4, -1.15);
    glRotated(a, 0, 0, 1);
    snitch();
    glPopMatrix();
    
    glColor3f(0, 0, 0);
    bats();
    glutSwapBuffers();         ///swaping the current buffer with the back buffer, used in case of double buffers
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;						/// To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;	/// Set the aspect ratio of the clipping volume to match the viewport
    glViewport(0, 0, width, height);					/// Set the viewport to cover the new window
    glMatrixMode(GL_PROJECTION);						/// Operate on the Projection matrix
    glLoadIdentity();                                   ///loads the identitty matrix
    gluPerspective(60.0f, aspect, 0.1f, 500.0f);        ///sets the projection matrix with the view angle to 60, the aspect ratio, the near plane and the far plane.
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();		/// Enable perspective projection with fovy, aspect, zNear and zFar
}

static void idle(void)
{
    glutPostRedisplay();    ///for calling the main loop to draw again. this enable the motion for the elements.
}
Camera cam;
void keyboard(unsigned char key, int x,int y){
    switch (key){
            
        case 'u': cam.translate(0,0.05,0);
            break;
        case 'd': cam.translate(0,-0.05, 0);
            break;
        case 'l': cam.translate(-0.05,0,0);
            break;
        case ';': cam.translate(0.05,0,0);
            break;
        case 'z': cam.translate(0,0,-0.05);
            break;
        case 'q': cam.translate(0,0,0.05);
            break;
        case 'y': cam.yaw(1);
            break;
        case 't': cam.yaw(-1);
            break;
        case 'p': cam.pitch(1);
            break;
        case 'o': cam.pitch(-1);
            break;
        case 'r': cam.roll(1);
            break;
        case 'e': cam.roll(-1);
            break;
        default: return;
    }
    glutPostRedisplay();
    ///	display();
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);  ///configuration and opening
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Quidditch Field");
    init();    ///sets opengl States and variables
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); ///function for resizing the window
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard); ///handle keyboard events
    glutMainLoop();  ///entr event driven loop
    return 0;
}

