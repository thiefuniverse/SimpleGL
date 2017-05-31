//
//  SimpleGLPaint.hpp
//  SimpleGL
//
//  Created by 谢非 on 2017/5/31.
//  Copyright © 2017年 谢非. All rights reserved.
//

#ifndef SimpleGLPainter_hpp
#define SimpleGLPainter_hpp

#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace SimpleGLPaint {
    
    // init environment and terminate environment
    static void initSimpleGL();
    static void byeSimpleGL();
    
    
    void initSimpleGL(){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }
    void byeSimpleGL(){
        glfwTerminate();
    }
    
    class SimpleGLPainter{
      public:
        // SimpleGLPainter();
        bool createWindow(unsigned int width,unsigned int height,std::string title);
        void drawLine(int x1,int y1,int x2, int y2);
        void showWindow();
        ~SimpleGLPainter();
        private:
        GLFWwindow *window;
        
    };

    bool SimpleGLPainter::createWindow(unsigned int width, unsigned int height, std::string title){
        window=glfwCreateWindow(width,height,title.c_str(),nullptr,nullptr);
        return window!=nullptr;
    }
    
    void SimpleGLPainter::drawLine( GLint x1, GLint y1, GLint x2,  GLint y2){
        
        int screenWidth,screenHeight;
        glfwGetFramebufferSize(window,&screenWidth,&screenHeight);
         glViewport(0, 0, screenWidth, screenHeight);
        glewInit();
        
        glfwMakeContextCurrent(window);
        glewExperimental=GL_TRUE;
        
       
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_POINTS);
        GLint dx=x2-x1,dy=y2-y1;
        GLint ux=((dx> 0) << 1) -1,uy=((dy>0)<<1)-1;
        
        GLint x=x1,y=y1,eps;
        
        eps=0;
        dx=abs(dx);
        dy=abs(dy);
        
        if(dx>dy){
            for (x=x1; x!=x2; x+=ux) {
                glVertex2i(x, y);
                eps+=dy;
                if((eps<<1)>=dx){
                    y+=uy;
                    eps-=dx;
                }
            }
        }else{
            for (y=y1; y!=y2; y+=uy) {
                glVertex2i(x, y);
                eps+=dx;
                if((eps<<1)>=dy){
                    x+=ux;
                    eps-=dy;
                }
            }
        }
        
        glEnd();
    }
    
    void SimpleGLPainter::showWindow()
    {
        while(!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
            // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
        }
        byeSimpleGL();

    }
    SimpleGLPainter::~SimpleGLPainter(){
        glfwDestroyWindow(window);
    }

}

#endif /* SimpleGLPainter_hpp */
