#ifndef WEBRTCCLIENT_H
#define WEBRTCCLIENT_H

#include "rtc/rtc.hpp"
#include "TCPServer.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>


using namespace std::chrono_literals;
using std::shared_ptr;
using std::weak_ptr;

class WebRTCClientAnswerer {
private:
    shared_ptr<rtc::PeerConnection> pc;
    shared_ptr<rtc::DataChannel> dc;
    int role;
    TCPServer TCPserver;
    std::string recievedConfig;
    std::string desc;
    std::vector <std::string> cand;

public:
    WebRTCClientAnswerer();
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
    void parseDescription();
    void parseCandidate();
    void sendMessage();
    void printConnectionInfo();
    void setPeerConnectionCallbacks();
    void setDataChannelCallbacks();
};

#endif // WEBRTCCLIENT_H
