#pragma once
//
// Created by badiu on 3/22/2022.
//

#ifndef LAB_5_6_PB_4_TUTORIAL_H
#define LAB_5_6_PB_4_TUTORIAL_H
#include <string>
#include <iostream>
#include <new>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "../../Header/Exception/CustomException.h"

using namespace std;

class Tutorial {
private:
    string title;
    string presenter;
    int minutes{}, seconds{};
    int likes{};
    string link;


public:
    Tutorial();
    Tutorial(const string &new_title,const string &new_presenter,const int &new_minutes,const int &new_seconds,const string &new_link);

    string getTitle(){return title;};
    void setTitle(string new_title);

    string getPresenter(){return presenter;};
    void setPresenter(string new_presenter);

    int getMinutes(){return minutes;};
    void setMinutes(int new_minutes);

    int getSeconds(){return seconds;};
    inline void setSeconds(int new_seconds){seconds = new_seconds;};

    int getLikes(){return likes;};
    void like(){likes++;};
    void dislike(){likes--;};
    inline void setLikes(int &new_likes){likes = new_likes;};

    string getLink(){return link;};
    inline void setLink(string new_link){link = new_link;};
    friend ostream& operator<<(ostream& os, const Tutorial& entity);
    friend istream& operator>>(istream& is, Tutorial& entity);
    bool operator== (const Tutorial& entity) const;
};


#endif //LAB_5_6_PB_4_TUTORIAL_H
