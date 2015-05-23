/**
    Shape.h
    Purpose: Implements a basic shape. In order
    to create a shape you need to create another
    class which inherits this one and implement
    your drawing method there.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef SHAPE_H
#define SHAPE_H

#include "ColorRGBA.h"

class Shape
{
    public:

        //The texture
        GLuint texture;
        ColorRGBA color;

	    /**
	        Renders the shape on the screen.

	        @param
	        @return
	    */
        virtual void draw() = 0;

	    /**
	        Set the texture that will be bound to the
	        shape.

	        @param newTexture the texture to bound to
	        the shape
	        @return
	    */
        void setTexture( GLuint newTexture );

	    /**
	        Set the color that will be bound to the
	        shape. All these values must take a value
	        between 0 and 1.

	        @param red the red color
	        @param green the green color
	        @param blue the blue color
	        @param alpha the alpha color
	        @return
	    */
        void setColor( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha );

	    /**
	        Set the color that will be bound to the
	        shape.

	        @param newColor the color from which
	        to take the red, green, blue and alpha
	        levels
	        @return
	    */
        void setColor( ColorRGBA newColor );
};

void Shape::setTexture(GLuint newTexture){
    texture = newTexture;
}

void Shape::setColor( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha ){
	color.setColor(red, green, blue, alpha);
}

void Shape::setColor( ColorRGBA newColor ){
	color.setColor(newColor);

}

#endif // SHAPE_H
