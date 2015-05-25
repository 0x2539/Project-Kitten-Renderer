/**
    ColorRGBA.h
    Purpose: Implements a basic color manager.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef COLORRGBA_H_INCLUDED
#define COLORRGBA_H_INCLUDED

class ColorRGBA
{
private:
	//The red color
	GLfloat _red;
	//The green color
	GLfloat _green;
	//The blue color
	GLfloat _blue;
	//The alpha color
	GLfloat _alpha;
public:

    /**
        Initialise a new instance of this class with default color values.
        @return
    */
    ColorRGBA();

    /**
        Initialise a new instance of this class.

        @param red the red color
        @param green the green color
        @param blue the blue color
        @param alpha the alpha color
        @return
    */
	ColorRGBA(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

    /**
        Set the color.

        @param red the red color
        @param green the green color
        @param blue the blue color
        @param alpha the alpha color
        @return
    */
	void setColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

    /**
        Set the color.

        @param newColor the color from which
        to get the new color values
        @return
    */
	void setColor(ColorRGBA newColor);

    /**
        Set the red color.

        @param red the red color
        @return
    */
	void setRed(GLfloat red);

    /**
        Get the red color.

        @param
        @return the red color
    */
	GLfloat getRed();
	
    /**
        Set the green color.

        @param green the green color
        @return
    */
	void setGreen(GLfloat green);

    /**
        Get the green color.

        @param
        @return the green color
    */
	GLfloat getGreen();
	
    /**
        Set the blue color.

        @param blue the blue color
        @return
    */
	void setBlue(GLfloat blue);

    /**
        Get the blue color.

        @param
        @return the blue color
    */
	GLfloat getBlue();
	
    /**
        Set the alpha color.

        @param alpha the alpha color
        @return
    */
	void setAlpha(GLfloat alpha);

    /**
        Get the alpha color.

        @param
        @return the alpha color
    */
	GLfloat getAlpha();
};

ColorRGBA::ColorRGBA()
{
    setColor(1.0f, 1.0f, 1.0f, 0.0f);
}


ColorRGBA::ColorRGBA(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	setColor(red, green, blue, alpha);
}

void ColorRGBA::setColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	setRed(red);
	setGreen(green);
	setBlue(blue);
	setAlpha(alpha);
}

void ColorRGBA::setColor(ColorRGBA newColor)
{
	setColor(newColor.getRed(), newColor.getGreen(), newColor.getBlue(), newColor.getAlpha());
}

void ColorRGBA::setRed(GLfloat red)
{
	_red = red;
}

GLfloat ColorRGBA::getRed()
{
	return _red;
}

void ColorRGBA::setGreen(GLfloat green)
{
	_green = green;
}

GLfloat ColorRGBA::getGreen()
{
	return _green;
}

void ColorRGBA::setBlue(GLfloat blue)
{
	_blue = blue;
}

GLfloat ColorRGBA::getBlue()
{
	return _blue;
}

void ColorRGBA::setAlpha(GLfloat alpha)
{
	_alpha = alpha;
}

GLfloat ColorRGBA::getAlpha()
{
	return _alpha;
}

#endif // COLORRGBA_H_INCLUDED