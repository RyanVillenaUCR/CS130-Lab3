#include <iostream>

struct array
{
    int * data;
    size_t n;

    array()
        :data(0), n(0)
    {
    }

    array(size_t size)
        :data(new int[size]), n(size)
    {
    }

    ~array() {
        delete [] data;
    }

    array(const array& other)
        : data(new int[other.n]), n(other.n) {

        for (size_t i = 0; i < other.n; i++) {
            data[i] = other.data[i];
        }
    }

    array& operator=(const array& other) {

        delete [] this->data;
        this->n = 0;

        this->data = new int[other.n];

        for (size_t i = 0; i < other.n; i++)
            this->data[i] = other[i];

        this->n = other.n;

        return *this;
    }

    const int& operator[](size_t i) const
    {
        return data[i];
    }

    int& operator[](size_t i)
    {
        return data[i];
    }
    
    const array operator + (const array& c) const
    {
        array r(n);
        for(size_t i = 0; i < n; i++)
            r[i] = data[i] + c[i];
        return r;
    }

    const array operator - (const array& c) const
    {
        array r(n);
        for(size_t i = 0; i < n; i++)
            r[i] = data[i] - c[i];
        return r;
    }
};

void print(const array& c)
{
    std::cout << "( ";
    for(size_t i = 0; i < c.n; i++)
        std::cout << c[i] << " ";
    std::cout << ")" << std::endl;
}

template<class T>
void print(double x, T extra = "\n")
{
    std::cout << x << extra;
}

int main()
{
    array a(2);
    a[0] = 4;
    a[1] = 5;
    print(a);

    array b(2);
    b[0] = 7;
    b[1] = 9;
    print(b);

    array c = a + b;
    array d = c - a;

    print(c);
    print(d);

    print(0, ", ");
    print(1);

    return 0;
}

