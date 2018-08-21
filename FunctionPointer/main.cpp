#include <iostream>
#include <functional>

//普通的函数定义
int normalfunc(int a, int b) {
    std::cout << "call in normal function " << a << "  " << b << std::endl;
    return a + b;
}

//定义一个lambda表达式，然后通过函数指针指向这个表达式，因为有指针可以多次调用
std::function<int(int, int)> lambdafuncton = [](int a, int b) {
    a += 5;
    b += 10;
    std::cout << "call in lambda func " << a << "  " << b << std::endl;
    return a + b;
};

//返回一个函数指针的函数
std::function<int(int, int)> func2() {
    return [](int a, int b) {
        ++a;
        ++b;
        std::cout << "call in inner lambda in func2 " << a << "  " << b << std::endl;
        return a + b;
    };
}

//接收一个函数指针作为参数的函数
int func3(std::function<int(int, int)> fun1) {
    return fun1(100, 200);
}

int main()
{
    std::cout << "Hello World!" << std::endl;

    int lambdacallresult = func3(lambdafuncton);     //将 lambda表达式的函数指针  作为 参数 传递给接收 函数指针 作为 参数 的函数
    std::cout << "result " << lambdacallresult << std::endl;

    std::cout << std::endl;

    lambdacallresult = func3([](int a, int b){  //因为lambda表达式没有名称，只能在这个地方使用一次
        a *= 10;
        b *= 3;
        std::cout << "call in disposable lambda func " << a << "  " << b << std::endl;
        return a + b;
    });
    std::cout << "result " << lambdacallresult << std::endl;

    std::cout << std::endl;

    int functioncallresult = func3(func2());    //func2() 返回一个函数指针，func3()接收一个函数指针作为参数
    std::cout << "result " << functioncallresult << std::endl;

    std::cout << std::endl;

    functioncallresult = func3(normalfunc);   //没有lambda表达式的情况，接受一个函数作为参数
    std::cout << "result " << functioncallresult << std::endl;

    return 0;
}
