# ComputerGraphics
Repository to store Lab Works of Computer Graphics subject.

## List of labs
1. Simple 2D editor, that provides drawing simple shapes with chosen colors. This project is created
using Qt framework. This lab must have realization of logical color mixing, but I have not found analog of LogicalOP
functions in 3.3+ version of OpenGL. As I understood, in 3.3+ all color operations provided by shaders and written in 
Shader language (may be in external files or added as string in main OpenGL code).
So this part of task is not done.
2. This is also a third lab. So, meet Snoop Dogg! This is very simple object. About project:
- uses six shader programs
- has class SnoopDogg, where generates vertices of body, head and face with colors, texture coordinates
- has class Shader that helps read shader programs from files and use it in program
- uses callback for actions on different buttons: ESC - to close, SPACE - to stop or to start rotation, UP or DOWN - 
to increase or decrease rotation speed, A - generates random axis for rotating.

##Installation
1. GLFW and GLEW install from <link href="https://learnopengl.com/#!Getting-started/Creating-a-window">this</link>
tutorial. Thus used for accessing OpenGL 3.3+ version functions.
2. SOIL install from <link href="https://learnopengl.com/#!Getting-started/Textures">here</link>, SOIL header of the
article. This used for getting array of bytes of image for texture.
3. GLM install from <link href="https://learnopengl.com/#!Getting-started/Transformations">here</link>, GLM header of
the article. This used for math operations with vectors and matrices of scaling, rotation and transformation.

All this libraries and headers must be linked to project and generated on your PC (except static libs) for stable work.
There can be some bugs and bad optimized algorithms, so if You somehow found this project, please help and contribute.
I'll be pleased for any help. 

Better documentation and better comments may be added later (that's not sure, I'm lazy).