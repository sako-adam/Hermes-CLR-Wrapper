#include "stdafx.h"
#include "HermesWrapper.h"

HermesWrapper::DownstreamWrapper::DownstreamWrapper(unsigned laneId, Hermes::IDownstreamCallback& callback) {


	downStream = &Hermes::Downstream::Downstream(laneId, callback);  //laneId, callback
}

void HermesWrapper::DownstreamWrapper::Run() {
	downStream->Run();
}

template<class F> void HermesWrapper::DownstreamWrapper::Post(F&& f) {
	downStream->Post(f);
}

void HermesWrapper::DownstreamWrapper::Enable(const Hermes::DownstreamSettings& data) {
	downStream->Enable(data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::ServiceDescriptionData& data) {
	downStream->Signal(sessionId, data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::BoardAvailableData& data) {
	downStream->Signal(sessionId, data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::RevokeBoardAvailableData& data) {
	downStream->Signal(sessionId, data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::TransportFinishedData& data) {
	downStream->Signal(sessionId, data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::BoardForecastData& data) {
	downStream->Signal(sessionId, data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::SendBoardInfoData& data) {
	downStream->Signal(sessionId, data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::NotificationData& data) {
	downStream->Signal(sessionId, data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::CheckAliveData& data) {
	downStream->Signal(sessionId, data);
}


void HermesWrapper::DownstreamWrapper::Reset(const Hermes::NotificationData& data) {
	downStream->Reset(data);
}

void HermesWrapper::DownstreamWrapper::Signal(unsigned sessionId, const Hermes::StringView data) {
	downStream->Signal(sessionId, data);
}
void HermesWrapper::DownstreamWrapper::Reset(const Hermes::StringView data) {
	downStream->Reset(data);
}

void HermesWrapper::DownstreamWrapper::Disable(const Hermes::NotificationData& data) {
	downStream->Disable(data);
}

void HermesWrapper::DownstreamWrapper::Stop() {
	downStream->Stop();
}