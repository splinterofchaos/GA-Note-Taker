
#include "Window.h"

// Stolen from http://nehe.gamedev.net/tutorial/lines,_antialiasing,_timing,_ortho_view_and_simple_sounds/17003/
void gl_resize_view( GLsizei width, GLsizei height )
{
    // Prevent a divide by zero.
    if( ! height ) 
        height=1;                        
 
    glViewport( 0, 0, width, height );
 
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();            
 
    glOrtho( 0.0f, width, height, 0.0f, -1.0f, 1.0f);
 
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();           
}

void init_window( sf::Window& win, int w, int h )
{
    win.Create( sf::VideoMode(w, h, 32), "" );
    gl_resize_view( w, h );
}

bool quit_requested( const sf::Event& e )
{
    bool ret;
    ret = e.Type == sf::Event::Closed;
    ret = ret || ( e.Type == sf::Event::KeyPressed && 
                   e.Key.Code == sf::Key::Escape );
    return ret;
}
