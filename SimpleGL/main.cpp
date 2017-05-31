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

int main(int argc, const char * argv[]) {
    SimpleGLPaint::initSimpleGL();
    SimpleGLPainter painter;
    painter.createWindow(600, 800, "thief");
    painter.drawLine(0, 0, 40, 40);
    painter.showWindow();
//    GLFWwindow *window=glfwCreateWindow(WIDTH,HEIGHT,"learn Opengl",nullptr,nullptr);
//    
//    int screenWidth,screenHeight;
//    glfwGetFramebufferSize(window,&screenWidth,&screenHeight);
//    
//    if(nullptr == window)
//    {
//        std::cout<<"Failed to create GLFW window"<<std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glewExperimental=GL_TRUE;
//    
//    if(GLEW_OK!=glewInit())
//    {
//        std::cout<<"Failed to initalize GLFW"<<std::endl;
//        return -1;
//    }
//
//    
//    glViewport(0, 0, screenWidth, screenHeight);
//    while(!glfwWindowShouldClose(window))
//    {
//        glfwPollEvents();
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        glfwSwapBuffers(window);
//    }
   
    SimpleGLPaint::byeSimpleGL();
    return 0;
}
