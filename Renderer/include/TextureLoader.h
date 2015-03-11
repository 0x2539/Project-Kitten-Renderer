#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H
#include <unordered_map>
#include <string>
#include <utility>
#include <SOIL.h>
#include "Logger.h"

using namespace std;

class TextureLoader{
private:
	static TextureLoader *_instance;
	unordered_map<string, GLuint> textures;

public:
	TextureLoader()
	{
		//_instance = getInstance();
	}

	static TextureLoader* getInstance()
	{
		if(_instance == NULL) _instance = new TextureLoader();
		return _instance;
	}

	void addTexture(string path)
	{
		GLuint newTexture = SOIL_load_OGL_texture
		(
			path.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

    	if( newTexture == 0 ) 
    		Logger::write("SOIL loading " + path + " error: " + SOIL_last_result());
	    else 
	    	Logger::write("SOIL loaded " + path);

		textures.insert(make_pair(path, newTexture));
	}

	GLuint getTexture(string path)
	{
		// TO DO: Placeholder when texture is not found in map
		return textures[path];
	}
};

TextureLoader* TextureLoader::_instance = NULL;

#endif // TEXTURE_LOADER_H