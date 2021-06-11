#pragma once

#include <chrono>
#include <iostream>
#include <string>


class SimpleTimer
{
public:
    SimpleTimer(std::string timerName = "noname")
        : m_TimerName(timerName)
    {
        m_Start = std::chrono::high_resolution_clock::now();
    }

    ~SimpleTimer()
    {
        m_End = std::chrono::high_resolution_clock::now();
        m_Duration = m_End - m_Start;
        float msDuration = m_Duration.count() * 1000.0f;
        std::cout << "Timer: " << m_TimerName << std::endl
                  << "Elapsed Time: " << msDuration << "ms\n";
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> m_Start, m_End;
    std::chrono::duration<float> m_Duration;
    std::string m_TimerName;
};

