#ifndef COLORRGBA_H_INCLUDED
#define COLORRGBA_H_INCLUDED

class ColorRGBA
{
private:
	GLfloat _red, _green, _blue, _alpha;
public:
	ColorRGBA(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

	void setColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

	void setRed(GLfloat red);
	GLfloat getRed();
	
	void setGreen(GLfloat green);
	GLfloat getGreen();
	
	void setBlue(GLfloat blue);
	GLfloat getBlue();
	
	void setAlpha(GLfloat alpha);
	GLfloat getAlpha();
};

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