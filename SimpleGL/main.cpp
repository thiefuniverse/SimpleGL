//
//  main.cpp
//  testOpengl
//
//  Created by 谢非 on 2017/5/30.
//  Copyright © 2017年 谢非. All rights reserved.
//

#include <iostream>
#include "SimpleGLPaint.hpp"

const GLint WIDTH=800,HEIGHT=600;

int main(int argc, const char * argv[]) {
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
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
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    
    return 0;
}
