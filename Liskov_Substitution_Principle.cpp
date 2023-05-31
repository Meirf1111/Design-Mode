#include <iostream>

// 基类
class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a shape." << std::endl;
    }
};

// 子类1
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

// 子类2
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

// 客户端代码
void clientCode(const Shape& shape) {
    shape.draw();
}

int main() {
    Rectangle rectangle;
    Circle circle;

    // 客户端代码使用基类对象，传递子类对象
    clientCode(rectangle);
    clientCode(circle);

    return 0;
}
