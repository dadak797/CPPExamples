#include "Singleton.h"
#include "App.h"


Singleton& Singleton::GetInstance()
{
    static Singleton s_Instance;
    return s_Instance;
}

Singleton::Singleton()
{
    m_pApp = new App();
}

Singleton::~Singleton()
{
    if (m_pApp) {
        delete m_pApp;
        m_pApp = nullptr;
    }
}