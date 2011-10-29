
#include <SFML/Graphics.hpp> // For Font, Input, Event.
#include <string>

struct TextBox
{
    sf::Vector2<int> pos;

    sf::String  gfxStr;
    std::string rawStr;

    sf::RenderWindow& win;
    
    TextBox( int x, int y, sf::RenderWindow&, sf::Font& );
    
    void        text( const std::string& str );
    std::string text();

    void draw();
    
    void update_text();
}; 

struct InputBox : TextBox
{
    InputBox( int x, int y, sf::RenderWindow&, sf::Font& );

    void capture_input( const sf::Event& e );
};
