
#include "TextBox.h"

TextBox::TextBox( int x, int y, sf::RenderWindow& win, sf::Font& font )
    : gfxStr( "", font, 10 ), win( win )
{
    gfxStr.SetColor( sf::Color(255,255,255) );
    gfxStr.SetPosition( x, y );

    update_text();
}

void TextBox::text( const std::string& str )
{
    rawStr = str;
    update_text();
}

std::string TextBox::text()
{
    return rawStr;
}

void TextBox::draw()
{
    sf::Color c( 50, 50, 50 );
    sf::Shape background;
    sf::Rect<float> boarders = gfxStr.GetRect();

    background.AddPoint( boarders.Left  - 10, boarders.Top    - 10, c );
    background.AddPoint( boarders.Right + 10, boarders.Top    - 10, c );
    background.AddPoint( boarders.Right + 10, boarders.Bottom + 10, c );
    background.AddPoint( boarders.Left  - 10, boarders.Bottom + 10, c );

    win.Draw( background );
    win.Draw( gfxStr );
}

void TextBox::update_text()
{
    gfxStr.SetText( rawStr );
}

InputBox::InputBox( int x, int y, sf::RenderWindow& w, sf::Font& f )
    : TextBox( x, y, w, f )
{
}

void InputBox::capture_input( const sf::Event& e )
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

    rawStr += key;
    update_text();
}
