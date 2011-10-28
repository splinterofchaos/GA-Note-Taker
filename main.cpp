
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window.hpp>
#include "Window.h"

int main()
{
    sf::Window window;
    init_window( window, 600, 600 );

    while (window.IsOpened())
    {
        sf::Event Event;
        while (window.GetEvent(Event))
        {
            if( quit_requested(Event) )
                window.Close();
        }

        glClear( GL_COLOR_BUFFER_BIT );
        window.Display();
    }

    return EXIT_SUCCESS;
}

