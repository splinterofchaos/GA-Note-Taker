
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window.hpp>
#include "Window.h"

int main()
{
    sf::Window App;
    init_window( App, 600, 600 );

    const sf::Input& Input = App.GetInput();

    while (App.IsOpened())
    {
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            if( quit_requested(Event) )
                App.Close();
        }

        glClear( GL_COLOR_BUFFER_BIT );
        App.Display();
    }

    return EXIT_SUCCESS;
}

