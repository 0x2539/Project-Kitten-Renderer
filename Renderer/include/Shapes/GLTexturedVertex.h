/**
    GLVertexCoord.h
    Purpose: Contains basic classes for vertices,
    textured vertices and colored vertices.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef GLTEXTUREDVERTEX_H
#define GLTEXTUREDVERTEX_H

class GLVertexCoord
{
  private:

    //The x coordinate
    float _x;
    //The y coordinate
    float _y;

  public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
    GLVertexCoord();

    /**
        Initialise a new instance of this class.

        @param x the x coordinate of the vertex
        @param y the y coordinate of the vertex
        @return
    */
    GLVertexCoord(GLfloat x, GLfloat y);
    
    /**
        Set a new location for the vertex.

        @param x the x coordinate of the vertex
        @param y the y coordinate of the vertex
        @return
    */
    void setLocation(GLfloat x, GLfloat y);

    /**
        Set a new location for the vertex.

        @param p the vertex from which the current
        vertex will get the location
        @return
    */
    void setLocation(GLVertexCoord p);

    /**
        Set a new x coordinate for the vertex.

        @param x the x coordinate of the vertex
        @return
    */
    void setX(GLfloat x);

    /**
        Get the vertex's x coordinate.

        @param
        @return the vertex's x coordinate
    */
    GLfloat getX();
    
    /**
        Set a new y coordinate for the vertex.

        @param y the y coordinate of the vertex
        @return
    */
    void setY(GLfloat y);

    /**
        Get the vertex's y coordinate.

        @param
        @return the vertex's y coordinate
    */
    GLfloat getY();
};

class GLTexCoord
{
private:
    //The x coordinate
    GLfloat _s;
    //The y coordinate
    GLfloat _t;
public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
    GLTexCoord();

    /**
        Initialise a new instance of this class.

        @param s the x coordinate of the texture
        @param t the y coordinate of the texture
        @return
    */
    GLTexCoord(GLfloat s, GLfloat t);

    /**
        Set a new location for the vertex.

        @param s the x coordinate of the vertex
        @param t the y coordinate of the vertex
        @return
    */
    void setLocation(GLfloat s, GLfloat t);

    /**
        Set a new location for the vertex.

        @param p the vertex from which the current
        vertex will get the location
        @return
    */
    void setLocation(GLTexCoord p);

    /**
        Set a new x coordinate for the vertex.

        @param s the x coordinate of the vertex
        @return
    */
    void setS(GLfloat s);

    /**
        Get the vertex x coordinate.

        @param
        @return the vertex x coordinate
    */
    GLfloat getS();

    /**
        Set a new y coordinate for the vertex.

        @param t the y coordinate of the vertex
        @return
    */
    void setT(GLfloat t);

    /**
        Get the vertex t coordinate.

        @param
        @return the vertex t coordinate
    */
    GLfloat getT();
};

class GLTexturedVertex
{
private:
public:

    //The vertex
    GLVertexCoord _vertexCoord;
    //The vertex of the texture
    GLTexCoord _textureCoord;
    
    /**
        Initialise a new instance of this class.

        @param
        @return
    */
    GLTexturedVertex();

    /**
        Initialise a new instance of this class.

        @param vertexCoord the vertex
        @param textureCoord the vertex of the texture
        @return
    */
    GLTexturedVertex(GLVertexCoord vertexCoord, GLTexCoord textureCoord);

    /**
        Set the vertex.

        @param vertexCoord the new vertex value
        @return
    */
    void setVertexCoord(GLVertexCoord vertexCoord);

    /**
        Get the vertex.

        @param
        @return the vertex
    */
    GLVertexCoord getVertexCoord();

    /**
        Set the texture vertex.

        @param textureCoord the new texture vertex value
        @return
    */
    void setTextureCoord(GLTexCoord textureCoord);

    /**
        Get the texture vertex.

        @param
        @return the texture vertex
    */
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
