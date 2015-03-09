#include "include.h"



GLuint LoadTexture( const char * filename, int width, int height )
{
    
	  GLuint texture;
	  unsigned char * data;
	  FILE * file;
    

    
	  file = fopen( filename, "rb" );
    
	  if ( file == NULL ) return 0;
    

    
	  data = (unsigned char *)malloc( width * height * 24 );
    

    
	  fread( data, width * height * 24, 1, file );
    
	  fclose( file );
    

    
	  glGenTextures( 1, &texture );
    

    
	  glBindTexture( GL_TEXTURE_2D, texture );
    

    
	  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE ); 
    

    
	  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
    

    
	  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    

    
	  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    
	  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    

    
	  gluBuild2DMipmaps( GL_TEXTURE_2D, 4, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );
    

    
	  free( data );
    

    
	  return texture;
    

}
