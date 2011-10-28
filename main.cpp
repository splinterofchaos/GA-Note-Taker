
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Window.h"
#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp> // For RendWin, Font.

int main()
{
    sf::RenderWindow window;
    init_window( window, 600, 600 );

    sf::Font font;
    font.LoadFromFile( "/Library/Fonts/Arial Black.ttf" );

    sf::String inputText( "TEST", font, 50 );
    inputText.SetColor( sf::Color(255,255,255) ); 
    inputText.SetPosition( 50, 50 );

    while( window.IsOpened() )
    {
        sf::Event Event;
        while( window.GetEvent(Event) )
        {
            if( quit_requested(Event) )
                window.Close();
        }

        glClear( GL_COLOR_BUFFER_BIT );
        window.Draw( inputText );
        window.Display();
    }

    return EXIT_SUCCESS;
}

