#include "stdafx.h"
#include "HermesWrapper.h"

HermesWrapper::VerticalServiceWrapper::VerticalServiceWrapper(Hermes::IVerticalServiceCallback& callback) {
	verticalService = &Hermes::VerticalService::VerticalService(callback);
}

void HermesWrapper::VerticalServiceWrapper::Run() {
	verticalService->Run();
}

template<class F> void HermesWrapper::VerticalServiceWrapper::Post(F&& f) {
	verticalService->Post(f);
}

void HermesWrapper::VerticalServiceWrapper::Enable(const Hermes::VerticalServiceSettings& settings) {
	verticalService->Enable(settings);
}

void HermesWrapper::VerticalServiceWrapper::Signal(unsigned sessionId, const Hermes::SupervisoryServiceDescriptionData& data) {
	verticalService->Signal(sessionId, data);
}

void HermesWrapper::VerticalServiceWrapper::Signal(unsigned sessionId, const Hermes::BoardArrivedData& data) {
	verticalService->Signal(sessionId, data);
}

void HermesWrapper::VerticalServiceWrapper::Signal(const Hermes::BoardArrivedData& data) {
	verticalService->Signal(data);
}


void HermesWrapper::VerticalServiceWrapper::Signal(unsigned sessionId, const Hermes::BoardDepartedData& data) {
	verticalService->Signal(sessionId, data);
}

void HermesWrapper::VerticalServiceWrapper::Signal(const Hermes::BoardDepartedData& data) {
	verticalService->Signal(data);
}

void HermesWrapper::VerticalServiceWrapper::Signal(unsigned sessionId, const Hermes::QueryWorkOrderInfoData& data) {
	verticalService->Signal(sessionId, data);
}

void HermesWrapper::VerticalServiceWrapper::Signal(unsigned sessionId, const Hermes::CurrentConfigurationData& data) {
	verticalService->Signal(sessionId, data);
}

void HermesWrapper::VerticalServiceWrapper::Signal(unsigned sessionId, const Hermes::NotificationData& data) {
	verticalService->Signal(sessionId, data);
}

void HermesWrapper::VerticalServiceWrapper::Signal(unsigned sessionId, const Hermes::CheckAliveData& data) {
	verticalService->Signal(sessionId, data);
}

void HermesWrapper::VerticalServiceWrapper::ResetSession(unsigned sessionId, const Hermes::NotificationData& data) {
	verticalService->ResetSession(sessionId, data);
}

void HermesWrapper::VerticalServiceWrapper::Disable(const Hermes::NotificationData& data) {
	verticalService->Disable(data);
}

void HermesWrapper::VerticalServiceWrapper::Stop() {
	verticalService->Stop();
}