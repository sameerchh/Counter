#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;

int main()
{
    int intCount=0;

    RenderWindow window(VideoMode({200,300}), "Counter");

        ///Background
    Texture texture1("Background.png");
    Sprite bg(texture1);
    bg.setScale({2,2});

        ///Count Button
    Texture texture2("button.png");
    Sprite button(texture2);
    button.setPosition({40,160});
    button.setScale({2.4,2});

        ///Count Pressed
    Texture texture3("pressed.png");
    Sprite pressed(texture3);
    pressed.setPosition({40,160});
    pressed.setScale({2.4,2});

        ///Reset Button
    Texture texture4("button.png");
    Sprite reset(texture4);
    reset.setPosition({40,220});
    reset.setScale({2.4,2});

        ///Reset Pressed
    Texture texture5("pressed.png");
    Sprite reset2(texture5);
    reset2.setPosition({40,220});
    reset2.setScale({2.4,2});

        ///Font
    Font font("robotoo.ttf");

        ///Counter Display
    Text counter(font,std::to_string(intCount),70);
    counter.setPosition({80,50});

        ///Count Button Text
     Text countText(font,"Count",20);
    countText.setPosition({80,195});

        ///Reset Button Text
    Text resetText(font,"Reset",20);
    resetText.setPosition({80,255});

    int count=0;


    while(window.isOpen())
    {

        while(auto event=window.pollEvent())
        {

            if(event->is<Event::Closed>())
            {
                window.close();
            }

            auto mouse_position= Vector2f(Mouse::getPosition(window));

                //if(Mouse::isButtonPressed(Mouse::Button::Left))
                if(event->is<Event::MouseButtonPressed>())
                {
                    if(button.getGlobalBounds().contains(mouse_position))

                    count=1;
                    intCount+=1;

                }
                else
                {
                count=0;
                }

                if(event->is<Event::MouseButtonPressed>())
                {
                    if(reset.getGlobalBounds().contains(mouse_position))
                        {
                            intCount=0;
                            count=2;
                        }

                }
        }


    window.clear(Color::Cyan);

    window.draw(bg);

    window.draw(button);
    window.draw(countText);

    if(count==1)
    {
        window.draw(pressed);
    }

    counter.setString(std::to_string(intCount));
    window.draw(counter);

    window.draw(reset);
    window.draw(resetText);

    if(count==2)
    {
        window.draw(reset2);
    }

    window.display();
    }

    return 0;
}
