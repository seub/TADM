// Standard library
#include <iostream> // Needed for std::cout etc.
#include <vector> // Needed for std::vector


template<typename T> std::ostream & operator<<(std::ostream &out, const std::vector<T> &V)
{
    out << "[";
    for (auto it = V.begin(); it+1!=V.end(); ++it) {out << *it << ", ";}
    if (!V.empty()) {out << V.back();}
    out <<  "]";
    return out;
}

template<typename T> void insertion_sort(std::vector<T> & out, const std::vector<T> & in) 
{
    uint c=0;
    out = in;
    for (auto it = out.begin()+1; it!=out.end(); ++it) 
    {
        auto jt = it;
            while ( (jt!=out.begin()) && (*jt < *(jt-1)) )
                {
                    std::swap(*jt, *(jt-1));
                    --jt;
                    ++c;
                }
    }
    std::cout << "Number of operations: " << c << std::endl;
}

int main()
{
    std::vector<int> in = {17, 4, 0, -5, 22, -8, 13, 13, -7, -5}, out;
    std::cout << in << std::endl;

    insertion_sort(out, in);
    std::cout << out << std::endl;

    return 0;
}