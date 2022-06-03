#pragma once

class App;

class Singleton
{
public:
    static Singleton& GetInstance();
    ~Singleton();

private:
    Singleton();
    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;

    App* m_pApp;
};

