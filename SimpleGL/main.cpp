//
//  main.cpp
//  testOpengl
//
//  Created by 谢非 on 2017/5/30.
//  Copyright © 2017年 谢非. All rights reserved.
//

#include <iostream>
#include "SimpleGLPainter.hpp"

using namespace SimpleGLPaint;

const GLint WIDTH=800,HEIGHT=600;
    GLuint VBO;
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint VAO;
    GLuint shaderProgram;
void showTriangle(){
    GLfloat vertices[]={
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f,
        0.4f,0.2f,0.5f,
        0,1,1,
        0.05,1,1,
        0.1,1,1,
        0.15,1,1,
        0.2,1,1,
        0.25,1,1,
        0.3,1,1,
        0.35,1,1,
        0.4,1,1,
        0.45,1,1,
        0.5,1,1,
        0.55,1,1,
        0.6,1,1,
        0.65,1,1,
        0.7,1,1,
        0.75,1,1,
        0.8,1,1,
        0.85,1,1,
        0.9,1,1,
        0.95,1,1
    };
    

    glGenBuffers(1,&VBO);
    
    char* shaderSrc="#version 330 core\
    layout (location = 0) in vec3 position;\
    void main()\
    {\
        gl_Position = vec4(position.x, position.y, position.z, 1.0);\
    }";
    
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&shaderSrc,NULL);
    glCompileShader(vertexShader);
    
    char* shaderSrc2="#version 330 core\
    out vec4 color;\
    void main()\
    {\
        color = vec4(1.0f, 0.8f, 0.2f, 1.0f);\
    }";
    

    fragmentShader= glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&shaderSrc2,nullptr);
    glCompileShader(fragmentShader);
    

    shaderProgram=glCreateProgram();
    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    
    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    

    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
    
}
int main(int argc, char ** argv) {
    SimpleGLPaint::initSimpleGL();
    SimpleGLPainter painter;
   // painter.createWindow(600, 800, "thief");
   // painter.drawLine(0, 0, 40, 40);
   // painter.showWindow();
    glfwInit();
 GLFWwindow *window=glfwCreateWindow(WIDTH,HEIGHT,"learn Opengl",nullptr,nullptr);
    
    int screenWidth,screenHeight;
    glfwGetFramebufferSize(window,&screenWidth,&screenHeight);
    
    if(nullptr == window)
    {
        std::cout<<"Failed to create GLFW window"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental=GL_TRUE;
    
    if(GLEW_OK!=glewInit())
    {
        std::cout<<"Failed to initalize GLFW"<<std::endl;
        return -1;
    }
    glViewport(0, 0, screenWidth, screenHeight);
    
    showTriangle();
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
      // glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, 15);
        glEnable(GL_PROGRAM_POINT_SIZE);
        glPointSize(30);
        glBindVertexArray(0);
        glfwSwapBuffers(window);
    }
    
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    
    glfwTerminate();
  //  SimpleGLPaint::byeSimpleGL();
    return 0;
}
