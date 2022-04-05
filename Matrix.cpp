#include "Matrix.hpp"
using namespace std;

namespace zich
{
    Matrix::Matrix(std::vector<double> matAsVector, int rows, int cols)
    {
        cout << rows << "  " << cols << "  " << matAsVector.size() << endl;
        if (rows <= 0 || cols <= 0 || rows * cols != matAsVector.size())
        {
            __throw_invalid_argument("rows or columns are negative or 0 or the dimensions do not match the vector given");
        }
        vector<vector<double>> mat;
        for (size_t i = 0; i < rows; i++)
        {
            vector<double> ithRow;
            for (size_t j = 0; j < cols; j++)
            {
                ithRow.push_back(matAsVector.at(i*size_t(cols) + j));
            }
            mat.push_back(ithRow);
        }
        this->matrix = mat;
    }

    Matrix::Matrix(const Matrix& other)
    {
        vector<vector<double>> mat;
        for (size_t i = 0; i < other.matrix.size(); i++)
        {
            vector<double> ithRow;
            for (size_t j = 0; j < other.matrix[0].size(); j++)
            {
                ithRow.push_back(other.matrix.at(i).at(j));
            }
            mat.push_back(ithRow);
        }
        this->matrix = mat;
    }
    Matrix::~Matrix()
    {

    }

    Matrix Matrix::operator+(const Matrix& other) const
    {
        if (other.matrix.size() != this->matrix.size() || other.matrix.at(0).size() != this->matrix.at(0).size())
        {
            __throw_invalid_argument("The matrices are not of the same size");
        }

        Matrix answer(other);
        for (size_t i = 0; i < this->matrix.size(); i++)
        {
            for (size_t j = 0; j < this->matrix.at(0).size(); j++)
            {
                answer.matrix.at(i).at(j) += this->matrix.at(i).at(j);
            }
        }
        return answer;
        return *this;
    }
    Matrix Matrix::operator+=(const Matrix& other) const
    {
        return *this + other;
    }
    Matrix Matrix::operator+() const
    {
        return Matrix(*this);
    }

    Matrix Matrix::operator-(const Matrix& other) const
    {
        if (other.matrix.size() != this->matrix.size() || other.matrix.at(0).size() != this->matrix.at(0).size())
        {
            __throw_invalid_argument("The matrices are not of the same size");
        }

        Matrix answer(*this);
        for (size_t i = 0; i < this->matrix.size(); i++)
        {
            for (size_t j = 0; j < this->matrix.at(0).size(); j++)
            {
                answer.matrix.at(i).at(j) -= other.matrix.at(i).at(j);
            }
        }
        return answer;
    }
    Matrix Matrix::operator-=(const Matrix& other) const
    {
        return *this - other;
    }
    Matrix Matrix::operator-() const
    {
        return (*this);// * (-1.0);
    }

    Matrix Matrix::operator++()
    {
        for (size_t i = 0; i < this->matrix.size(); i++)
        {
            for (size_t j = 0; j < this->matrix.at(0).size(); j++)
            {
                this->matrix.at(i).at(j) += 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator++(int)
    {
        Matrix temp = *this;
        ++(*this);
        return temp;
    }
    Matrix Matrix::operator--()
    {
        for (size_t i = 0; i < this->matrix.size(); i++)
        {
            for (size_t j = 0; j < this->matrix.at(0).size(); j++)
            {
                this->matrix.at(i).at(j) -= 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator--(int)
    {
        Matrix temp = *this;
        --(*this);
        return temp;
    }

    Matrix Matrix::operator*(const double value)
    {
        for (size_t i = 0; i < this->matrix.size(); i++)
        {
            for (size_t j = 0; j < this->matrix.at(0).size(); j++)
            {
                this->matrix.at(i).at(j) *= value;
            }
        }
        return *this;
    }
    Matrix Matrix::operator*=(const double value)
    {
        return *this * value;
    }
    Matrix Matrix::operator*(const Matrix& other) // Unimplemented
    {
        return *this;
    }
    Matrix Matrix::operator*=(const Matrix& other)
    {
        return *this * other;
    }

    bool Matrix::operator==(const Matrix& other) const
    //Check the matrices are of the same dimentions
    {
        try
        {
            for (size_t i = 0; i < this->matrix.size(); i++)
            {
                for (size_t j = 0; j < this->matrix.at(0).size(); j++)
                {
                    if (this->matrix.at(i).at(j) != other.matrix.at(i).at(j))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        catch(const std::exception& e)
        {
            return false;
        }
    }
    bool Matrix::operator!=(const Matrix& other) const
    {
        return !(*this == other);
    }
    bool Matrix::operator<(const Matrix& other) const
    {
        double sumThis = 0;
        double sumOther = 0;
        for (size_t i = 0; i < this->matrix.size(); i++)
        {
            for (size_t j = 0; j < this->matrix.at(0).size(); j++)
            {
                sumThis += this->matrix.at(i).at(j);
                sumOther += other.matrix.at(i).at(j);
            }
        }
        return sumThis < sumOther;
    }
    bool Matrix::operator<=(const Matrix& other) const
    {
        return false;
    }
    bool Matrix::operator>(const Matrix& other) const
    {
        return false;
    }
    bool Matrix::operator>=(const Matrix& other) const
    {
        return false;
    }

    std::ostream& operator<<(std::ostream& output, const Matrix& mat)
    {
        return output;
    }
    std::istream& operator>>(std::istream& input, Matrix& mat)
    {
        return input;
    }

    Matrix operator*(const double value, Matrix& other)
    {
        std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix a{identity, 3, 3};
        return a;
    }
}