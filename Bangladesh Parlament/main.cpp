#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846


GLfloat position1 = 2.0f;
GLfloat speed1 = 0.01f;
GLfloat speed = 0.01f;
GLfloat speedCloud = 0.01f;
GLfloat rPosition = 0.0f;
GLfloat rSpeed = 0.1f;
GLfloat pPosition = 3.0f;
GLfloat pSpeed = 0.1f;

GLfloat speedCblue= 0.04f;
GLfloat speedCbrown= 0.2f;
GLfloat position2 = 1.0f;
GLfloat positionColud = 1.0f;
GLfloat positionSun = 0.2f;
GLfloat speedSun= 0.003f;

GLfloat position3 = -1.0f;
GLfloat R = 248;
GLfloat G = 248;
GLfloat B = 255;

GLfloat pR = 153;
GLfloat pG = 204;
GLfloat pB = 255;
void Rain();
void DisplayRain();

void Dis();
void displayMorning();
void fillCircle();

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void updateCloud(int value){

     if(positionColud<-1.0)
        positionColud =1.0f;

     positionColud -=speedCloud;
     glutPostRedisplay();
     glutTimerFunc(100,updateCloud,0);

}
void updateSun(int value){

     if(positionSun<-1.0)
        positionSun =3.0f;

     positionSun-=speedSun;
     glutPostRedisplay();
     glutTimerFunc(100,updateSun,0);

}

