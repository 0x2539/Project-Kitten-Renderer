#ifndef GLTEXTUREDVERTEX_H
#define GLTEXTUREDVERTEX_H

class GLVertexCoord
{
  private:
    float _x,_y;

  public:
    GLVertexCoord();
    GLVertexCoord(GLfloat x, GLfloat y);
    
    void setLocation(GLfloat x, GLfloat y);
    void setLocation(GLVertexCoord p);

    void setX(GLfloat x);
    GLfloat getX();
    
    void setY(GLfloat y);
    GLfloat getY();
};

class GLTexCoord
{
private:
    GLfloat _s;
    GLfloat _t;
public:
    GLTexCoord();
    GLTexCoord(GLfloat s, GLfloat t);

    void setLocation(GLfloat s, GLfloat t);
    void setLocation(GLTexCoord p);

    void setS(GLfloat s);
    GLfloat getS();

    void setT(GLfloat t);
    GLfloat getT();
};

class GLTexturedVertex
{
private:
public:
    GLVertexCoord _vertexCoord;
    GLTexCoord _textureCoord;
    
    GLTexturedVertex();
    GLTexturedVertex(GLVertexCoord vertexCoord, GLTexCoord textureCoord);

    void setVertexCoord(GLVertexCoord vertexCoord);
    GLVertexCoord getVertexCoord();

    void setTextureCoord(GLTexCoord textureCoord);
    GLTexCoord getTextureCoord();
};

//GLVertexCoord--------------------------------------------------------------------------
GLVertexCoord::GLVertexCoord()
{
	setLocation(0, 0);
}

GLVertexCoord::GLVertexCoord(GLfloat x, GLfloat y)
{
	setLocation(x, y);
}

void GLVertexCoord::setLocation(GLfloat x, GLfloat y)
{
	setX(x);
	setY(y);
}

void GLVertexCoord::setLocation(GLVertexCoord p)
{
    setLocation(p.getX(), p.getY());
}

void GLVertexCoord::setX(GLfloat x)
{
	_x = x;
}

GLfloat GLVertexCoord::getX()
{
    return _x;
}

void GLVertexCoord::setY(GLfloat y)
{
	_y = y;
}

GLfloat GLVertexCoord::getY()
{
    return _y;
}
//---------------------------------------------------------------------------------------

//GLTexCoord-----------------------------------------------------------------------------
GLTexCoord::GLTexCoord()
{
	setLocation(0, 0);
}

GLTexCoord::GLTexCoord(GLfloat s, GLfloat t)
{
	setLocation(s, t);
}

void GLTexCoord::setLocation(GLTexCoord p)
{
    setLocation(p.getS(), p.getT());
}

void GLTexCoord::setLocation(GLfloat s, GLfloat t)
{
	setS(s);
	setT(t);
}

void GLTexCoord::setS(GLfloat s)
{
	_s = s;
}

GLfloat GLTexCoord::getS()
{
    return _s;
}

void GLTexCoord::setT(GLfloat t)
{
	_t = t;
}

GLfloat GLTexCoord::getT()
{
    return _t;
}
//---------------------------------------------------------------------------------------

//GLTexturedVertex-----------------------------------------------------------------------
GLTexturedVertex::GLTexturedVertex()
{

}

GLTexturedVertex::GLTexturedVertex(GLVertexCoord vertexCoord, GLTexCoord textureCoord)
{
	setVertexCoord(vertexCoord);
	setTextureCoord(textureCoord);
}

void GLTexturedVertex::setVertexCoord(GLVertexCoord vertexCoord)
{
    _vertexCoord = vertexCoord;
}

GLVertexCoord GLTexturedVertex::getVertexCoord()
{
    return _vertexCoord;
}

void GLTexturedVertex::setTextureCoord(GLTexCoord textureCoord)
{
    _textureCoord = textureCoord;
}

GLTexCoord GLTexturedVertex::getTextureCoord()
{
    return _textureCoord;
}
//---------------------------------------------------------------------------------------

#endif // GLTEXTUREDVERTEX_H
