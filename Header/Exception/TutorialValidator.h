#pragma once
//
// Created by badiu on 4/12/2022.
//

#ifndef LAB_5_6_PB_4_TUTORIALVALIDATOR_H
#define LAB_5_6_PB_4_TUTORIALVALIDATOR_H

#include "../Model/Tutorial.h"

class TutorialValidator{
public:
    static void Validate(Tutorial& entity){
        if(entity.getTitle().empty())
            throw InvalidArgument("Invalid Argument: Title empty string!");
        if(entity.getPresenter().empty())
            throw InvalidArgument("Invalid Argument: Presenter empty string!");
        if(entity.getLink().empty())
            throw InvalidArgument("Invalid Argument: Link empty string!");
        if(entity.getLikes() < 0)
            throw InvalidArgument("Invalid Argument: Likes negative number!");
        if(entity.getMinutes() == 0 && entity.getSeconds() == 0)
            throw InvalidArgument("Invalid Argument: Tutorial with duration 0!");
        if(entity.getMinutes() < 0)
            throw InvalidArgument("Invalid Argument: Minutes negative number!");
        if(entity.getSeconds() < 0)
            throw InvalidArgument("Invalid Argument: Seconds negative number!");
    };
};

#endif //LAB_5_6_PB_4_TUTORIALVALIDATOR_H
