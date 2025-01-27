
#include <iostream>

class Shape {
  public:
    virtual void draw() noexcept = 0;
    virtual ~Shape() {
     std::cout<<"Shape Destuctor is called:"<<"\n"; 
    }
};

class Square : public Shape {
  public:
    void draw() noexcept override;

    ~Square() override {
     std::cout<<"Square Destuctor is called:"<<"\n"; 
    }
};

class Rectangle : public Shape {
  public:
    void draw() noexcept override;

    ~Rectangle() override {
     std::cout<<"Rectangle Destuctor is called:"<<"\n"; 
    }
};

class Triangle : public Shape {
  public:
    void draw() noexcept override;

    ~Triangle() override {
     std::cout<<"Triangle Destuctor is called:"<<"\n"; 
    }
};