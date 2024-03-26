#include <QAudioInput>
#include <QFile>
#include <QCoreApplication>
#include <QApplication>
#include<QAudioFormat>
#include<QAudioDevice>
#include<QMediaDevices>

#include<string>
#include"Audio.h"

int main(int argv, char **args)
{
    QApplication app(argv, args);
    QCoreApplication::setApplicationName("Audio Source Test");

    InputTest input;
    input.show();

    return QCoreApplication::exec();
}

