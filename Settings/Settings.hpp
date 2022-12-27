#ifndef PROJECT_SETTINGS_HPP
#define PROJECT_SETTINGS_HPP

#include <vector>

namespace gm {

    class Settings {
    public:
        Settings(unsigned int x, unsigned int y,  unsigned int count);
        ~Settings();
        unsigned int getCount();
    private:
        unsigned int x_size = 840;
        unsigned int y_size = 480;
        unsigned int win_count = 3;


    };

}

#endif //PROJECT_SETTINGS_HPP
