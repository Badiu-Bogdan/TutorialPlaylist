#pragma once
//
// Created by badiu on 3/22/2022.
//

#ifndef LAB_5_6_PB_4_REPOSITORY_H
#define LAB_5_6_PB_4_REPOSITORY_H

#include "Tutorial.h"
#include "../../Header/Exception/TutorialValidator.h"
//typedef Tutorial TElem;

template<typename T>
class Repository {
protected:
    string fileName;
    vector<T> elems;

public:
    Repository() = default;

    explicit Repository(const string &new_fileName);

    Repository(const Repository<T> &copy_repository);

    ~Repository();

    void add(T entity);

    void removeElement(int &pos);

    void updateElement(int &pos, T &new_entity);

    T &operator[](int pos);

    auto vector() {
        return this->elems;
    }

    int getSize();

    virtual void readStartUp();

public:
    virtual void writeInFile(T &entity);

    virtual void reWriteFile();

};


template<typename T>
class FileRepository : public Repository<T> {
public:
    explicit FileRepository(const string &newFileName) {
        this->fileName = newFileName;
        readStartUp();
    };
private:
    void readStartUp() override {
        ifstream readFile(this->fileName);
        if (!readFile) {
            //File not opened correctly
        } else {
            //File opened correctly
        }
        while (!readFile.eof()) {
            Tutorial entity;
            try {
                readFile >> entity;
                TutorialValidator::Validate(entity);
                this->elems.push_back(entity);
            }
            catch (InvalidArgument &error) {
                //cout << "1 element not added. Read from file error. ReadFromStartUp  Repository \n";
                //cout << entity;
            }
        }

        readFile.close();
    };

    void writeInFile(T &entity) override {
        ofstream file(this->fileName, ios_base::app);
        if (!file) {
            //file not opened
        } else {
            //file opened
            file << entity;
        }

    };

    void reWriteFile() override {
        ofstream file(this->fileName);
        if (!file) {
            //file not opened
        } else {
            for (auto &i: this->elems)
                file << i;
        }
    };
};

template<typename T>
class HtmlRepository : public Repository<T> {
public:
    explicit HtmlRepository(const string &newFileName) {
        this->fileName = newFileName;
        readStartUp();
    };
private:
    void readStartUp() override {
        ifstream readFile(this->fileName);
        if (!readFile) {
            //File not opened correctly
        } else {
            //File opened correctly
        }
        while (!readFile.eof()) {
            Tutorial entity;
            try {
                readFile >> entity;
                TutorialValidator::Validate(entity);
                this->elems.push_back(entity);
            }
            catch (InvalidArgument &error) {
                //cout << "1 element not added. Read from file error. ReadFromStartUp  Repository \n";
                //cout << entity;
            }
        }

        readFile.close();
    };

    void writeInFile(T &entity) override {
        ofstream file(this->fileName);
        if (!file) {
            //File not opened correctly
        } else {
            file << "<!DOCTYPE html>";
            file << "<html>";
            file << "<head> <title>Playlist</title> </head>";
            file
                    << "<body> <table border=\"1\">  <tr> <td>Title</td> <td>Presenter</td> <td>Duration</td> <td>Likes</td> <td>Youtube link</td>  </tr>";

            for(auto &i: this->elems)
            {
                file << "<tr>";
                file << "<td>";
                file << i.getTitle();
                file << "</td>";
                file << "<td>" ;
                file << i.getPresenter();
                file << "</td>";
                file << "<td>";
                file << i.getMinutes();
                file << ":";
                file << i.getSeconds();
                file << "</td>";
                file << "<td>";
                file << i.getLikes();
                file << "</td>";
                file << "<td><a href = \"";
                file << i.getLink();
                file << "\">Link</a></td>";
                file << "</tr> </table> </body> </html>";
            }
        }
    };

    void reWriteFile() override {
        ofstream file(this->fileName);
        if (!file) {
            //File not opened correctly
        } else {
            file << "<!DOCTYPE html>";
            file << "<html>";
            file << "<head> <title>Playlist</title> </head>";
            file
                    << "<body> <table border=\"1\">  <tr> <td>Title</td> <td>Presenter</td> <td>Duration</td> <td>Likes</td> <td>Youtube link</td>  </tr>";

            for(auto &i: this->elems)
            {
/*                file << "<tr>";
                file << "<td>" + i.getTitle() + "</td>";
                file << "<td>" + i.getPresenter() + "</td>";
                file << "<td>" + i.getMinutes() + ":" + i.getSeconds() + "</td>";
                file << "<td>" + i.getLikes() + "</td>";
                file << "<td><a href = \"" + i.getLink() + "\">Link</a></td>";
                file << "</tr> </table> </body> </html>";*/
                file << "<tr>";
                file << "<td>";
                file << i.getTitle();
                file << "</td>";
                file << "<td>" ;
                file << i.getPresenter();
                file << "</td>";
                file << "<td>";
                file << i.getMinutes();
                file << ":";
                file << i.getSeconds();
                file << "</td>";
                file << "<td>";
                file << i.getLikes();
                file << "</td>";
                file << "<td><a href = \"";
                file << i.getLink();
                file << "\">Link</a></td>";
                file << "</tr> </table> </body> </html>";
            }
        }
    };
};

#include "StlRepository.tpp"

#endif //LAB_5_6_PB_4_REPOSITORY_H
