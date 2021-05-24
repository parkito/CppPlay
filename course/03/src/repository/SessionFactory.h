#pragma once

#include <session.h>
#include <postgresql/soci-postgresql.h>
#include <memory>

class SessionFactory {
public:
    static std::unique_ptr<soci::session> createSession();

    static std::unique_ptr<soci::session> globalSession();

    static void resetGlobalSession();

private:
    static std::unique_ptr<soci::session> m_globalSession;
};