void update2 (int value){

     if(position2<-8.0)
        position2 =1.0f;
     position2 -=speedCbrown;

     if (rPosition < -1.0)
        rPosition = 1.0f;
    rPosition -= rSpeed;

    if (pPosition < -3.0)
        pPosition = 3.0f;
    pPosition -= pSpeed;

     glutPostRedisplay();
     glutTimerFunc(100,update2,0);

}
void update3 (int value){

     if(position3>2.0)
        position3 =-2.0f;

     position3 +=speedCblue;
     glutPostRedisplay();
     glutTimerFunc(100,update3,0);

}
void update1(int value) {

    if(position1 >2.0)
        position1 =- 1.0f;

    position1 += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update1, 0);
}
void soundRain()
{

    PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void soundCar()
{

    PlaySound("car.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}
void soundHorn()
{

    PlaySound("horn.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}
void soundPlane()
{

    PlaySound("airland.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}
void soundBird()
{

    PlaySound("Bird.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void soundNight()
{

    PlaySound("night.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void circle(GLfloat x,GLfloat y,GLfloat radius){
       int i;

	//GLfloat x=.4f; GLfloat y=.4f; GLfloat radius =.2f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);

		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    }
    void cloud(){
 glColor3ub(255, 255, 255);
   circle(.5f,.9f,.2f);
   circle(.25f,.9f,.15f);
    circle(.69f,.9f,.15f);
   glLoadIdentity();

    }
      void sun(){

glTranslatef(-.23f,.93f,0);
 glColor3ub(255, 255, 128);
circle(.0f,.0f,.06f);
   glLoadIdentity();
    }
void Moon(){
glTranslatef(-.23f,.93f,0);
 glColor3ub(242, 245, 230);
circle(.0f,.0f,.06f);
glColor3ub(74, 74, 70);
circle(.009f,0.003f,.06f);
   glLoadIdentity();
    }
    void Bird(){

   glColor3ub(255, 204, 0);
   circle(.0f,.0f,.07f);
   circle(.07f,.07f,.04f);
   glColor3ub(0, 0, 0);
   circle(.08f,.08f,.012f);
 glBegin(GL_TRIANGLES);
    glColor3ub(230, 46, 0);
    glVertex2f(0.14f,0.02f);
    glVertex2f(0.11f,0.07f);
    glVertex2f(0.097f,0.045f);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255, 153, 153);
    glVertex2f(-0.01,0.06);
    glVertex2f(-0.04,0.0);
    glVertex2f(-0.04,0.0);
    glVertex2f(0.05,0.0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(173, 173, 133);
    glVertex2f(-0.02,-0.07);
    glVertex2f(-0.03,-0.09);
    glVertex2f(-0.03,-0.09);
    glVertex2f(0.0,-0.12);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(173, 173, 133);
    glVertex2f(0.02,-0.07);
    glVertex2f(0.0,-0.09);
    glVertex2f(0.0,-0.09);
    glVertex2f(0.04,-0.12);
    glEnd();
}
void MoreBird(){
 glScalef(.3,.3,0);
glTranslatef(-1.0,2.9,0);
Bird();
glTranslatef(-1.2,2.9,0);
Bird();
glTranslatef(-1.2,3.3,0);
Bird();
}
void Tree_Trinagle(){
glBegin(GL_QUADS);
glColor3ub(184, 134, 28);
glVertex2f(0.01f,0.0f);
glVertex2f(0.01f,0.4f);
glVertex2f(-0.01f,0.4f);
glVertex2f(-0.01f,0.0f);
glEnd();
glBegin(GL_TRIANGLES);
glColor3ub(14, 115, 21);
glVertex2f(0.15f,0.3f);
glVertex2f(0.0f,0.55f);
glVertex2f(-0.15f,0.3f);
glEnd();
//2nd
glBegin(GL_TRIANGLES);
glColor3ub(14, 115, 21);
glVertex2f(0.15f,0.41f);
glVertex2f(0.0f,0.75f);
glVertex2f(-0.15f,0.41f);
glEnd();
//3rd
glBegin(GL_TRIANGLES);
glColor3ub(14, 115, 21);
glVertex2f(0.15f,0.51f);
glVertex2f(0.0f,0.85f);
glVertex2f(-0.15f,0.51f);
glEnd();
}
void BackgroundDay(){

//background
glBegin(GL_QUADS);
glColor3ub(204, 230, 255);
glVertex2f(1.0f,0.0f);
glVertex2f(1.0f,1.0f);
glVertex2f(-1.0f,1.0f);
glVertex2f(-1.0f,0.0f);
glEnd();
}
void BackgroundDayRain(){

//background
glBegin(GL_QUADS);
glColor3ub(163, 173, 172);
glVertex2f(1.0f,0.0f);
glVertex2f(1.0f,1.0f);
glVertex2f(-1.0f,1.0f);
glVertex2f(-1.0f,0.0f);
glEnd();
}
void BackgroundMorning(){

//background
glBegin(GL_QUADS);
glColor3ub(217, 219, 219);
glVertex2f(1.0f,0.0f);
glVertex2f(1.0f,1.0f);
glVertex2f(-1.0f,1.0f);
glVertex2f(-1.0f,0.0f);
glEnd();
}
void BackgroundNight(){

//background
glBegin(GL_QUADS);
glColor3ub(74, 74, 70);
glVertex2f(1.0f,0.0f);
glVertex2f(1.0f,1.0f);
glVertex2f(-1.0f,1.0f);
glVertex2f(-1.0f,0.0f);
glEnd();
}
void BackSide(){
glBegin(GL_QUADS);
glColor3ub(66, 71, 68);
glVertex2f(0.42f,0.0f);
glVertex2f(0.42f,0.45f);
glVertex2f(-0.5f,0.45f);
glVertex2f(-0.5f,0.0f);
glEnd();
}
void FootPath(){
glBegin(GL_QUADS);
glColor3ub(189, 189, 189);
glVertex2f(1.0f,0.0f);
glVertex2f(1.0f,0.06f);
glVertex2f(-1.0f,0.06f);
glVertex2f(-1.0f,0.0f);

glColor3ub(117, 27, 27);
glVertex2f(1.0f,0.03f);
glVertex2f(1.0f,0.045f);
glVertex2f(-1.0f,0.045f);
glVertex2f(-1.f,0.03f);

glColor3ub(201, 199, 12);
glVertex2f(1.0f,0.045f);
glVertex2f(1.0f,0.06f);
glVertex2f(-1.0f,0.06f);
glVertex2f(-1.f,0.045f);
glEnd();
}
void Grass(){
        glBegin(GL_QUADS);
        glColor3ub(64, 255, 0);
        glVertex2f(1.0,-0.57);
        glVertex2f(1.0,0.0);
        glVertex2f(-1.0,0.0);
        glVertex2f(-1.0,-.57);
        glEnd();
}
void Quad(){
glBegin(GL_QUADS);
glVertex2f(0.08f,0.0f);
glVertex2f(0.08f,0.1f);
glVertex2f(0.0f,0.1f);
glVertex2f(0.0f,0.0f);
glEnd();
}
void Road(){
//road
glBegin(GL_QUADS);
glColor3ub(97, 97, 97);
glVertex2f(1.0f,-1.f);
glVertex2f(1.0f,-0.5f);
glVertex2f(-1.0f,-0.5f);
glVertex2f(-1.0f,-1.f);

glEnd();
glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(-1.0f,-0.8f);
glVertex2f(-0.7f,-0.8f);
glVertex2f(-0.5f,-0.8f);
glVertex2f(-0.2f,-0.8f);
glVertex2f(0.1f,-0.8f);
glVertex2f(0.3f,-0.8f);
glVertex2f(0.5f,-0.8f);
glVertex2f(0.8f,-0.8f);
glVertex2f(1.0f,-0.8f);
glEnd();
}
void SecondFloor(){
glBegin(GL_QUADS);
glColor3ub(204, 204, 179);
glVertex2f(0.35f,0.0f);
glVertex2f(0.35f,0.1f);
glVertex2f(0.0f,0.1f);
glVertex2f(0.0f,0.0f);
glEnd();
}
void SecondFloorUpperDesign(){
glBegin(GL_QUADS);
glColor3ub(204, 204, 179);
glVertex2f(0.34f,0.0f);
glVertex2f(0.34f,0.08f);
glVertex2f(-0.02f,0.08f);
glVertex2f(-0.02f,0.0f);
glEnd();
}
void frontP1(){
//front p1
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(0.12,0.0);
    glVertex2f(.12,0.55);
    glVertex2f(0.0,0.55);
    glVertex2f(0.0,0.0);
    glEnd();
}
void LeftLastP(){

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(0.1,0.0);
    glVertex2f(.1,0.37);
    glVertex2f(0.0,0.4);
    glVertex2f(0.0,0.07);
    glEnd();
}
void LeftLastP_Basement(){

    glBegin(GL_QUADS);
    glColor3ub(161, 155, 116);
    glVertex2f(0.09,-0.08);
    glVertex2f(.09,0.0);
    glVertex2f(0.0,0.06);
    glVertex2f(0.0,-0.08);
    glEnd();
}
void FrontP2(){
  glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(0.11,0.065);
    glVertex2f(.11,0.45);
    glVertex2f(0.0,0.5);
    glVertex2f(0.0,0.0);
    glEnd();
    glColor3ub(230, 230, 230);
    circle(0.05,0.26,0.04);
}
void FrontP3(){
        glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(0.2,0.05);
    glVertex2f(0.2,0.435);
    glVertex2f(0.1,0.435);
    glVertex2f(0.1,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(230, 230, 230);
    glVertex2f(0.18f,0.23f);
    glVertex2f(0.15f,0.4f);
    glVertex2f(0.12f,0.23f);
    glEnd();

    glTranslatef(.119,.05,.0);
    glScalef(.8,.9,0);
    glColor3ub(230, 230, 230);
    Quad();

}
void FrontRightLastP(){
        glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(0.26,0.05);
    glVertex2f(0.26,0.45);
    glVertex2f(0.1,0.45);
    glVertex2f(0.1,0.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 230);
    glVertex2f(0.1f,0.45f);
    glVertex2f(0.1f,0.4f);
    glVertex2f(0.1f,0.35f);
    glVertex2f(0.1f,0.05f);
    glVertex2f(0.25f,0.05f);
    glVertex2f(0.2f,0.3f);
    glVertex2f(0.18f,0.35f);
    glVertex2f(0.18f,0.45f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(0.16f,0.45f);
    glVertex2f(0.16f,0.35f);
    glVertex2f(0.1f,0.26f);
    glVertex2f(0.1f,0.45f);

    glEnd();

}
void FrontLeftP2(){
  glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(-0.0,0.5);
    glVertex2f(-0.0,0.0);
    glVertex2f(-0.11,0.065);
    glVertex2f(-.11,0.45);
    glEnd();
    glColor3ub(230, 230, 230);
    circle(-0.05,0.26,0.04);
}
void RightUpperDesign(){
  glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(0.08,0.02);
    glVertex2f(0.08,0.15);
    glVertex2f(0.0,0.125);
    glVertex2f(0.0,0.05);
    //glEnd();
    glVertex2f(0.15,0.0);
    glVertex2f(0.15,0.16);
    glVertex2f(0.08,0.16);
    glVertex2f(0.08,0.0);

    glEnd();


    glColor3ub(230, 230, 230);
    circle(0.11,0.08,0.035);
}
void LefttUpperDesign(){
  glBegin(GL_QUADS);
    glColor3ub(204, 204, 179);
    glVertex2f(-0.08,0.02);
    glVertex2f(-0.08,0.155);
    glVertex2f(-0.0,0.14);
    glVertex2f(-0.0,0.05);
    //glEnd();
    glVertex2f(-0.15,0.02);
    glVertex2f(-0.15,0.165);
    glVertex2f(-0.08,0.165);
    glVertex2f(-0.08,0.02);

    glEnd();


    glColor3ub(230, 230, 230);
    circle(-0.11,0.08,0.035);
}
void RightBasement(){
    glBegin(GL_POLYGON);
    glColor3ub(161, 155, 116);
    glVertex2f(0.28f,0.0f);
    glVertex2f(0.42f,0.08f);
    glVertex2f(0.55f,0.08f);
    glVertex2f(0.73f,0.08f);
    glVertex2f(0.73f,0.0f);
    glVertex2f(0.55f,0.0f);
    glVertex2f(0.42f,0.0f);
    glVertex2f(0.32f,0.00f);
    glEnd();
  glBegin(GL_QUADS);
    glColor3ub(99, 33, 33);
    glVertex2f(0.28,0.0);
    glVertex2f(0.42,0.08);
    glVertex2f(0.44,0.079);
    glVertex2f(0.42,0.00);
    glEnd();

}
void LeftBasement(){
    glBegin(GL_POLYGON);
    glColor3ub(161, 155, 116);
    glVertex2f(-0.28f,0.0f);
    glVertex2f(-0.42f,0.08f);
    glVertex2f(-0.55f,0.08f);
    glVertex2f(-0.612f,0.08f);
    glVertex2f(-0.612f,0.0f);
    glVertex2f(-0.55f,0.0f);
    glVertex2f(-0.42f,0.0f);
    glVertex2f(-0.32f,0.00f);
    glEnd();
  glBegin(GL_QUADS);
    glColor3ub(99, 33, 33);
    glVertex2f(-0.28,0.0);
    glVertex2f(-0.42,0.08);
    glVertex2f(-0.44,0.079);
    glVertex2f(-0.42,0.00);
    glEnd();

}
void MainStair(){
    glBegin(GL_QUADS);
    glColor3ub(156, 148, 126);
    glVertex2f(0.02,0.0);
    glVertex2f(0.48,-0.2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.3,0.0);
    glEnd();
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(125, 26, 24);
    glVertex2f(0.45,-0.18);
    glVertex2f(-0.7,-0.18);
    glVertex2f(0.45,-0.15);
    glVertex2f(-0.7,-0.15);
    glVertex2f(0.45,-0.12);
    glVertex2f(-0.7,-0.12);
    glVertex2f(0.45,-0.09);
    glVertex2f(-0.7,-0.09);
    glVertex2f(0.45,-0.059);
    glVertex2f(-0.7,-0.059);
    glVertex2f(0.45,-0.025);
    glVertex2f(-0.7,-0.025);





    glEnd();


}
void RightSideOfStair(){
    glBegin(GL_TRIANGLES);
    glColor3ub(99, 33, 33);
     glVertex2f(0.47f,-0.2f);
    glVertex2f(0.47f,0.01f);
    glVertex2f(0.02f,0.01f);
    glEnd();
}
void LeftSideOfStair(){
    glBegin(GL_TRIANGLES);
    glColor3ub(99, 33, 33);
     glVertex2f(-0.42f,-0.2f);
    glVertex2f(-0.42f,0.0f);
    glVertex2f(-0.02f,0.0f);
    glEnd();
}
void Flag(){
glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(33, 33, 31);
glVertex2f(0.0f,-0.2f);
glVertex2f(0.0f,0.8f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(8, 56, 1);
glVertex2f(0.3f,0.55f);
glVertex2f(0.3f,0.78f);
glVertex2f(0.0f,0.78f);
glVertex2f(0.0f,0.55f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(33, 33, 31);
glVertex2f(0.05f,-0.2f);
glVertex2f(0.05f,-0.17f);
glVertex2f(-0.05f,-0.17f);
glVertex2f(-0.05f,-0.2f);
glEnd();
glColor3ub(161, 5, 5);
circle(0.17,0.66,0.08);

}
void Star(){
glPointSize(2);
glBegin(GL_POINTS);
glColor3ub(235, 239, 247);
glVertex2f(0.0,0.8);
glVertex2f(0.04,0.7);
glVertex2f(0.08,0.9);
glVertex2f(0.12,0.6);
glVertex2f(0.16,0.8);
glVertex2f(0.2,0.7);
glVertex2f(0.24,0.9);
glVertex2f(0.28,0.6);
glVertex2f(0.32,0.8);
glVertex2f(0.36,0.9);
glVertex2f(0.40,0.7);
glVertex2f(0.44,0.6);
//left
glVertex2f(-0.04,0.7);
glVertex2f(-0.08,0.9);
glVertex2f(-0.12,0.6);
glVertex2f(-0.16,0.8);
glVertex2f(-0.2,0.7);
glVertex2f(-0.24,0.9);
glVertex2f(-0.28,0.6);
glVertex2f(-0.32,0.8);
glVertex2f(-0.36,0.9);
glVertex2f(-0.40,0.7);
glVertex2f(-0.44,0.6);
glEnd();
}
void MakeStars(){
glTranslatef(-.7,0.0,0);
Star();
glLoadIdentity();
glTranslatef(-.8,0.0,0);
Star();
glLoadIdentity();
glTranslatef(.7,0.0,0);
Star();
glLoadIdentity();

}
void WalkWay(){

glBegin(GL_QUADS);
glColor3ub(97, 97, 97);
glVertex2f(.15f,0.0f);
glVertex2f(.15f,0.57f);
glVertex2f(-.15f,0.57f);
glVertex2f(-.15f,0.0f);

glEnd();
glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(0.0f,0.5f);
glVertex2f(0.0f,0.3f);
glVertex2f(0.0f,0.2f);
glVertex2f(0.0f,0.05f);
glEnd();
}
void BackgroundBuildingLeft(){

glBegin(GL_QUADS);
glColor3ub(127, 250, 244);
glVertex2f(-.6f,0.0f);
glVertex2f(-.6f,0.7f);
glVertex2f(-.9f,0.8f);
glVertex2f(-.9f,0.0f);
glEnd();
glBegin(GL_LINES);
glColor3ub(245, 245, 245);
glVertex2f(-.6f,0.15f);
glVertex2f(-.9f,0.15f);
glVertex2f(-.6f,0.25f);
glVertex2f(-.9f,0.25f);
glVertex2f(-.6f,0.35f);
glVertex2f(-.9f,0.35f);
glVertex2f(-.6f,0.45f);
glVertex2f(-.9f,0.45f);
glVertex2f(-.6f,0.55f);
glVertex2f(-.9f,0.55f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(192, 221, 250);
glVertex2f(-.35f,0.0f);
glVertex2f(-.35f,0.7f);
glVertex2f(-.59f,0.7f);
glVertex2f(-.59f,0.0f);
glEnd();
glBegin(GL_TRIANGLES);
glColor3ub(192, 221, 250);
glVertex2f(-.35f,0.7f);
glVertex2f(-.47f,0.85f);
glVertex2f(-.59f,0.7f);
glEnd();
glBegin(GL_LINES);
glColor3ub(245, 245, 245);
glVertex2f(-.35f,0.15f);
glVertex2f(-.59f,0.15f);
glVertex2f(-.35f,0.25f);
glVertex2f(-.59f,0.25f);
glVertex2f(-.35f,0.35f);
glVertex2f(-.59f,0.35f);
glVertex2f(-.35f,0.45f);
glVertex2f(-.59f,0.45f);
glVertex2f(-.35f,0.55f);
glVertex2f(-.59f,0.55f);
glVertex2f(-.35f,0.65f);
glVertex2f(-.59f,0.65f);

glEnd();
glBegin(GL_QUADS);
glColor3ub(252, 154, 154);
glVertex2f(-.1f,0.0f);
glVertex2f(-.1f,0.8f);
glVertex2f(-.34f,0.7f);
glVertex2f(-.34f,0.0f);
glEnd();
glBegin(GL_LINES);
glColor3ub(245, 245, 245);
glVertex2f(-.1f,0.15f);
glVertex2f(-.34f,0.15f);
glVertex2f(-.1f,0.25f);
glVertex2f(-.34f,0.25f);
glVertex2f(-.1f,0.35f);
glVertex2f(-.34f,0.35f);
glVertex2f(-.1f,0.45f);
glVertex2f(-.34f,0.45f);
glVertex2f(-.1f,0.55f);
glVertex2f(-.34f,0.55f);
glVertex2f(-.1f,0.65f);
glVertex2f(-.34f,0.65f);

glEnd();

}
void BackgroundBuildingRight(){

glBegin(GL_QUADS);
glColor3ub(125, 149, 245);
glVertex2f(-.6f,0.0f);
glVertex2f(-.6f,0.7f);
glVertex2f(-.9f,0.8f);
glVertex2f(-.9f,0.0f);
glEnd();
glBegin(GL_LINES);
glColor3ub(245, 245, 245);
glVertex2f(-.6f,0.15f);
glVertex2f(-.9f,0.15f);
glVertex2f(-.6f,0.25f);
glVertex2f(-.9f,0.25f);
glVertex2f(-.6f,0.35f);
glVertex2f(-.9f,0.35f);
glVertex2f(-.6f,0.45f);
glVertex2f(-.9f,0.45f);
glVertex2f(-.6f,0.55f);
glVertex2f(-.9f,0.55f);
glEnd();
glBegin(GL_QUADS);
glColor3ub(145, 54, 69);
glVertex2f(-.35f,0.0f);
glVertex2f(-.35f,0.7f);
glVertex2f(-.59f,0.7f);
glVertex2f(-.59f,0.0f);
glEnd();
glBegin(GL_TRIANGLES);
glColor3ub(145, 54, 69);
glVertex2f(-.35f,0.7f);
glVertex2f(-.47f,0.85f);
glVertex2f(-.59f,0.7f);
glEnd();
glBegin(GL_LINES);
glColor3ub(245, 245, 245);
glVertex2f(-.35f,0.15f);
glVertex2f(-.59f,0.15f);
glVertex2f(-.35f,0.25f);
glVertex2f(-.59f,0.25f);
glVertex2f(-.35f,0.35f);
glVertex2f(-.59f,0.35f);
glVertex2f(-.35f,0.45f);
glVertex2f(-.59f,0.45f);
glVertex2f(-.35f,0.55f);
glVertex2f(-.59f,0.55f);
glVertex2f(-.35f,0.65f);
glVertex2f(-.59f,0.65f);

glEnd();
glBegin(GL_QUADS);
glColor3ub(255, 222, 168);
glVertex2f(-.1f,0.0f);
glVertex2f(-.1f,0.8f);
glVertex2f(-.34f,0.8f);
glVertex2f(-.34f,0.0f);
glEnd();
glBegin(GL_LINES);
glColor3ub(245, 245, 245);
glVertex2f(-.1f,0.15f);
glVertex2f(-.34f,0.15f);
glVertex2f(-.1f,0.25f);
glVertex2f(-.34f,0.25f);
glVertex2f(-.1f,0.35f);
glVertex2f(-.34f,0.35f);
glVertex2f(-.1f,0.45f);
glVertex2f(-.34f,0.45f);
glVertex2f(-.1f,0.55f);
glVertex2f(-.34f,0.55f);
glVertex2f(-.1f,0.65f);
glVertex2f(-.34f,0.65f);

glEnd();


}

void MiniLamp() {
    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    //stand
    glVertex2d(0.05f, 0.45f);
    glVertex2d(0.0f, 0.45f);
    glVertex2d(0.0f, -0.4f);
    glVertex2d(0.05f, -0.4f);

    glEnd();

    glColor3ub(R, G, B); //yellow
    //glColor3ub(248,248,255); //off-white
    circle(0.022f, 0.6f, 0.09f);

    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    //stand
    glVertex2d(0.08f, 0.45f);
    glVertex2d(0.15f, 0.55f);
    glVertex2d(-0.1f, 0.55f);
    glVertex2d(-0.03f, 0.45f);

    glEnd();

}
void circleTree(){
glBegin(GL_QUADS);
glColor3ub(184, 134, 28);
glVertex2f(0.01f,0.0f);
glVertex2f(0.01f,0.4f);
glVertex2f(-0.01f,0.4f);
glVertex2f(-0.01f,0.0f);
glEnd();
glColor3ub(14, 115, 21);
circle(0.0,0.4,0.05);
glColor3ub(14, 115, 21);
circle(0.02,0.4,0.05);
glColor3ub(14, 115, 21);
circle(-0.02,0.4,0.05);
glColor3ub(14, 115, 21);
circle(0.0,0.46,0.05);

}

void Car(){
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);//yellow
        glColor3ub(241, 96, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
        glEnd();
/*
glBegin(GL_TRIANGLES);
        glColor3ub(R,G,B);
        glVertex2f(-1.04,-0.75);
        glVertex2f(-1.04,-0.89);
        glVertex2f(-0.89,-0.81);
        glEnd();
*/
	glColor3ub(0, 0, 0);
    circle(-0.84,-0.845,0.03);

	glColor3ub(0, 0, 0);
	circle(-0.71,-0.845,0.03);

}
//bus
void Bus(){
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.35,-0.675);
        glVertex2f(-0.38,-0.675);
        glVertex2f(-0.38,-0.775);
        glVertex2f(-0.35,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.39,-0.685);
        glVertex2f(-0.89,-0.685);
        glVertex2f(-0.89,-0.765);
        glVertex2f(-0.39,-0.765);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);

glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.37,-0.84);
        glVertex2f(-0.37,-0.8);
        glVertex2f(-0.35,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.885,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.78);
        glVertex2f(-0.885,-0.78);
glEnd();
/*
glBegin(GL_TRIANGLES);
        glColor3ub(R,G,B);
        glVertex2f(-0.15,-0.78);
        glVertex2f(-0.35,-0.82);
        glVertex2f(-0.15,-0.91);
        glEnd();
*/
	glColor3ub(0, 0, 0);
    circle(-.84,-.845,0.04);

	glColor3ub(0, 0, 0);
    circle(-.75,-.845,0.04);

	glColor3ub(0, 0, 0);
    circle(-.43,-.845,0.04);
}

void CarNight(){
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.64,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.79);
        glVertex2f(-0.65,-0.79);
glBegin(GL_QUADS);
        glColor3ub(151, 79, 68);
        glVertex2f(-0.73,-0.74);
        glVertex2f(-0.82,-0.74);
        glVertex2f(-0.85,-0.79);
        glVertex2f(-0.7,-0.79);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.735,-0.745);
        glVertex2f(-0.816,-0.745);
        glVertex2f(-0.84,-0.785);
        glVertex2f(-0.71,-0.785);
glBegin(GL_QUADS);//yellow
        glColor3ub(241, 96, 91);
        glVertex2f(-0.645,-0.82);
        glVertex2f(-0.67,-0.82);
        glVertex2f(-0.67,-0.8);
        glVertex2f(-0.647,-0.8);
glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.88,-0.82);
        glVertex2f(-0.9,-0.82);
        glVertex2f(-0.9,-0.8);
        glVertex2f(-0.88,-0.8);
        glEnd();

glBegin(GL_TRIANGLES);
        glColor3ub(R,G,B);
        glVertex2f(-1.04,-0.75);
        glVertex2f(-1.04,-0.89);
        glVertex2f(-0.89,-0.81);
        glEnd();
	glColor3ub(0, 0, 0);
    circle(-0.84,-0.845,0.03);

	glColor3ub(0, 0, 0);
	circle(-0.71,-0.845,0.03);

}
//bus
void BusNight(){
glBegin(GL_QUADS);
        glColor3ub(45, 149, 107);
        glVertex2f(-0.35,-0.86);
        glVertex2f(-0.9,-0.86);
        glVertex2f(-0.9,-0.67);
        glVertex2f(-0.35,-0.67);

glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.35,-0.675);
        glVertex2f(-0.38,-0.675);
        glVertex2f(-0.38,-0.775);
        glVertex2f(-0.35,-0.775);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.39,-0.685);
        glVertex2f(-0.89,-0.685);
        glVertex2f(-0.89,-0.765);
        glVertex2f(-0.39,-0.765);
glBegin(GL_QUADS);
        glColor3ub(200, 247, 254);
        glVertex2f(-0.36,-0.685);
        glVertex2f(-0.77,-0.685);
        glVertex2f(-0.77,-0.765);
        glVertex2f(-0.36,-0.765);

glBegin(GL_QUADS);
        glColor3ub(234, 241, 91);
        glVertex2f(-0.35,-0.84);
        glVertex2f(-0.37,-0.84);
        glVertex2f(-0.37,-0.8);
        glVertex2f(-0.35,-0.8);
glBegin(GL_QUADS);
        glColor3ub(241, 96, 91);
        glVertex2f(-0.885,-0.84);
        glVertex2f(-0.9,-0.84);
        glVertex2f(-0.9,-0.78);
        glVertex2f(-0.885,-0.78);
glEnd();

glBegin(GL_TRIANGLES);
        glColor3ub(R,G,B);
        glVertex2f(-0.15,-0.78);
        glVertex2f(-0.35,-0.82);
        glVertex2f(-0.15,-0.91);
        glEnd();

	glColor3ub(0, 0, 0);
    circle(-.84,-.845,0.04);

	glColor3ub(0, 0, 0);
    circle(-.75,-.845,0.04);

	glColor3ub(0, 0, 0);
    circle(-.43,-.845,0.04);
}
void ResizeCar(){
glScalef(3.,3.,0);
Car();
}
void ResizeCarNight(){
glScalef(3.,3.,0);
CarNight();
}

void Rain()
{
    glBegin(GL_LINES);
    glColor3ub(218, 223, 232);

    glVertex2f(0.0f, 1.9f);
    glVertex2f(0.05f, 2.0f);

    glVertex2f(0.1f, 1.9f);
    glVertex2f(0.15f, 2.0f);

    glVertex2f(0.2f, 1.9f);
    glVertex2f(0.25f, 2.0f);

    glVertex2f(0.3f, 1.9f);
    glVertex2f(0.35f, 2.0f);

    glVertex2f(0.4f, 1.9f);
    glVertex2f(0.45f, 2.0f);

    glVertex2f(0.5f, 1.9f);
    glVertex2f(0.55f, 2.0f);

    glVertex2f(0.6f, 1.9f);
    glVertex2f(0.65f, 2.0f);

    glVertex2f(0.7f, 1.9f);
    glVertex2f(0.75f, 2.0f);

    glVertex2f(0.8f, 1.9f);
    glVertex2f(0.85f, 2.0f);

    glVertex2f(0.9f, 1.9f);
    glVertex2f(0.95f, 2.0f);

    glVertex2f(1.0f, 1.9f);
    glVertex2f(1.05f, 2.0f);

    glVertex2f(1.1f, 1.9f);
    glVertex2f(1.15f, 2.0f);

    glVertex2f(1.2f, 1.9f);
    glVertex2f(1.25f, 2.0f);

    glVertex2f(1.3f, 1.9f);
    glVertex2f(1.35f, 2.0f);

    glVertex2f(1.4f, 1.9f);
    glVertex2f(1.45f, 2.0f);

    glVertex2f(1.5f, 1.9f);
    glVertex2f(1.55f, 2.0f);

    glVertex2f(1.6f, 1.9f);
    glVertex2f(1.65f, 2.0f);

    glVertex2f(1.7f, 1.9f);
    glVertex2f(1.75f, 2.0f);

    glVertex2f(1.8f, 1.9f);
    glVertex2f(1.85f, 2.0f);

    glVertex2f(1.9f, 1.9f);
    glVertex2f(1.95f, 2.0f);

    glVertex2f(2.0f, 1.9f);
    glVertex2f(2.05f, 2.0f);
    //
    glVertex2f(-0.1f, 1.9f);
    glVertex2f(-0.05f, 2.0f);

    glVertex2f(-0.2f, 1.9f);
    glVertex2f(-0.15f, 2.0f);

    glVertex2f(-0.3f, 1.9f);
    glVertex2f(-0.25f, 2.0f);

    glVertex2f(-0.4f, 1.9f);
    glVertex2f(-0.35f, 2.0f);

    glVertex2f(-0.5f, 1.9f);
    glVertex2f(-0.45f, 2.0f);

    glVertex2f(-0.6f, 1.9f);
    glVertex2f(-0.55f, 2.0f);

    glVertex2f(-0.7f, 1.9f);
    glVertex2f(-0.65f, 2.0f);

    glVertex2f(-0.8f, 1.9f);
    glVertex2f(-0.75f, 2.0f);

    glVertex2f(-0.9f, 1.9f);
    glVertex2f(-0.85f, 2.0f);

    glVertex2f(-1.0f, 1.9f);
    glVertex2f(-0.95f, 2.0f);

    glVertex2f(-1.1f, 1.9f);
    glVertex2f(-1.05f, 2.0f);

    glVertex2f(-1.2f, 1.9f);
    glVertex2f(-1.15f, 2.0f);

    glVertex2f(-1.3f, 1.9f);
    glVertex2f(-1.25f, 2.0f);

    glVertex2f(-1.4f, 1.9f);
    glVertex2f(-1.35f, 2.0f);

    glVertex2f(-1.5f, 1.9f);
    glVertex2f(-1.45f, 2.0f);

    glVertex2f(-1.6f, 1.9f);
    glVertex2f(-1.55f, 2.0f);

    glVertex2f(-1.7f, 1.9f);
    glVertex2f(-1.65f, 2.0f);

    glVertex2f(-1.8f, 1.9f);
    glVertex2f(-1.75f, 2.0f);

    glVertex2f(-1.9f, 1.9f);
    glVertex2f(-1.85f, 2.0f);

    glVertex2f(-2.0f, 1.9f);
    glVertex2f(-1.95f, 2.0f);
    glEnd();
}

void DisplayRain()
{
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
    glTranslatef(.0f, -.2f, 0);
    Rain();
}

void fillCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}

void plane()
{
   /* glTranslatef(.9f, 1.2f, 0);
    // wheel stand
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(.0f, -.83f);
    glVertex2f(.0f, -.7f);
    glVertex2f(.3f, -.83f);
    glVertex2f(.3f, -.7f);
    glEnd();
*/
    // body
    glBegin(GL_QUADS);
    glColor3ub(252, 255, 247);
    glVertex2f(.7f, -.65f);
    glVertex2f(.0f, -.6f);
    glVertex2f(-.3f, -.75f);
    glVertex2f(.5f, -.75f);


    // tail
    glVertex2f(.65f, -.65f);
    glVertex2f(.7f, -.55f);
    glVertex2f(.6f, -.55f);
    glVertex2f(.5f, -.65f);
    glEnd();

    // wheel
    //glColor3ub(0, 0, 0);
    //fillCircle(.0f, -.83f, .03f);
    //sfillCircle(.3f, -.83f, .03f);

    // window

    glColor3ub(pR,pG,pB);
    fillCircle(.01f, -.66f, .04f);
    fillCircle(.15f, -.67f, .03f);
    fillCircle(.25f, -.675f, .03f);
    fillCircle(.35f, -.68f, .03f);

    glBegin(GL_LINES);
    glColor3ub(252, 255, 247);
    glVertex2f(.6f, -.55f);
    glVertex2f(.5f, -.65f);
    glVertex2f(.65f, -.65f);
    glVertex2f(.7f, -.55f);
    glVertex2f(.7f, -.55f);
    glVertex2f(.6f, -.55f);
    glColor3ub(48, 44, 44);
    glVertex2f(.7f, -.65f);
    glVertex2f(.0f, -.6f);
    glVertex2f(.0f, -.6f);
    glVertex2f(-.3f, -.75f);
    glVertex2f(-.3f, -.75f);
    glVertex2f(.5f, -.75f);
    glVertex2f(.5f, -.75f);
    glVertex2f(.7f, -.65f);
    glEnd();

    glLoadIdentity();
}




void displayMorning() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(3,3,3,3);// Clear the color buffer (background)
    BackgroundMorning();
    glScalef(0.6,0.8,0);
    glTranslatef(-.8,.0,0);
    BackgroundBuildingLeft();
    glLoadIdentity();
    glScalef(0.6,0.8,0);
    glTranslatef(1.8,.0,0);
    BackgroundBuildingRight();
    glLoadIdentity();

    Road();
    Grass();
    glTranslatef(0.0,-0.58,0);
    FootPath();
    glLoadIdentity();
    //WalkWay
    glScalef(.72,.72,0);
    glTranslatef(-.05,-0.83,0);
    WalkWay();
    glLoadIdentity();

glTranslatef(-.12,0,0);
//sun();
glLoadIdentity();

glLoadIdentity();
glTranslatef(-.4,0,0);
cloud();
glLoadIdentity();
//glPushMatrix();
//glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.9,1.7,0);
cloud();
//glPopMatrix();
glLoadIdentity();

//glPushMatrix();
//glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.3,1.95,0);
cloud();
//glPopMatrix();
glLoadIdentity();

//glPushMatrix();
//glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-0.8,2.3,0);
cloud();
//glPopMatrix();
glLoadIdentity();
//Tree
glScalef(.4,.4,0);
glTranslatef(1.2,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.6,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.9,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.2,.0,0);
Tree_Trinagle();
glLoadIdentity();
//2nd Row

glScalef(.4,.4,0);
glTranslatef(1.6,-0.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.9,-0.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.1,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.4,-.7,0);
Tree_Trinagle();
glLoadIdentity();
//Left tree
glScalef(.4,.4,0);
glTranslatef(-1.9,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(-2.3,.0,0);
Tree_Trinagle();
glLoadIdentity();
//2nd Row
glScalef(.4,.4,0);
glTranslatef(-1.9,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(-2.3,-.7,0);
Tree_Trinagle();
glLoadIdentity();

//Bird
glPushMatrix();
glTranslatef(position1,0, 0.0f);
    glScalef(.3,.3,0);
glTranslatef(-1.0,2.4,0);
    Bird();
    glPopMatrix();
glLoadIdentity();
glTranslatef(position1,0, 0.0f);
    glScalef(.3,.3,0);
glTranslatef(-1.2,2.4,0);
    Bird();
    glPopMatrix();
glLoadIdentity();
glTranslatef(position1,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.3,2.5,0);
    Bird();
    glPopMatrix();

glPushMatrix();
       glTranslatef(position2,0.0,0.0f);
       //glScalef(.7,.7,0);
       glTranslatef(1.4,-2.2,.0);
       glColor3ub(115, 38, 38);
       ResizeCar();
       glLoadIdentity();

       glPushMatrix();
       glTranslatef(position3,0.0,0.0f);
       //glScalef(.25,.25,.0);
       glTranslatef(.0,-.09,.0);
       glColor3ub(0, 43, 128);
       Bus();
       glLoadIdentity();

       //glTranslatef(0,0,0);
       BackSide();
       //glLoadIdentity();


//building Start

    //secondFloorUpperDesign
    glTranslatef(-.2,.55,.0);
    SecondFloorUpperDesign();
    glLoadIdentity();
    //secondFloor
    glTranslatef(-.2,.4,.0);
    SecondFloor();
    glLoadIdentity();
    //RightUpperDesign
    glTranslatef(0.12,0.45,0);
    RightUpperDesign();
    glLoadIdentity();
    //LeftUpperDesign
    glTranslatef(-0.2,0.43,0);
    LefttUpperDesign();
    glLoadIdentity();
    //Left last P
    glTranslatef(-.6,.069,.0);
    LeftLastP();
    glLoadIdentity();
    ////Left last P Basement
    glTranslatef(-.6,0.08,.0);
    LeftLastP_Basement();
    glLoadIdentity();

      //right_last
      glScalef(1.0,.93,0);
     glTranslatef(.31,.027,.0);
     FrontRightLastP();
     glLoadIdentity();
    //Right P2
    glTranslatef(.122,.01,.0);
    FrontP2();
    glLoadIdentity();
    //Left P2
    glTranslatef(-.202,.01,.0);
    FrontLeftP2();
    glLoadIdentity();
    //Right p1
    frontP1();
    //Left P1
    glTranslatef(-.2,.0,.0);
    frontP1();
    glLoadIdentity();
    //Middle P1_resize
    glScalef(0.45,0.8,0);
    glTranslatef(-.15,.0,.0);
    frontP1();
    glLoadIdentity();
    //Right p#
    glTranslatef(.1301,.023,0);
    FrontP3();
    glLoadIdentity();
    //
    glTranslatef(.244,.023,0);
    FrontP3();
    glLoadIdentity();
    //left P3
    glTranslatef(-.50,.023,0);
    FrontP3();
    glLoadIdentity();
    glTranslatef(-.613,.023,0);
    FrontP3();
    glLoadIdentity();
    //Right basement
    glTranslatef(-0.16,0.01,0);
    RightBasement();
    glLoadIdentity();
    //Left Basement
    glTranslatef(0.095,0.0002,0);
    LeftBasement();
    glLoadIdentity();
    //MainStair
    glTranslatef(0.1,0.01,0);
    MainStair();
    glLoadIdentity();
    //right side of stair
    glTranslatef(0.1,0.001,0);
    RightSideOfStair();
    glLoadIdentity();
     //left side of stair
    glTranslatef(-0.18,0.01,0);
    LeftSideOfStair();
    glLoadIdentity();
    //Flag
    glScalef(0.3,0.3,0);
    glTranslatef(-.12,.0,.0);
    Flag();
    glLoadIdentity();



//Building Ends
//Mini lamp
    glScalef(.2,.2,0);
    glTranslatef(0.35,-.83,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-.83,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(0.35,-1.3,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-1.3,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(0.35,-1.73,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-1.73,0);
    MiniLamp();
    glLoadIdentity();


    glScalef(.2,.2,0);
    glTranslatef(0.35,-2.21,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-2.21,0);
    MiniLamp();
    glLoadIdentity();
    //Circle Tree
    glScalef(.6,.3,0);
    glTranslatef(-0.47,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(-0.67,-1.74,0);
        circleTree();
    glLoadIdentity();
     glScalef(.6,.3,0);
    glTranslatef(-0.87,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(-1.07,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.27,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.47,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.65,-1.74,0);
        circleTree();
    glLoadIdentity();
    //right side Circle Tree

    glScalef(.6,.3,0);
    glTranslatef(0.27,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(0.47,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(0.67,-1.74,0);
        circleTree();
    glLoadIdentity();
     glScalef(.6,.3,0);
    glTranslatef(0.87,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(1.07,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.27,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.47,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.65,-1.74,0);
        circleTree();
    glLoadIdentity();

	glFlush();  // Render now
}
void displayDay() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(3,3,3,3);// Clear the color buffer (background)

    BackgroundDay();
     glScalef(0.6,0.8,0);
    glTranslatef(-.8,.0,0);
    BackgroundBuildingLeft();
    glLoadIdentity();
    glScalef(0.6,0.8,0);
    glTranslatef(1.8,.0,0);
    BackgroundBuildingRight();
    glLoadIdentity();

    Road();
    Grass();
    glTranslatef(0.0,-0.58,0);
    FootPath();
    glLoadIdentity();
    //WalkWay
    glScalef(.72,.72,0);
    glTranslatef(-.05,-0.83,0);
    WalkWay();
    glLoadIdentity();
glPushMatrix();
glTranslatef(positionSun,0,0);
glTranslatef(-.12,0,0);
sun();
glPopMatrix();
glLoadIdentity();

glLoadIdentity();
glTranslatef(-.4,0,0);
cloud();
glLoadIdentity();
glPushMatrix();
glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.9,1.7,0);
cloud();
glPopMatrix();
glLoadIdentity();

glPushMatrix();
glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.3,1.95,0);
cloud();
glPopMatrix();
glLoadIdentity();

glPushMatrix();
glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-0.8,2.3,0);
cloud();
glPopMatrix();
glLoadIdentity();
//Tree
glScalef(.4,.4,0);
glTranslatef(1.2,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.6,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.9,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.2,.0,0);
Tree_Trinagle();
glLoadIdentity();
//2nd Row

glScalef(.4,.4,0);
glTranslatef(1.6,-0.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.9,-0.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.1,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.4,-.7,0);
Tree_Trinagle();
glLoadIdentity();
//Left tree
glScalef(.4,.4,0);
glTranslatef(-1.9,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(-2.3,.0,0);
Tree_Trinagle();
glLoadIdentity();
//2nd Row
glScalef(.4,.4,0);
glTranslatef(-1.9,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(-2.3,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glPushMatrix();
glTranslatef(position1,0, 0.0f);
    glScalef(.3,.3,0);
glTranslatef(-1.0,2.3,0);
    Bird();
    glPopMatrix();
glLoadIdentity();
glTranslatef(position1,0, 0.0f);
    glScalef(.3,.3,0);
glTranslatef(-1.2,2.3,0);
    Bird();
    glPopMatrix();
glLoadIdentity();
glTranslatef(position1,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.3,2.4,0);
    Bird();
    glPopMatrix();


glPushMatrix();
       glTranslatef(position2,0.0,0.0f);
       //glScalef(.7,.7,0);
       glTranslatef(1.4,-2.2,.0);
       glColor3ub(115, 38, 38);
       ResizeCar();
       glLoadIdentity();

       glPushMatrix();
       glTranslatef(position3,0.0,0.0f);
       //glScalef(.25,.25,.0);
       glTranslatef(.0,-.09,.0);
       glColor3ub(0, 43, 128);
       Bus();
       glLoadIdentity();

       //glTranslatef(0,0,0);
       BackSide();
       //glLoadIdentity();


//building Start

    //secondFloorUpperDesign
    glTranslatef(-.2,.55,.0);
    SecondFloorUpperDesign();
    glLoadIdentity();
    //secondFloor
    glTranslatef(-.2,.4,.0);
    SecondFloor();
    glLoadIdentity();
    //RightUpperDesign
    glTranslatef(0.12,0.45,0);
    RightUpperDesign();
    glLoadIdentity();
    //LeftUpperDesign
    glTranslatef(-0.2,0.43,0);
    LefttUpperDesign();
    glLoadIdentity();
    //Left last P
    glTranslatef(-.6,.069,.0);
    LeftLastP();
    glLoadIdentity();
    ////Left last P Basement
    glTranslatef(-.6,0.08,.0);
    LeftLastP_Basement();
    glLoadIdentity();

      //right_last
      glScalef(1.0,.93,0);
     glTranslatef(.31,.027,.0);
     FrontRightLastP();
     glLoadIdentity();
    //Right P2
    glTranslatef(.122,.01,.0);
    FrontP2();
    glLoadIdentity();
    //Left P2
    glTranslatef(-.202,.01,.0);
    FrontLeftP2();
    glLoadIdentity();
    //Right p1
    frontP1();
    //Left P1
    glTranslatef(-.2,.0,.0);
    frontP1();
    glLoadIdentity();
    //Middle P1_resize
    glScalef(0.45,0.8,0);
    glTranslatef(-.15,.0,.0);
    frontP1();
    glLoadIdentity();
    //Right p#
    glTranslatef(.1301,.023,0);
    FrontP3();
    glLoadIdentity();
    //
    glTranslatef(.244,.023,0);
    FrontP3();
    glLoadIdentity();
    //left P3
    glTranslatef(-.50,.023,0);
    FrontP3();
    glLoadIdentity();
    glTranslatef(-.613,.023,0);
    FrontP3();
    glLoadIdentity();
    //Right basement
    glTranslatef(-0.16,0.01,0);
    RightBasement();
    glLoadIdentity();
    //Left Basement
    glTranslatef(0.095,0.0002,0);
    LeftBasement();
    glLoadIdentity();
    //MainStair
    glTranslatef(0.1,0.01,0);
    MainStair();
    glLoadIdentity();
    //right side of stair
    glTranslatef(0.1,0.001,0);
    RightSideOfStair();
    glLoadIdentity();
     //left side of stair
    glTranslatef(-0.18,0.01,0);
    LeftSideOfStair();
    glLoadIdentity();
    //Flag
    glScalef(0.3,0.3,0);
    glTranslatef(-.12,.0,.0);
    Flag();
    glLoadIdentity();



//Building Ends

//Mini lamp
    glScalef(.2,.2,0);
    glTranslatef(0.35,-.83,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-.83,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(0.35,-1.3,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-1.3,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(0.35,-1.73,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-1.73,0);
    MiniLamp();
    glLoadIdentity();


    glScalef(.2,.2,0);
    glTranslatef(0.35,-2.21,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-2.21,0);
    MiniLamp();
    glLoadIdentity();
    //Circle Tree
    glScalef(.6,.3,0);
    glTranslatef(-0.47,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(-0.67,-1.74,0);
        circleTree();
    glLoadIdentity();
     glScalef(.6,.3,0);
    glTranslatef(-0.87,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(-1.07,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.27,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.47,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.65,-1.74,0);
        circleTree();
    glLoadIdentity();
    //right side Circle Tree

    glScalef(.6,.3,0);
    glTranslatef(0.27,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(0.47,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(0.67,-1.74,0);
        circleTree();
    glLoadIdentity();
     glScalef(.6,.3,0);
    glTranslatef(0.87,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(1.07,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.27,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.47,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.65,-1.74,0);
        circleTree();
    glLoadIdentity();

    ///plane animation
    glPushMatrix();
    glScalef(0.4f, 0.4f, 0.5f);
    glTranslatef(-.5+pPosition, 2.8f, 0);
    plane();
    glLoadIdentity();
    glPopMatrix();





	glFlush();  // Render now
}
void displayDayRain() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(3,3,3,3);// Clear the color buffer (background)

    BackgroundDayRain();
     glScalef(0.6,0.8,0);
    glTranslatef(-.8,.0,0);
    BackgroundBuildingLeft();
    glLoadIdentity();
    glScalef(0.6,0.8,0);
    glTranslatef(1.8,.0,0);
    BackgroundBuildingRight();
    glLoadIdentity();

    Road();
    Grass();
    glTranslatef(0.0,-0.58,0);
    FootPath();
    glLoadIdentity();
    //WalkWay
    glScalef(.72,.72,0);
    glTranslatef(-.05,-0.83,0);
    WalkWay();
    glLoadIdentity();
glPushMatrix();
glTranslatef(positionSun,0,0);
glTranslatef(-.12,0,0);
//sun();
glPopMatrix();
glLoadIdentity();

glLoadIdentity();
glTranslatef(-.4,0,0);
cloud();
glLoadIdentity();
glPushMatrix();
//glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.9,1.7,0);
cloud();
glPopMatrix();
glLoadIdentity();

glPushMatrix();
//glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-3.2,1.95,0);
cloud();
glPopMatrix();
glLoadIdentity();

glPushMatrix();
//glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(2.2,2.,0);
cloud();
glPopMatrix();
glLoadIdentity();
//Tree
glScalef(.4,.4,0);
glTranslatef(1.2,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.6,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.9,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.2,.0,0);
Tree_Trinagle();
glLoadIdentity();
//2nd Row

glScalef(.4,.4,0);
glTranslatef(1.6,-0.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.9,-0.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.1,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.4,-.7,0);
Tree_Trinagle();
glLoadIdentity();
//Left tree
glScalef(.4,.4,0);
glTranslatef(-1.9,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(-2.3,.0,0);
Tree_Trinagle();
glLoadIdentity();
//2nd Row
glScalef(.4,.4,0);
glTranslatef(-1.9,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(-2.3,-.7,0);
Tree_Trinagle();
glLoadIdentity();

glPushMatrix();
glTranslatef(position1,0, 0.0f);
    glScalef(.3,.3,0);
glTranslatef(-1.0,2.7,0);
    //Bird();
    glPopMatrix();
glLoadIdentity();
glTranslatef(position1,0, 0.0f);
    glScalef(.3,.3,0);
glTranslatef(-1.2,2.7,0);
    //Bird();
    glPopMatrix();
glLoadIdentity();
glTranslatef(position1,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.3,2.8,0);
    //Bird();
    glPopMatrix();


glPushMatrix();
       glTranslatef(position2,0.0,0.0f);
       //glScalef(.7,.7,0);
       glTranslatef(1.4,-2.3,.0);
       glColor3ub(115, 38, 38);
       ResizeCar();
       glLoadIdentity();

       glPushMatrix();
       glTranslatef(position3,0.0,0.0f);
       //glScalef(.25,.25,.0);
       glTranslatef(.0,-.09,.0);
       glColor3ub(0, 43, 128);
       Bus();
       glLoadIdentity();

       //glTranslatef(0,0,0);
       BackSide();
       //glLoadIdentity();


//building Start

    //secondFloorUpperDesign
    glTranslatef(-.2,.55,.0);
    SecondFloorUpperDesign();
    glLoadIdentity();
    //secondFloor
    glTranslatef(-.2,.4,.0);
    SecondFloor();
    glLoadIdentity();
    //RightUpperDesign
    glTranslatef(0.12,0.45,0);
    RightUpperDesign();
    glLoadIdentity();
    //LeftUpperDesign
    glTranslatef(-0.2,0.43,0);
    LefttUpperDesign();
    glLoadIdentity();
    //Left last P
    glTranslatef(-.6,.069,.0);
    LeftLastP();
    glLoadIdentity();
    ////Left last P Basement
    glTranslatef(-.6,0.08,.0);
    LeftLastP_Basement();
    glLoadIdentity();

      //right_last
      glScalef(1.0,.93,0);
     glTranslatef(.31,.027,.0);
     FrontRightLastP();
     glLoadIdentity();
    //Right P2
    glTranslatef(.122,.01,.0);
    FrontP2();
    glLoadIdentity();
    //Left P2
    glTranslatef(-.202,.01,.0);
    FrontLeftP2();
    glLoadIdentity();
    //Right p1
    frontP1();
    //Left P1
    glTranslatef(-.2,.0,.0);
    frontP1();
    glLoadIdentity();
    //Middle P1_resize
    glScalef(0.45,0.8,0);
    glTranslatef(-.15,.0,.0);
    frontP1();
    glLoadIdentity();
    //Right p#
    glTranslatef(.1301,.023,0);
    FrontP3();
    glLoadIdentity();
    //
    glTranslatef(.244,.023,0);
    FrontP3();
    glLoadIdentity();
    //left P3
    glTranslatef(-.50,.023,0);
    FrontP3();
    glLoadIdentity();
    glTranslatef(-.613,.023,0);
    FrontP3();
    glLoadIdentity();
    //Right basement
    glTranslatef(-0.16,0.01,0);
    RightBasement();
    glLoadIdentity();
    //Left Basement
    glTranslatef(0.095,0.0002,0);
    LeftBasement();
    glLoadIdentity();
    //MainStair
    glTranslatef(0.1,0.01,0);
    MainStair();
    glLoadIdentity();
    //right side of stair
    glTranslatef(0.1,0.001,0);
    RightSideOfStair();
    glLoadIdentity();
     //left side of stair
    glTranslatef(-0.18,0.01,0);
    LeftSideOfStair();
    glLoadIdentity();
    //Flag
    glScalef(0.3,0.3,0);
    glTranslatef(-.12,.0,.0);
    Flag();
    glLoadIdentity();



//Building Ends

//Mini lamp
    glScalef(.2,.2,0);
    glTranslatef(0.35,-.83,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-.83,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(0.35,-1.3,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-1.3,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(0.35,-1.73,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-1.73,0);
    MiniLamp();
    glLoadIdentity();


    glScalef(.2,.2,0);
    glTranslatef(0.35,-2.21,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-2.21,0);
    MiniLamp();
    glLoadIdentity();
    //Circle Tree
    glScalef(.6,.3,0);
    glTranslatef(-0.47,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(-0.67,-1.74,0);
        circleTree();
    glLoadIdentity();
     glScalef(.6,.3,0);
    glTranslatef(-0.87,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(-1.07,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.27,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.47,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.65,-1.74,0);
        circleTree();
    glLoadIdentity();
    //right side Circle Tree

    glScalef(.6,.3,0);
    glTranslatef(0.27,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(0.47,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(0.67,-1.74,0);
        circleTree();
    glLoadIdentity();
     glScalef(.6,.3,0);
    glTranslatef(0.87,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(1.07,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.27,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.47,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.65,-1.74,0);
        circleTree();
    glLoadIdentity();
    ///Rain

    glPushMatrix();
    glTranslatef(rPosition, rPosition, 0.0f);
    DisplayRain();
    glPopMatrix();




	glFlush();  // Render now
}
void displayNight() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(3,3,3,3);// Clear the color buffer (background)

    BackgroundNight();


    Star();
    glTranslatef(0.9,0.87,0);
    MakeStars();
    glLoadIdentity();
    glTranslatef(1.5,0.73,0);
    MakeStars();
    glLoadIdentity();
    glTranslatef(0.0,0.8,0);
    MakeStars();
    glLoadIdentity();
    glTranslatef(-0.4,0.73,0);
    MakeStars();
    glLoadIdentity();

     glScalef(0.6,0.8,0);
    glTranslatef(-.8,.0,0);
    BackgroundBuildingLeft();
    glLoadIdentity();
    glScalef(0.6,0.8,0);
    glTranslatef(1.8,.0,0);
    BackgroundBuildingRight();
    glLoadIdentity();
    Road();
    Grass();
    glTranslatef(0.0,-0.58,0);
    FootPath();
    glLoadIdentity();
    //WalkWay
    glScalef(.72,.72,0);
    glTranslatef(-.05,-0.83,0);
    WalkWay();
    glLoadIdentity();

glTranslatef(-.4,0,0);
Moon();
glLoadIdentity();


glTranslatef(-.4,0,0);
cloud();
glLoadIdentity();

glPushMatrix();
glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.9,1.7,0);
cloud();
glPopMatrix();
glLoadIdentity();

glPushMatrix();
glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.3,1.95,0);
cloud();
glPopMatrix();
glLoadIdentity();

glPushMatrix();
glTranslatef(positionColud,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-0.8,2.3,0);
cloud();
glPopMatrix();
glLoadIdentity();

//Tree
glScalef(.4,.4,0);
glTranslatef(1.2,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.6,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.9,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.2,.0,0);
Tree_Trinagle();
glLoadIdentity();
//2nd Row

glScalef(.4,.4,0);
glTranslatef(1.6,-0.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(1.9,-0.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.1,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(2.4,-.7,0);
Tree_Trinagle();
glLoadIdentity();
//Left tree
glScalef(.4,.4,0);
glTranslatef(-1.9,.0,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(-2.3,.0,0);
Tree_Trinagle();
glLoadIdentity();
//2nd Row
glScalef(.4,.4,0);
glTranslatef(-1.9,-.7,0);
Tree_Trinagle();
glLoadIdentity();
glScalef(.4,.4,0);
glTranslatef(-2.3,-.7,0);
Tree_Trinagle();
glLoadIdentity();

glPushMatrix();
glTranslatef(position1,0, 0.0f);
    glScalef(.3,.3,0);
glTranslatef(-1.0,2.7,0);

    //Bird();
    glPopMatrix();
glLoadIdentity();
glTranslatef(position1,0, 0.0f);
    glScalef(.3,.3,0);
glTranslatef(-1.2,2.7,0);
    //Bird();
    glPopMatrix();
glLoadIdentity();
glTranslatef(position1,0, 0.0f);
glScalef(.3,.3,0);
glTranslatef(-1.3,2.8,0);
    //Bird();
    glPopMatrix();



glPushMatrix();
       glTranslatef(position2,0.0,0.0f);
       //glScalef(.7,.7,0);
       glTranslatef(1.4,-2.3,.0);
       glColor3ub(115, 38, 38);
       ResizeCarNight();
       glLoadIdentity();

       glPushMatrix();
       glTranslatef(position3,0.0,0.0f);
       //glScalef(.25,.25,.0);
       glTranslatef(.0,-.09,.0);
       glColor3ub(0, 43, 128);
       BusNight();
       glLoadIdentity();

       //glTranslatef(0,0,0);
       BackSide();
       //glLoadIdentity();


//building Start

    //secondFloorUpperDesign
    glTranslatef(-.2,.55,.0);
    SecondFloorUpperDesign();
    glLoadIdentity();
    //secondFloor
    glTranslatef(-.2,.4,.0);
    SecondFloor();
    glLoadIdentity();
    //RightUpperDesign
    glTranslatef(0.12,0.45,0);
    RightUpperDesign();
    glLoadIdentity();
    //LeftUpperDesign
    glTranslatef(-0.2,0.43,0);
    LefttUpperDesign();
    glLoadIdentity();
    //Left last P
    glTranslatef(-.6,.069,.0);
    LeftLastP();
    glLoadIdentity();
    ////Left last P Basement
    glTranslatef(-.6,0.08,.0);
    LeftLastP_Basement();
    glLoadIdentity();

      //right_last
      glScalef(1.0,.93,0);
     glTranslatef(.31,.027,.0);
     FrontRightLastP();
     glLoadIdentity();
    //Right P2
    glTranslatef(.122,.01,.0);
    FrontP2();
    glLoadIdentity();
    //Left P2
    glTranslatef(-.202,.01,.0);
    FrontLeftP2();
    glLoadIdentity();
    //Right p1
    frontP1();
    //Left P1
    glTranslatef(-.2,.0,.0);
    frontP1();
    glLoadIdentity();
    //Middle P1_resize
    glScalef(0.45,0.8,0);
    glTranslatef(-.15,.0,.0);
    frontP1();
    glLoadIdentity();
    //Right p#
    glTranslatef(.1301,.023,0);
    FrontP3();
    glLoadIdentity();
    //
    glTranslatef(.244,.023,0);
    FrontP3();
    glLoadIdentity();
    //left P3
    glTranslatef(-.50,.023,0);
    FrontP3();
    glLoadIdentity();
    glTranslatef(-.613,.023,0);
    FrontP3();
    glLoadIdentity();
    //Right basement
    glTranslatef(-0.16,0.01,0);
    RightBasement();
    glLoadIdentity();
    //Left Basement
    glTranslatef(0.095,0.0002,0);
    LeftBasement();
    glLoadIdentity();
    //MainStair
    glTranslatef(0.1,0.01,0);
    MainStair();
    glLoadIdentity();
    //right side of stair
    glTranslatef(0.1,0.001,0);
    RightSideOfStair();
    glLoadIdentity();
     //left side of stair
    glTranslatef(-0.18,0.01,0);
    LeftSideOfStair();
    glLoadIdentity();
    //Flag
    glScalef(0.3,0.3,0);
    glTranslatef(-.12,.0,.0);
    Flag();
    glLoadIdentity();



//Building Ends
//Mini lamp
    glScalef(.2,.2,0);
    glTranslatef(0.35,-.83,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-.83,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(0.35,-1.3,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-1.3,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(0.35,-1.73,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-1.73,0);
    MiniLamp();
    glLoadIdentity();


    glScalef(.2,.2,0);
    glTranslatef(0.35,-2.21,0);
    MiniLamp();
    glLoadIdentity();

    glScalef(.2,.2,0);
    glTranslatef(-0.77,-2.21,0);
    MiniLamp();
    glLoadIdentity();
    //Circle Tree
    glScalef(.6,.3,0);
    glTranslatef(-0.47,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(-0.67,-1.74,0);
        circleTree();
    glLoadIdentity();
     glScalef(.6,.3,0);
    glTranslatef(-0.87,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(-1.07,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.27,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.47,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(-1.65,-1.74,0);
        circleTree();
    glLoadIdentity();
    //right side Circle Tree

    glScalef(.6,.3,0);
    glTranslatef(0.27,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(0.47,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(0.67,-1.74,0);
        circleTree();
    glLoadIdentity();
     glScalef(.6,.3,0);
    glTranslatef(0.87,-1.74,0);
        circleTree();
    glLoadIdentity();
    glScalef(.6,.3,0);
    glTranslatef(1.07,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.27,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.47,-1.74,0);
        circleTree();
    glLoadIdentity();

        glScalef(.6,.3,0);
    glTranslatef(1.65,-1.74,0);
        circleTree();
    glLoadIdentity();


    ///plane animation
    glPushMatrix();
    glScalef(0.4f, 0.4f, 0.5f);
    glTranslatef(-.5+pPosition, 2.5f, 0);
    plane();
    glLoadIdentity();
    glPopMatrix();


	glFlush();  // Render now
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'd':
    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
    glutDisplayFunc(displayDay);
    soundBird();
    soundPlane();
    //soundCar();
    //soundHorn();
    //speed += 0.01f;
    glutPostRedisplay();
    break;
case 'n':
    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
    glutDisplayFunc(displayNight);
    soundNight();

    //speed2 -= 0.01f;
    glutPostRedisplay();
    break;
    case 'm':
    glutDisplayFunc(displayMorning);
    //soundPlane();
    soundBird();
    //soundCar();

    //soundHorn();
    glutPostRedisplay();
    break;

    case 'r':
    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
    glutDisplayFunc(displayDayRain);
    soundRain();
    glutPostRedisplay();
    break;
    case 'l':
        R = 255;
        G = 255;
        B = 102;

        pR = 255;
        pG = 255;
        pB = 102;
        glutPostRedisplay();
        break;
    case 'f':
        R = 248;
        G= 248;
        B = 255;
        glutPostRedisplay();
        break;
        case 'h':
            soundHorn();
        glutPostRedisplay();
        break;

        case 'c':
        soundCar();
        glutPostRedisplay();
        break;


	}
}
void SpecialInput(int key, int x, int y)
{
switch(key)
{case GLUT_KEY_UP:
speedCbrown=0.2;
speedCblue=0.04;

break;
case GLUT_KEY_DOWN:
speedCbrown=0.0;
speedCblue=0.0;
break;
case GLUT_KEY_LEFT:
speedCbrown-=0.01;
speedCblue-=0.01;
break;
case GLUT_KEY_RIGHT:
speedCbrown+=0.01;
speedCblue+=0.01;
break;}
glutPostRedisplay();
}
void Dis(){
glutDisplayFunc(displayMorning);
soundBird();

}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("Parliament of Bangladesh"); // Create a window with the given title
	glutInitWindowSize(640, 640);   // Set the window's initial width & height
	glutDisplayFunc(Dis);// Register display callback handler for window re-paint
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);
    glutTimerFunc(100, updateCloud, 0);
    glutTimerFunc(100,updateSun,0);
	glutIdleFunc(Idle);
	glutMainLoop();
	          // Enter the event-processing loop
	return 0;
}
