#ifndef MATH_PROPERTY
#define MATH_PROPERTY

#include <QString>

class Math_Property
{
public:
    Math_Property() {}
    virtual QString dump() = 0;
    virtual double value() = 0;
};

#endif // MATH_PROPERTY

