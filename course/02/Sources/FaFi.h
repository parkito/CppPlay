#pragma once

class FaFi {
public:
    FaFi(const int fa, const int fi) : fa(fa), fi(fi) {};

    int get_fa() {
        return fa;
    }

    int get_fi() {
        return fi;
    }

private:
    const int fa;
    const int fi;
};
