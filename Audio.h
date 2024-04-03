#ifndef AUDIO_H
#define AUDIO_H

#include <QAudioSource>
#include <QMediaDevices>
#include <QComboBox>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

#include <QPixmap>

#include <QByteArray>
#include <QScopedPointer>
#include<iostream>

#include"AudioOut.h"

class AudioInfo : public QIODevice
{
    Q_OBJECT

public:
    AudioInfo(const QAudioFormat &format);

    void start();
    void stop();

    qreal level() const { return m_level; }

    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;

    qreal calculateLevel(const char *data, qint64 len) const;

signals:
    void levelChanged(qreal level);

private:
    const QAudioFormat m_format;
    qreal m_level = 0.0; // 0.0 <= m_level <= 1.0
};

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);

    void setLevel(qreal value);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    qreal m_level = 0;
};

class InputTest : public QWidget
{
    Q_OBJECT

public:
    InputTest();

private:
    void initializeWindow();
    void initializeAudio(const QAudioDevice &deviceInfo);
    void initializeErrorWindow();

private slots:
    void init();
    void toggleMode();
    void toggleSuspend();
    void deviceChanged(int index);
    void deviceOutputChanged(int index);
    void sliderChanged(int value);

private:
    // Owned by layout
    RenderArea *m_canvas = nullptr;
    QPushButton *m_modeButton = nullptr;
    QPushButton *m_suspendResumeButton = nullptr;
    QComboBox *m_deviceBox = nullptr;
    QComboBox *m_deviceBox2 = nullptr;
    QSlider *m_volumeSlider = nullptr;

    AudioOut *m_audioOutput;
    QMediaDevices *m_devices = nullptr;
    QScopedPointer<AudioInfo> m_audioInfo;
    QScopedPointer<QAudioSource> m_audioInput;
    bool m_pullMode = true;
};







#endif // AUDIO_H
