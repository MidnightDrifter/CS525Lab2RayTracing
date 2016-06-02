#ifndef SHAPES_H
#define SHAPES_H

#include <utility> //pair<T1,T2>, make_pair, p.first, p.second
#include <fstream>
class Shape {

private:

public:
	
	virtual ~Shape() = 0;
	virtual std::pair<bool, float> Intersect(Ray const& ray) const = 0;
	virtual friend std::ostream& operator<<(std::ostream& os, Shape const& s) =0;
	virtual void Print() const = 0;
	virtual BoundingCircle GetBoundingCircle() const = 0;

};



class Ray {
    private:
        float  origin_x;
        float  origin_y;
        float  dir_x;
        float  dir_y;
    public:
		Ray(float a, float b, float c, float d);

		friend std::ostream& operator<<(std::ostream& os, Ray const& r);
		
		std::pair<bool, float> IntersectSegment(float a, float b, float c, float d) const;
		// compiler generated copy, assignment, destructor are OK
		float const& Origin_x() const;
		float const& Origin_y() const;
		float const& Direction_x() const;
		float const& Direction_y() const;

};

class BoundingCircle {
    private:
        float  center_x;
        float  center_y;
        float  radius;
    public:
		BoundingCircle(float a, float b, float c);
		friend std::ostream& operator<<(std::ostream & os, BoundingCircle const& bc);
		bool IntersectTest(Ray const& ray) const;

};

class Box : public Shape {
    private:
        float center_x;
        float center_y;
        float side_x;
        float side_y;
    public:
		Box(float a, float b, float c, float d);
		BoundingCircle GetBoundingCircle() const;
        // compiler generated copy, assignment, destructor are OK
		std::pair<bool, float> Intersect(Ray const& ray) const;
		friend std::ostream& operator<<(std::ostream& os, Box const& b);
		void Print() const;
};

class Rhombus : public Shape {
    private:
        float center_x;
        float center_y;
        float diag_x;
        float diag_y;
    public:
		Rhombus(float a, float b, float c, float d);
		BoundingCircle GetBoundingCircle() const;
        // compiler generated copy, assignment, destructor are OK
		friend std::ostream& operator<<(std::ostream& os, Rhombus const& r);
		std::pair<bool, float> Intersect(Ray const& ray) const;
		void Print() const;
};

#endif
