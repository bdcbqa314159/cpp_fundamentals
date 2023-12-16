#include <iostream>

class CoordinatesManager
{

public:
    CoordinatesManager() : size(0), array(nullptr)
    {
    }

    explicit CoordinatesManager(size_t size) : size(size)
    {
        array = new int[size];
    }

    ~CoordinatesManager()
    {
        delete[] array;
    }

    void allocation()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << "Enter a value >> ";
            std::cin >> array[i];
        }
    }

    void display()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << "array[" << i << "]=" << array[i] << ", ";
        }
        std::cout << std::endl;
    }

private:
    size_t size;
    int *array;
};

int main()
{
    CoordinatesManager test(4);

    test.allocation();

    test.display();

    return 0;
}
