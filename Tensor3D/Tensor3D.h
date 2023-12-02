#pragma once


void DrawPolygon(std::vector<Point>& points, cimg_library::CImg<unsigned char>& image, const unsigned char color[3]);
void GetPolygon(std::vector<Point>& points);
void GetPolygon2(std::vector<Point>& points);
