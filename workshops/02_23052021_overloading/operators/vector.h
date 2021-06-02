#pragma once

class Vector {
    private:
        double x1;
        double x2;
        double x3;

    public:
        Vector() = default;
        Vector(double x1, double x2, double x3);
        double getX1(void);
        double getX2(void);
        double getX3(void);
        void setX1(double x1);
        void setX2(double x2);
        void setX3(double x3);
        double operator %=(Vector &v);
        Vector operator *=(Vector &v);
        bool operator ()(void);
};
