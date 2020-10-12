#include "stdafx.h"
#include <Hermes.hpp>
#include "HermesData.hpp"
#include "HermesDataWrapper.h"
#include "CLRWrapper2.h"

using namespace System;
using namespace msclr::interop;
using namespace System;

namespace ConfigurationServiceWrapper {
	public ref class ConfigurationService {
	private:
		//DownstreamSink* d_sink;
		Hermes::ConfigurationService *configurationService;
	public:
		ConfigurationService(ConfigurationProviderWrapper ^configurationProviderWrapper) {
			configurationService = &Hermes::ConfigurationService::ConfigurationService(configurationProviderWrapper->toNative());
		}
		~ConfigurationService() {
			//delete d_sink;
		}
		void Run() {
			configurationService->Run();
		}
		template<class F> void Post(F&& f) {
			configurationService->Post(f);
		}
		void Enable(HermesDataWrapper::ConfigurationServiceSettingsWrapper ^configurationServiceSettings) {
			configurationService->Enable(configurationServiceSettings->toNative());
		}
		void Disable(HermesDataWrapper::NotificationDataWrapper ^data) {
			configurationService->Disable(data->toNative());
		}
		void Stop() {
			configurationService->Stop();
		}

	};
}