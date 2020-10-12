#include "stdafx.h"
#include <Hermes.hpp>
#include "HermesData.hpp"
#include "HermesDataWrapper.h"
#include "CLRWrapper2.h"

using namespace System;
using namespace msclr::interop;
using namespace System;

namespace VerticalServiceWrapper {

	public ref class VerticalService {
	private:
		Hermes::VerticalService *verticalService;
	public:
		VerticalService(VerticalServiceSinkWrapper ^data) {
			verticalService = &Hermes::VerticalService::VerticalService(data->toNative());
		}
		template<class F> void Post(F ^f) {
			verticalService->Post(f);
		}
		void Enable(HermesDataWrapper::VerticalServiceSettingsWrapper ^settings) {
			verticalService->Enable(settings->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::SupervisoryServiceDescriptionDataWrapper ^data) {
			verticalService->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::BoardArrivedDataWrapper ^data) {
			verticalService->Signal(sessionId, data->toNative());
		}
		void Signal(HermesDataWrapper::BoardArrivedDataWrapper ^data) {
			verticalService->Signal(data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::BoardDepartedDataWrapper ^data) {
			verticalService->Signal(sessionId, data->toNative());
		}
		void Signal(HermesDataWrapper::BoardDepartedDataWrapper ^data) {
			verticalService->Signal(data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::QueryWorkOrderInfoDataWrapper ^data) {
			verticalService->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::CurrentConfigurationDataWrapper ^data) {
			verticalService->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::NotificationDataWrapper ^data) {
			verticalService->Signal(sessionId, data->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::CheckAliveDataWrapper ^data) {
			verticalService->Signal(sessionId, data->toNative());
		}
		void ResetSession(unsigned sessionId, HermesDataWrapper::NotificationDataWrapper ^data) {
			verticalService->ResetSession(sessionId, data->toNative());
		}
		void Disable(HermesDataWrapper::NotificationDataWrapper ^data) {
			verticalService->Disable(data->toNative());
		}
		void Stop() {
			verticalService->Stop();
		}
	};
}