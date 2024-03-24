#include <QAudioInput>
#include <QFile>
#include <QCoreApplication>
#include<string>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QFile outputFile("output.wav");
    // if (!outputFile.open(QIODevice::WriteOnly QIODevice::Truncate)) {
    //     qWarning() << "Could not open output file";
    //     return 1;
    // }

    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, try to use nearest";
        format = info.nearestFormat(format);
    }

    QAudioInput audioInput(info, format);
    audioInput.start(&outputFile);

    qDebug() << "Recording audio... Press Ctrl+C to stop.";
    return app.exec();
}

