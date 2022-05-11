//
// Created by badiu on 3/22/2022.
//

#include "../../Header/Model/Tutorial.h"

Tutorial::Tutorial(const string &new_title, const string &new_presenter, const int &new_minutes, const int &new_seconds,
                   const string &new_link)
        : title(new_title), presenter(new_presenter), minutes(new_minutes), seconds(new_seconds), link(new_link),
          likes(0) {

}

void Tutorial::setTitle(string new_title) {
    this->title = new_title;
}

void Tutorial::setPresenter(string new_presenter) {
    presenter = new_presenter;
}

void Tutorial::setMinutes(int new_minutes) {
    minutes = new_minutes;
}

ostream &operator<<(ostream &os, const Tutorial &entity) {
    os << entity.title << "," << entity.presenter << "," << entity.minutes << "," << entity.seconds << ","
       << entity.likes << "," << entity.link << endl;

    return os;
}

Tutorial::Tutorial() {

}

bool Tutorial::operator==(const Tutorial &entity) const {
    if (minutes != entity.minutes)
        return false;
    if (seconds != entity.seconds)
        return false;
    if (title != entity.title)
        return false;
    if (presenter != entity.presenter)
        return false;
    if (link != entity.link)
        return false;
    if (likes != entity.likes)
        return false;
    return true;
}

istream &operator>>(istream &is, Tutorial &entity) {
    string line;
    //is >> line;
    getline(is, line);
    if(line.empty())
        throw InvalidArgument("Empty line. >> operator in Tutorial");
    stringstream ss(line);
    string title, presenter, minutes, seconds, likes, link;
    getline(ss, title, ',');
    getline(ss, presenter, ',');
    getline(ss, minutes, ',');
    getline(ss, seconds, ',');
    getline(ss, likes, ',');
    getline(ss, link, ',');

    entity.title = title;
    entity.presenter = presenter;
    try {
        entity.minutes = stoi(minutes);
    }
    catch (std::invalid_argument &error) {
        entity.minutes = 0;
    }
    try {
        entity.seconds = stoi(seconds);
    }
    catch (std::invalid_argument &error) {
        entity.seconds = 0;
    }
    try {
        entity.likes = stoi(likes);
    }
    catch (std::invalid_argument &error) {
        entity.likes = 0;
    }
    entity.link = link;

    return is;
}


