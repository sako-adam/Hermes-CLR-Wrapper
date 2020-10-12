#include "stdafx.h"
#include <Hermes.hpp>
#include "HermesData.hpp"
#include "HermesDataWrapper.h"
#include "CLRWrapper2.h"

using namespace System;
using namespace msclr::interop;
using namespace System;

namespace VerticalClientWrapper {

	public ref class VerticalClient {
	private:
		Hermes::VerticalClient *verticalClient;
		HermesVerticalClient* m_pImpl = nullptr;
	public:
		VerticalClient(VerticalClientSinkWrapper ^verticalClientSink) {
			verticalClient = &Hermes::VerticalClient::VerticalClient(verticalClientSink->toNative());
		}
		void Run() {
			verticalClient->Run();
		}
		template<class F> void Post(F ^f) {
			verticalClient->Post(f);
		}
		void Enable(HermesDataWrapper::VerticalClientSettingsWrapper ^verticalClientSettings) {
			verticalClient->Enable(verticalClientSettings->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::SupervisoryServiceDescriptionDataWrapper ^data) {
			verticalClient->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::SendWorkOrderInfoDataWrapper ^data) {
			verticalClient->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::GetConfigurationDataWrapper ^data) {
			verticalClient->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::SetConfigurationDataWrapper ^data) {
			verticalClient->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::NotificationDataWrapper ^data) {
			verticalClient->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::CheckAliveDataWrapper ^data) {
			verticalClient->Signal(sessionId, data->toNative());
		}
		void Reset(HermesDataWrapper::NotificationDataWrapper ^data) {
			verticalClient->Reset(data->toNative());
		}
		void Disable(HermesDataWrapper::NotificationDataWrapper ^data) {
			verticalClient->Disable(data->toNative());
		}
		void Stop() {
			verticalClient->Stop();
		}
	};
}