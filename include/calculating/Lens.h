#ifndef OPTOCUS_LENS_H
#define OPTOCUS_LENS_H

#include <cmath>

#include "Ray.h"
#include "Object.h"
#include "Image.h"

class Lens {
    double _opt_pow;
    double _height;
    double _x;

public:
    Lens(double opt_pow, double x, double height);
    ~Lens() = default;

    double& x() { return _x; }
    const double& x() const { return _x; }

    double& optPow() { return _opt_pow; }
    const double& optPow() const  { return _opt_pow; }

    double& height() { return _height; }
    const double& height() const { return _height; }

    double getFocus() const;
    double getFocusLength() const;
    // converging or diffusing
    bool isConv() const;

    // get distance to image from distance to object
    double getDistanceToImage(double d) const;
    // get distance to object from distance to image
    double getDistanceToObject(double f) const;

    static double getImgHeight(double h, double f, double d);
    static double getObjHeight(double imgH, double f, double d);

    // calculate optical power
    static double getOptPow(double d, double f);

    Point getImage(const Point &point);
    Image getImageRays(const Point &point);
    Object getImage(const Object& obj);
};

#endif