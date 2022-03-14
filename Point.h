#pragma once
class Point
{
	int m_x, m_y;
public:
	explicit Point(int x, int y);
	Point();
	Point& operator+=(const Point& other);
	Point& operator+=(int d);
	friend Point& operator-=(Point& f, const Point& s);
	friend Point& operator-=(Point& f, int d);
	Point operator+(const Point& other) const;
	Point operator+(int d) const;
	friend Point operator-(const Point& f, int d);
	friend Point operator-(const Point& f, const Point& s);
	friend Point operator+(int d, const Point& f);
	Point operator-() const;
	const Point& operator+() const;
};
Point& operator-=(Point& f, const Point& s);
Point& operator-=(Point& f, int d);
Point operator-(const Point& f, int d);
Point operator-(const Point& f, const Point& s);
Point operator+(int d, const Point& f);