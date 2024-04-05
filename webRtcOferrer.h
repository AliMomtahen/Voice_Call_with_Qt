#ifndef WEBRTCOFERRER_H
#define WEBRTCOFERRER_H

#include "rtc/rtc.hpp"
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include "TCPClient.h"
#include"AudioOut.h"

using namespace std::chrono_literals;
using std::shared_ptr;
using std::weak_ptr;


class WebRTCClientOferrer {
private:
    shared_ptr<rtc::PeerConnection> pc;
    shared_ptr<rtc::DataChannel> dc;
    int role;
    std::string desc;
    std::vector <std::string> cand;
    AudioOut *ao;

public:
    WebRTCClientOferrer();
    void start();
    void close();

private:
    void initializePeerConnection();
    int chooseRole();
    void initializeDataChannel();
    void onDataChannel();
    void handleCommands();
    void printMenu();
    int getCommand();
    void executeCommand(int command, bool& exit);
    void parseDescription(std::string descript);
    void parseCandidate(std::string candid);
    void sendMessage();
    void printConnectionInfo();
    void setPeerConnectionCallbacks();
    void setDataChannelCallbacks();
    void setAudioOut(AudioOut *_ao);
};

#endif // WEBRTCOFERRER_H
