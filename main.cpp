
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Window.h"
#include "TextBox.h"

#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp> // For RendWin, Font.

int main()
{
    const sf::Color WHITE(255,255,255), GREY(100,100,100);

    const int WINDOW_W = 600;
    const int WINDOW_H = 600;

    sf::RenderWindow window;
    init_window( window, WINDOW_W, WINDOW_H );

    sf::Font font;
    font.LoadFromFile( "/Library/Fonts/Arial Black.ttf" );

    InputBox inputBox( 50, WINDOW_H - 50, window, font );

    while( window.IsOpened() )
    {
        sf::Event event;
        while( window.GetEvent(event) )
        {
            if( quit_requested(event) )
                window.Close();

            inputBox.capture_input( event );
        }

        glClear( GL_COLOR_BUFFER_BIT );
        inputBox.draw();
        window.Display();
    }

    return EXIT_SUCCESS;
}

