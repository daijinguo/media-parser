#pragma once

#ifndef _INCLUDE_MP4_DISPLAY_HPP
#define _INCLUDE_MP4_DISPLAY_HPP

#include <QTreeWidget>
#include <QTextEdit>
#include <QtGlobal>


#include "basic/filereader.hpp"

using namespace media;

class BasicBox;
class MP4Parser;

class MP4Display
{
public:
    MP4Display();

public:
    void display(QTreeWidget* tree, QTextEdit* edit, MP4Parser* parser);

private:
    void showBox(QTreeWidgetItem* item, BasicBox* box);
};



#endif//_INCLUDE_MP4_DISPLAY_HPP

