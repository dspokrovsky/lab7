/*
 * Используя паттерн Proxy, реализовать «умный» указатель для
 * объектов шаблонного класса. Необходимо реализовать подсчет
 * числа ссылок на реальный объект. При отсутствии ссылок память
 * под объект автоматически освобождается */

#include <iostream>
#include "smart_ptr.hpp"
struct Foo
{
    Foo()      { std::cout << "Foo::Foo\n";  }
    ~Foo()     { std::cout << "Foo::~Foo\n"; }
    void bar() { std::cout << "Foo::bar\n";  }
};

int main()
{
    detail::smart_ptr<Foo> ptr1(new Foo);
    std::cout << *(ptr1.count) << std::endl;
    detail::smart_ptr<Foo> ptr2 = ptr1;
    std::cout << *(ptr1.count) << std::endl;
    detail::smart_ptr<Foo> ptr3(new Foo);
    std::cout << *(ptr1.count)<<std::endl;
    ptr2 = ptr3;
    std::cout << *(ptr1.count)<<std::endl;
    detail::smart_ptr<Foo> ptr4(ptr1);
    std::cout << *(ptr1.count)<<std::endl;
    detail::smart_ptr<Foo> ptr5(ptr1);
    std::cout << *(ptr1.count)<<std::endl;

    std::cout <<"________" << std::endl;
    (*ptr2).bar();
    std::cout <<"--------" << std::endl;

    ptr2->bar();
    return 0;
}

