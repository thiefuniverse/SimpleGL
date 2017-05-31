//
//  SimpleGLPaint.hpp
//  SimpleGL
//
//  Created by 谢非 on 2017/5/31.
//  Copyright © 2017年 谢非. All rights reserved.
//

#ifndef SimpleGLPaint_hpp
#define SimpleGLPaint_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace SimpleGLPaint {
    class SimpleGLHelper{
    private:
    public:
        SimpleGLHelper();
        static void initSimpleGL();
        
    };
}

#endif /* SimpleGLPaint_hpp */
