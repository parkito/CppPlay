#pragma once

#include <session.h>
#include <postgresql/soci-postgresql.h>
#include <memory>

class SessionFactory {
public:
    SessionFactory();

    std::unique_ptr<soci::session> getSession();

    void closeSession();

private:
    std::unique_ptr<soci::session> m_globalSession;
};


