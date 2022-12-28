#pragma once

namespace gm {

    class PublicVar {
    public:
        PublicVar(unsigned int x, unsigned int y, unsigned int count);
        ~PublicVar();
        unsigned int getCount();
        unsigned int x_size = 800;
        unsigned int y_size = 400;

    private:


    };

}

