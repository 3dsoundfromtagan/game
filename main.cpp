#include <iostream>
#include "SFML/Graphics.hpp"
#include <time.h>
#include <cmath>
using namespace sf;
bool isMove = false,df = true;
bool fly = false;
float dx,x=100,y=100;
float x1,y2,t;
float dy;
int  k =0;
CircleShape cirkle(10);
RenderWindow window(VideoMode(640, 480), "Hello SFML");
CircleShape circle(30);
RectangleShape rectangle(Vector2f (10,400));
void flyr()
{
    float start_x = cirkle.getPosition().x,start_y= cirkle.getPosition().y;
    Clock clock;
    clock.restart();
    float speed_r_x = 0;
    float speed_r_y = 0;
    float al = atan((x-start_y)/(y-start_x)) ;
    float speed_x = 2*sqrt((100 - start_x)*(100-start_x)+(100-start_y)*(100-start_y))*cos(al);
    float speed_y = 2*sqrt((100 - start_x)*(100-start_x)+(100-start_y)*(100-start_y))*sin(al);
    float speed_y1;
    while((sqrt(speed_x*speed_x+speed_y1*speed_y1) >10))
    {
        float time = clock.getElapsedTime().asSeconds();
        t = time;
        cirkle.setPosition(start_x+speed_x*time,start_y+speed_y*time+50*time*time);
        if((cirkle.getGlobalBounds().intersects(rectangle.getGlobalBounds())))
        {
            if((sqrt(speed_x*speed_x+speed_y1*speed_y1) >1000)) {
                rectangle.setPosition(-100, 0);
                start_x = cirkle.getPosition().x;
                start_y = cirkle.getPosition().y;
                speed_x = -0.5 * speed_x;
                speed_y1 = -0.5 * speed_y1;
                speed_y = speed_y1;
                clock.restart();
            }
            else{
                start_x = cirkle.getPosition().x;
                start_y = cirkle.getPosition().y;
                speed_x =  -0.5*speed_x;
                speed_y1 =  -0.5*speed_y1;
                // speed_r_x = -0.1*speed_x;
                speed_r_y = 0.1*speed_y1;
                cirkle.setPosition(x1,y2);
                speed_y = speed_y1;
                clock.restart();
            }
        }
        speed_y1 =speed_y+ 100*time;
        if(abs(speed_r_x)>0.01) {
            rectangle.setPosition(380 + speed_r_x * time, 80);
            speed_r_x = 0.999 * speed_r_x;
        }
        if(circle.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
        {
            speed_r_x = 0;
            circle.setPosition(-100,0);
        }
        if(circle.getGlobalBounds().intersects(cirkle.getGlobalBounds()))
            if((sqrt(speed_x*speed_x+speed_y1*speed_y1) >20)) {
                circle.setPosition(-100,0);
                start_x = cirkle.getPosition().x;
                start_y = cirkle.getPosition().y;
                speed_x = 0.5 * speed_x;
                speed_y1 = 0.5 * speed_y1;
                speed_y = speed_y1;
                clock.restart();
            } else{
                start_x = cirkle.getPosition().x;
                start_y = cirkle.getPosition().y;
                clock.restart();
            }
        if((cirkle.getPosition().x>=560))
        {
            start_x = cirkle.getPosition().x;
            start_y = cirkle.getPosition().y;
            speed_x = -0.5*speed_x;
            speed_y1 = -0.5*speed_y1;
            speed_y = speed_y1;
            clock.restart();
        }

        if((cirkle.getPosition().y>=460))
        {
            start_x = cirkle.getPosition().x;
            start_y = cirkle.getPosition().y;
            speed_x = 0.5*speed_x;
            speed_y1 = -0.5*speed_y1;
            speed_y = speed_y1;
            clock.restart();
        }

        x1 = start_x+speed_x*t;
        y2 = start_y+speed_y*t+50*t*t;
        window.clear(Color::White);
        cirkle.setFillColor(Color::Yellow);
        window.draw(circle);
        window.draw(cirkle);
        window.draw(rectangle);
        window.display();


    }
}
int main() {




    rectangle.setFillColor((Color::Blue));
    rectangle.setPosition(380,80);
    cirkle.setPointCount(30);
    cirkle.setFillColor(Color::Green);
    cirkle.setPosition(100,100);
    circle.setPointCount(50);
    circle.setFillColor(Color::Red);
    circle.setPosition(400,420);
    window.draw(circle);


    while (window.isOpen()) {

        Vector2i PixelPos = Mouse::getPosition(window);
        Event event;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {

                window.close();

            }


            if (event.type == Event::MouseButtonPressed)
                if (event.mouseButton.button == Mouse::Left)
                    if (cirkle.getGlobalBounds().contains(PixelPos.x, PixelPos.y)) {
                        dx = PixelPos.x - cirkle.getPosition().x;
                        dy = PixelPos.y - cirkle.getPosition().y;
                        isMove = true;
                    }
            if (event.type == Event::MouseButtonReleased)
                if (event.mouseButton.button == Mouse::Left) {
                    isMove = false;
                    fly = true;
                }
            cirkle.setFillColor(Color::Green);
            if(fly) {
                flyr();
                fly = false;
            }
            if (isMove) {

                cirkle.setFillColor(Color::Black);
                cirkle.setPosition(PixelPos.x - dx, PixelPos.y - dy);
            }




            window.clear(Color::White);
            window.draw(circle);

            window.draw(cirkle);
            window.draw(rectangle);
            window.display();


        }

    }

    return 0;
}



