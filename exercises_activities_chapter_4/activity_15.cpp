#include <iostream>
#include <array>

template <typename T, size_t R, size_t C>
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

    std::array<T, R> multiply(const std::array<T, C> &vector)
    {
        std::array<T, R> result{};
        for (size_t r = 0; r < R; r++)
        {
            for (size_t c = 0; c < C; c++)
            {
                result[r] += get(r, c) * vector[c];
            }
        }
        return result;
    }
};

template <typename T, size_t R, size_t C>
std::ostream &operator<<(std::ostream &os, const Matrix<T, R, C> &matrix)
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
    std::cout << "Activity 15: Writing a Matrix Class for Mathematical Operations in a Game" << std::endl;

    Matrix<int, 3, 2> matrix;
    matrix.setRow(0, {1, 2});
    matrix.setRow(1, {3, 4});
    matrix.setRow(2, {5, 6});

    std::cout << "Initial matrix:" << matrix << std::endl;
    std::cout << "Setting matrix[1][1] to 7" << std::endl;

    // Get returns a mutable reference, so we can assign a value to it
    matrix.get(1, 1) = 7;

    std::cout << "Modified matrix:" << matrix << std::endl;

    std::array<int, 2> vector = {8, 9};
    std::array<int, 3> result = matrix.multiply(vector);
    std::cout << "Result of multiplication: [" << result[0] << ", "
              << result[1] << ", " << result[2] << "]" << std::endl;

    return 0;
}
