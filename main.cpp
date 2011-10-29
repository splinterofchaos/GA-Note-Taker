
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Window.h"
#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp> // For RendWin, Font.

#include <cctype>
char capture_key( const sf::Event& e )
{
    char key = 0;
    if( e.Type == sf::Event::KeyPressed )
    {
        if( std::isalnum(e.Key.Code) )
            key = e.Key.Code;
    }

    return key;
}

int main()
{
    sf::RenderWindow window;
    init_window( window, 600, 600 );

    sf::Font font;
    font.LoadFromFile( "/Library/Fonts/Arial Black.ttf" );

    sf::String inputText( "", font, 50 );
    inputText.SetColor( sf::Color(255,255,255) ); 
    inputText.SetPosition( 50, 50 );

    while( window.IsOpened() )
    {
        sf::Event Event;
        while( window.GetEvent(Event) )
        {
            if( quit_requested(Event) )
                window.Close();

            if( char c = capture_key(Event) )
            {
                std::string txt = inputText.GetText();
                inputText.SetText( txt + c );
            }
        }

        glClear( GL_COLOR_BUFFER_BIT );
        window.Draw( inputText );
        window.Display();
    }

    return EXIT_SUCCESS;
}

