
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Window.h"
#include "TextBox.h"

#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp> // For RendWin, Font.

#include <cctype>
char capture_key( const sf::Window& win, const sf::Event& e )
{
    char key = 0;
    if( e.Type == sf::Event::KeyPressed )
    {
        using namespace sf::Key;

        const sf::Input& inp = win.GetInput();
        switch( e.Key.Code )
        {
          case Space    : key = ' '; break;
          case Comma    : key = ','; break;
          case SemiColon: key = ';'; break;
          case Period   : key = '.'; break;
          case Divide   : key = '/'; break;
          case LBracket : key = '['; break;
          case RBracket : key = ']'; break;
          case Quote    : key = '\''; break;
          case Return   : key = '\n'; break;
          default:
           if( std::isalpha(e.Key.Code) )
           {
               key = e.Key.Code;
               if( inp.IsKeyDown(LShift) || inp.IsKeyDown(RShift) )
                   key += 'A' - 'a';
           }
           else if( std::isdigit(e.Key.Code) )
               key = e.Key.Code;
        }
    }

    return key;
}

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

