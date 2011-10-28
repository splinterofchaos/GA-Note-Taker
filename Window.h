
#include <SFML/Window.hpp>

void gl_resize_view( GLsizei width, GLsizei height );
void init_window( sf::Window& win, int w, int h, const char* const name="" );
bool quit_requested( const sf::Event& );

