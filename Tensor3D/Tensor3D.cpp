// Tensor3D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CImg.h"
#include "TensorOperations.h"
#include "Point.h"
#include <vector>
#include "Tensor3D.h"

const unsigned char bluegreen[] = { 0, 170, 255 };
const unsigned int width = 200;
const unsigned int height = 200;
const unsigned char blue[] = { 0, 0, 255 };

void DrawPolygon()
{
    cimg_library::CImg<unsigned char> bg(width, height, 1, 255);

    cimg_library::CImgDisplay dsp(width, height, "Red hair programmer", 0);

    std::vector<Point> points;
    GetPolygon2(points);
    double theta = 0;
    double alpha = 0;
    while (!dsp.is_closed())
    {
        int x = dsp.mouse_x();
        int y = dsp.mouse_y();
        
        std::vector<Point> points2;
        alpha = alpha + 0.01;
        if (alpha > 2 * 3.1415)
            alpha = 0;

        theta = theta + 0.1;
        if (theta > 2 * 3.1415)
			theta = 0;
        for (auto& p : points)
		{
            Point p2 = TensorOperations::Convert(p, theta, alpha);
            points2.push_back(p2);
		}

        cimg_library::CImg<unsigned char> image(bg);
        DrawPolygon(points2, image, bluegreen);
        dsp.display(image);
        //Sleep(10);
        //dsp.wait(); //wait for a mouse event
    }
}

void GetPolygon(std::vector<Point>& points)
{
    points.push_back(Point(10, 10, 0));
    points.push_back(Point(30, 90, 0));
    points.push_back(Point(60, 90, 0));
    points.push_back(Point(90, 10, 0));
}
void GetPolygon2(std::vector<Point>& points)
{
    points.push_back(Point(0, 0, 0));
    points.push_back(Point(90, 0, 0));
    points.push_back(Point(20, 50, 0));
    points.push_back(Point(45, -35, 0));
    points.push_back(Point(70, 50, 0));
}

void DrawPolygon(std::vector<Point>& points, cimg_library::CImg<unsigned char>& image, const unsigned char color[3])
{
    Point* p1 = &points[points.size() - 1];
    for (auto& p : points)
    {
        image.draw_line(p1->x + width/2, p1->y + height/2, p.x + width / 2, p.y + height / 2, color, 0.9);
        p1 = &p;
    }
}

void DrawCircle()
{
    cimg_library::CImg<unsigned char> image(width, height, 1, 255);
    const unsigned char blue[] = { 0, 0, 255 };
    image.draw_circle(width / 2, height / 2, 10, blue);
    image.display();
}

void DrawPolygonOnce()
{
    cimg_library::CImg<unsigned char> image(width, height, 1, 255);
    const unsigned char blue[] = { 0, 0, 255 };

    std::vector<Point> points;
    GetPolygon(points);
    DrawPolygon(points, image, bluegreen);

    image.display();
}

void DrawPolygon2Once()
{
    cimg_library::CImg<unsigned char> image(width, height, 1, 255);
    const unsigned char blue[] = { 0, 0, 255 };

    std::vector<Point> points;
    GetPolygon2(points);
    DrawPolygon(points, image, bluegreen);

    image.display();
}

int main()
{
    std::cout << "1. DrawCircle(); 2. DrawPolygonOnce(); 3. Draw another Polygon; 4. Draw and rotate\n";
    while (true)
	{
        auto c = std::cin.get();
        switch (c) {
        case '1':
            DrawCircle();
            break;
        case '2':
            DrawPolygonOnce();
            break;
        case '3':
            DrawPolygon2Once();
            break;
        case '4':
            DrawPolygon();
            break;
        default:
            break;
        }
    }
}

