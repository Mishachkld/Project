//
// Created by Mishach on 19.12.2022.
//

#include "Settings.hpp"


namespace gm {

    Settings::Settings(unsigned int x, unsigned int y, unsigned int count) {
        win_count = count;
        x_size = x;
        y_size = y;
    }


    unsigned int Settings::getCount() {
        return win_count;
    }


    Settings::~Settings() {

    }



} // gm