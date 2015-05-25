/**
    TextureLoader.h
    Purpose: Load textures.

    @author Ion Ureche
    @version 1.0
*/
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

	//The instance of this class
	static TextureLoader *_instance;
	//The map of all the loaded textures
	unordered_map<string, GLuint> textures;
	//The path for the placeholder texture
	//in case the currently loaded texture
	//does not exist
	static string placeholderPath;
	TextureLoader(){}

public:

    /**
        Get the instance of this class.

        @param
        @return
    */
	static TextureLoader* getInstance()
	{
		if(_instance == NULL) {
			_instance = new TextureLoader();

			//load the placeholder
			_instance -> addTexture(placeholderPath);
		}
		return _instance;
	}

    /**
        Adds a new texture to the texture map.

        @param path the path of the texture to
        load to the texture map
        @return
    */
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

    	if( newTexture == 0 ) {
    		Logger::write("SOIL loading " + path + " error: " + SOIL_last_result());
    	}
	    else {
	    	Logger::write("SOIL loaded " + path);
	    }

		textures.insert(make_pair(path, newTexture));
	}

    /**
        Get the texture.

        @param path the path of the texture
        @return the texture from the given path
    */
	GLuint getTexture(string path)
	{
		//show placeholder if the texture does not exist
		if(textures[path] == NULL || textures[path] == 0){
			return textures[placeholderPath];
		}
		return textures[path];
	}
};

TextureLoader* TextureLoader::_instance = NULL;
string TextureLoader::placeholderPath = "Assets/placeholder.png";

#endif // TEXTURE_LOADER_H