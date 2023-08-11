#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
    private:
        int m_width;
        int m_height;

    public:
        Rectangle();
        Rectangle(const char *lbl, int width, int height);
        virtual ~Rectangle() {}

        void getSpecs(std::istream &is);
        void draw(std::ostream &os) const;
    };

}
#endif