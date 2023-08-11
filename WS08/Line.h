#ifndef LINE_H
#define LINE_H
#include "LblShape.h"

namespace sdds
{
    class Line : public LblShape
    {
    private:
        int m_length;

    public:
        Line();
        Line(const char *chr, int length);
        virtual ~Line() {}

        void getSpecs(std::istream &is) override;
        void draw(std::ostream &os) const override;
    };

}

#endif