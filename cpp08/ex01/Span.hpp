#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
    public:
        Span(void);
        Span(unsigned int N);
        Span(Span const &rhs);
        virtual ~Span();

        Span&   operator=(Span const &rhs);

        void                addNumber(int const n);
        unsigned int        shortestSpan(void) const;
        unsigned int        longestSpan(void) const;
        unsigned int        getN(void) const;
        std::vector<int>    getData(void) const;

        template<typename T>
        void            addRangeNumber(typename T::iterator begin, typename T::iterator end)
        {
            if (this->_data.size() + std::abs(std::distance(begin, end)) > this->_N)
                throw std::runtime_error(std::string("Adding too many numbers to the array"));
            for (typename T::iterator it = begin; it != end; it++)
                addNumber(*it);
        }

    private:
        unsigned int    _N;
        std::vector<int> _data;
};

#endif