/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#include "MainMenuModel.h"
#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>

MainMenuModel::MainMenuModel(MainMenuPresenter * presenter) {
    _presenter = presenter;
    loadGrids();
    presenter->refreshGrids(_grids, _gridsCount);
}

MainMenuModel::~MainMenuModel() {
    for (int i = 0; i < _gridsCount; ++i) {
        delete _grids[i];
    }
    delete[] _grids;
}

void getFilesInDirectory(std::vector<std::string> &out, const std::string &directory) {

    DIR *dir;
    class dirent *ent;
    class stat st;

    dir = opendir(directory.c_str());
    while ((ent = readdir(dir)) != NULL) {
        const std::string file_name = ent->d_name;
        const std::string full_file_name = directory + "/" + file_name;

        if (file_name[0] == '.')
            continue;

        if (stat(full_file_name.c_str(), &st) == -1)
            continue;

        const bool is_directory = (st.st_mode & S_IFDIR) != 0;

        if (is_directory)
            continue;

        out.push_back(full_file_name);
    }
    closedir(dir);
}

void MainMenuModel::loadGrids() {
    std::vector<std::string> files;
    getFilesInDirectory(files, "grids");
    _gridsCount = files.size();
    _grids = new GridInfo*[_gridsCount];
    for (int i = 0; i < _gridsCount; ++i) {
        _grids[i] = new GridInfo(files[i].substr(6, files[i].size()).c_str());
    }
}
