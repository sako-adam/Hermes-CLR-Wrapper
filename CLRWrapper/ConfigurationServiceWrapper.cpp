#include "stdafx.h"
#include "HermesWrapper.h"



HermesWrapper::ConfigurationServiceWrapper::ConfigurationServiceWrapper(Hermes::IConfigurationServiceCallback& callback):m_callback(callback){
	configurationService = &Hermes::ConfigurationService::ConfigurationService(callback);
}

void HermesWrapper::ConfigurationServiceWrapper::Run() {
	configurationService->Run();
}

template<class F> void HermesWrapper::ConfigurationServiceWrapper::Post(F&& f) {
	configurationService->Post(f);
}

void HermesWrapper::ConfigurationServiceWrapper::Enable(const Hermes::ConfigurationServiceSettings& data) {
	configurationService->Enable(data);
}

void HermesWrapper::ConfigurationServiceWrapper::Disable(const Hermes::NotificationData& data) {
	configurationService->Disable(data);
}


void HermesWrapper::ConfigurationServiceWrapper::Stop() {
	configurationService->Stop();
}