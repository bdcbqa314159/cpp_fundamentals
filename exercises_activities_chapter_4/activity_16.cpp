#include <iostream>
#include <array>
#include <functional>

template <size_t R, size_t C, typename T = int, typename Multiply = std::multiplies<T>>
class Matrix
{
    std::array<T, R * C> data{};

public:
    Matrix() : data({}) {}

    void setRow(size_t row, const std::array<T, C> &rowValue)
    {
        if (row >= R)
            std::abort();
        for (size_t c = 0; c < C; c++)
        {
            get(row, c) = rowValue[c];
        }
        return;
    }

    T &get(size_t row, size_t col)
    {
        if (row >= R || col >= C)
            std::abort();
        return data[row * C + col];
    }

    const T &get(size_t row, size_t col) const
    {
        if (row >= R || col >= C)
            std::abort();
        return data[row * C + col];
    }

    std::array<T, R> multiply(const std::array<T, C> &vector, Multiply multiply = Multiply())
    {
        std::array<T, R> result{};
        for (size_t r = 0; r < R; r++)
        {
            for (size_t c = 0; c < C; c++)
            {
                result[r] += multiply(get(r, c), vector[c]);
            }
        }
        return result;
    }
};

template <size_t R, size_t C, typename T = int, typename Mult>
std::ostream &operator<<(std::ostream &os, const Matrix<R, C, T, Mult> &matrix)
{
    os << std::endl;
    for (size_t r = 0; r < R; r++)
    {
        for (size_t c = 0; c < C; c++)
        {
            os << matrix.get(r, c) << " ";
        }
        os << std::endl;
    }
    return os;
}

int main()
{
    std::cout << "Activity 16: Making the Matrix Class Easier to Use" << std::endl;

    Matrix<3, 2> matrix;
    matrix.setRow(0, {1, 2});
    matrix.setRow(1, {3, 4});
    matrix.setRow(2, {5, 6});

    std::cout << "Initial matrix:" << matrix << std::endl;

    Matrix<3, 2, int, std::plus<int>> matrixAdd;
    matrixAdd.setRow(0, {1, 2});
    matrixAdd.setRow(1, {3, 4});
    matrixAdd.setRow(2, {5, 6});

    std::array<int, 2> vector = {8, 9};
    std::array<int, 3> result = matrixAdd.multiply(vector);
    std::cout << "Result of multiplication (with plus instead of multiply): [" << result[0] << ", "
              << result[1] << ", " << result[2] << "]" << std::endl;

    return 0;
}
