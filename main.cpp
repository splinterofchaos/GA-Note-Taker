
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Window.h"
#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp> // For RendWin, Font.

#include <cctype>
char capture_key( const sf::Window& win, const sf::event& e )
{
    char key = 0;
    if( e.Type == sf::event::KeyPressed )
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

    sf::RenderWindow window;
    init_window( window, 600, 600 );

    sf::Font font;
    font.LoadFromFile( "/Library/Fonts/Arial Black.ttf" );

    sf::String inputText( "", font, 50 );
    inputText.SetColor( WHITE ); 
    inputText.SetPosition( 50, 50 );

    while( window.IsOpened() )
    {
        sf::event event;
        while( window.Getevent(event) )
        {
            if( quit_requested(event) )
                window.Close();

            if( char c = capture_key(window,event) )
            {
                std::string txt = inputText.GetText();
                inputText.SetText( txt + c );
            }

        }

        sf::Shape inputBox;
        sf::Rect<float> boarders = inputText.GetRect();
        inputBox.AddPoint( boarders.Left  - 10, boarders.Top    - 10, GREY );
        inputBox.AddPoint( boarders.Right + 10, boarders.Top    - 10, GREY );
        inputBox.AddPoint( boarders.Right + 10, boarders.Bottom + 10, GREY );
        inputBox.AddPoint( boarders.Left  - 10, boarders.Bottom + 10, GREY );

        glClear( GL_COLOR_BUFFER_BIT );
        window.Draw( inputBox );
        window.Draw( inputText );
        window.Display();
    }

    return EXIT_SUCCESS;
}

