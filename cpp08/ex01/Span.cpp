#include "Span.hpp"

Span::Span(void) : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &rhs) : _N(rhs.getN()) { this->_data = rhs._data; }

Span::~Span() {}

Span&   Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->_N = rhs.getN();
        this->_data.clear();
        this->_data = rhs._data;
    }
    return (*this);
}

void            Span::addNumber(int const n)
{
    if (this->_data.size() == this->_N)
        throw std::runtime_error(std::string("The array is already full"));
    this->_data.push_back(n);
}

unsigned int Span::shortestSpan(void) const
{
    if (this->_data.size() <= 1)
        throw std::runtime_error(std::string("Not enough data to search a span"));
    unsigned int span = std::abs(this->_data[0] - this->_data[1]);
    for (std::vector<int>::const_iterator it = this->_data.begin(); it != this->_data.end(); it++)
        for (std::vector<int>::const_iterator jt = it + 1; jt != this->_data.end(); jt++)
            if (span > static_cast<unsigned int>(std::abs(*it - *jt)))
                span = static_cast<unsigned int>(std::abs(*it - *jt));
    return (span);
}

unsigned int    Span::longestSpan(void) const
{
    if (this->_data.size() <= 1)
        throw std::runtime_error(std::string("Not enough data to search a span"));
    int min = *std::min_element(this->_data.begin(), this->_data.end());
    int max = *std::max_element(this->_data.begin(), this->_data.end());
    long ret = max - min;
    return (static_cast<unsigned int>(std::abs(ret)));
}

unsigned int    Span::getN(void) const { return (this->_N); }

std::vector<int>    Span::getData(void) const { return (this->_data); }