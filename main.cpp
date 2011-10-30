
#include "Window.h"
#include "TextBox.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> // For Window, Font.

#include <vector>

typedef std::vector< TextBox > MessageList;

void add_message( MessageList* list, const InputBox& input )
{
    if( ! list )
        return;

    int x, y; // Position of the new message.

    if( ! list->size() )
    {   x = 50;
        y = 50;
    } else 
    {   const sf::Vector2<int>& vec = list->back().pos;
        x = vec.x;
        y = vec,y;
    }

    TextBox newMessage = input;
    newMessage.pos.x = x;
    newMessage.pos.y = y;

    list->push_back( newMessage );
}

int main()
{
    const int WINDOW_W = 600;
    const int WINDOW_H = 600;

    sf::RenderWindow window;
    init_window( window, WINDOW_W, WINDOW_H );

    sf::Font font;
    font.LoadFromFile( "/Library/Fonts/Arial Black.ttf" );

    InputBox inputBox( 50, WINDOW_H - 50, window, font );

    std::vector< TextBox > messageList;

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
}

