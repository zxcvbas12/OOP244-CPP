#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"
namespace sdds
{
    class LblShape : public Shape
    {
    private:
        char *m_label;

    protected:
        const char *label() const;

    public:
        LblShape();
        LblShape(const char *label);
        virtual ~LblShape();

        LblShape(const LblShape &src) = delete;
        LblShape &operator=(const LblShape &src) = delete;

        void getSpecs(std::istream &is) override;
    };

}

#endif