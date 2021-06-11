#include <iostream>
#include <vector>
#include "SimpleTimer.h"

class DataArray
{
public:
    DataArray()
    {
    }

    DataArray(const DataArray& other)
    {
        m_Data = other.m_Data;
    }

    DataArray(DataArray&& other)
    {
         m_Data = std::move(other.m_Data);
    }

    void InitArray(size_t dataCount)
    {
        m_Data.resize(dataCount);
        for (int i = 0; i < dataCount; i++)
        {
            m_Data.emplace_back(i);
        }
    }

    size_t GetDataCount() const { return m_Data.size(); }

private:
    std::vector<int> m_Data;
};

int main()
{
    DataArray array1;

    {
        SimpleTimer timer0("Initialize");
        array1.InitArray(1000000);
    }

    {
        SimpleTimer timer1("Copy");
        DataArray array2(array1);
    }

    {
        SimpleTimer timer2("Move");
        DataArray array3(std::move(array1));
    }

    return 0;
}