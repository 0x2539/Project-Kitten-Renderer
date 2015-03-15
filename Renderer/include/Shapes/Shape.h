#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
    public:
        virtual void draw() = 0;
        GLuint texture;
        void setTexture( GLuint newTexture );
        void setColor( GLfloat r, GLfloat g, GLfloat b, GLfloat a );
};

void Shape::setTexture(GLuint newTexture){
    texture = newTexture;
}

#endif // SHAPE_H
