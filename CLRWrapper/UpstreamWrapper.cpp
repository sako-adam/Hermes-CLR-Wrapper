#include "stdafx.h"
#include "HermesWrapper.h"

HermesWrapper::UpstreamWrapper::UpstreamWrapper(unsigned laneId, Hermes::IUpstreamCallback& callback) {
	upStream = &Hermes::Upstream::Upstream(laneId, callback);
}

void HermesWrapper::UpstreamWrapper::Run() {
	upStream->Run();
}

void HermesWrapper::UpstreamWrapper::Enable(const Hermes::UpstreamSettings& data) {
	upStream->Enable(data);
}

template<class F> void HermesWrapper::UpstreamWrapper::Post(F&& f) {
	upStream->Post(f);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::ServiceDescriptionData& data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::MachineReadyData& data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::RevokeMachineReadyData& data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::StartTransportData& data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::StopTransportData& data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::QueryBoardInfoData& data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::NotificationData& data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Reset(const Hermes::NotificationData& data) {
	upStream->Reset(data);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::CheckAliveData& data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Signal(unsigned sessionId, const Hermes::StringView data) {
	upStream->Signal(sessionId, data);
}

void HermesWrapper::UpstreamWrapper::Reset(const Hermes::StringView data) {
	upStream->Reset(data);
}

void HermesWrapper::UpstreamWrapper::Disable(const Hermes::NotificationData& data) {
	upStream->Disable(data);
}

void HermesWrapper::UpstreamWrapper::Stop() {
	upStream->Stop();
}