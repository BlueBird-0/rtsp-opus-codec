#include "utils.h"
#include "ClientSession.h"

ClientSession::ClientSession(const std::pair<int, std::string>& newClient) {
    info->id = (int)utils::GetRanNum(16);
    info->version = info->id;
    info->tcpSocket = newClient.first;
    info->ip = newClient.second;
    info->state = "INIT";

    info->rtpPort = -1;
    info->rtcpPort = -1;

    requestHandler = new RequestHandler(info);
    udpHandler = new UDPHandler(info);
    
}

int ClientSession::GetSessionId() const { return info->id; }

int ClientSession::GetVersion() const { return info->version; }

std::string ClientSession::GetState() const { return info->state; }

std::pair<int, int> ClientSession::GetPort() const {
    return { info->rtpPort, info->rtcpPort };
}

void ClientSession::SetState(const std::string& newState) {
    // std::lock_guard<std::mutex> lock(mtx);
    info->state = newState;
    info->version++;
}