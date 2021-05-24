
#include "SessionFactory.h"

std::unique_ptr<soci::session> SessionFactory::getSession() {
    if (m_globalSession == nullptr) {
        m_globalSession = std::make_unique<soci::session>(soci::postgresql,
                                                          "host=postgres user=postgres password=password");
    }

    return std::move(m_globalSession);
}

void SessionFactory::closeSession() {
    if (m_globalSession == nullptr) {
        m_globalSession.reset();
    }
}
