#include "stdafx.h"
#include "HermesWrapper.h"

HermesWrapper::VerticalClientWrapper::VerticalClientWrapper(Hermes::IVerticalClientCallback& callback) {
	verticalClient = &Hermes::VerticalClient::VerticalClient(callback);
}

void HermesWrapper::VerticalClientWrapper::Run() {
	verticalClient->Run();
}

template<class F> void HermesWrapper::VerticalClientWrapper::Post(F&& f) {
	verticalClient->Post(f);
}

void HermesWrapper::VerticalClientWrapper::Enable(const Hermes::VerticalClientSettings& data) {
	verticalClient->Enable(data);
}

void HermesWrapper::VerticalClientWrapper::Signal(unsigned sessionId, const Hermes::SupervisoryServiceDescriptionData& data) {
	verticalClient->Signal(sessionId, data);
}

void HermesWrapper::VerticalClientWrapper::Signal(unsigned sessionId, const Hermes::SendWorkOrderInfoData& data) {
	verticalClient->Signal(sessionId, data);
}

void HermesWrapper::VerticalClientWrapper::Signal(unsigned sessionId, const Hermes::GetConfigurationData& data) {
	verticalClient->Signal(sessionId, data);
}

void HermesWrapper::VerticalClientWrapper::Signal(unsigned sessionId, const Hermes::SetConfigurationData& data) {
	verticalClient->Signal(sessionId, data);
}

void HermesWrapper::VerticalClientWrapper::Signal(unsigned sessionId, const Hermes::NotificationData& data) {
	verticalClient->Signal(sessionId, data);
}

void HermesWrapper::VerticalClientWrapper::Signal(unsigned sessionId, const Hermes::CheckAliveData& data) {
	verticalClient->Signal(sessionId, data);
}

void HermesWrapper::VerticalClientWrapper::Reset(const Hermes::NotificationData& data) {
	verticalClient->Reset(data);
}

void HermesWrapper::VerticalClientWrapper::Signal(unsigned sessionId, Hermes::StringView rawXm) {
	//verticalClient->Signal(sessionId, rawXm);
}

void HermesWrapper::VerticalClientWrapper::Reset(Hermes::StringView rawXml) {
	//verticalClient->Reset(rawXml);
}

void HermesWrapper::VerticalClientWrapper::Disable(const Hermes::NotificationData& data) {
	verticalClient->Disable(data);
}

void HermesWrapper::VerticalClientWrapper::Stop() {
	verticalClient->Stop();
}
