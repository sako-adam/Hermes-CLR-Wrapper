#include "stdafx.h"
#include <Hermes.hpp>
#include "HermesData.hpp"
#include "HermesDataWrapper.h"
#include "CLRWrapper2.h"

using namespace System;
using namespace msclr::interop;
using namespace System;

/*DownstreamSink::DownstreamSink(DownstreamSink &obj) {

}*/
namespace DownstreamWrapper {
	public ref class Downstream {
	private:
		//DownstreamSink* d_sink;
		Hermes::Downstream *downStream;
	public:
		Downstream(unsigned laneId, DownstreamSinkWrapper^ wrapper) {
			downStream = &Hermes::Downstream::Downstream(laneId, wrapper->toNative());

		}
		~Downstream() {
			//delete d_sink;
		}
		void init(unsigned laneId, DownstreamSinkWrapper^ wrapper) {
			//downStream = &Hermes::Downstream::Downstream(laneId, wrapper->toNative());  //laneId, callback
		}
		template<class F> void Post(F ^f) {
			downStream->Post(f);
		}
		void run() {
			downStream->Run();
		}
		void Enable(HermesDataWrapper::DownstreamSettingsWrapper ^downstreamSettingsWrapper) {
			downStream->Enable(downstreamSettingsWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::ServiceDescriptionDataWrapper ^serviceDescriptionDataWrapper) {
			downStream->Signal(sessionId, serviceDescriptionDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::BoardAvailableDataWrapper ^boardAvailableDataWrapper) {
			downStream->Signal(sessionId, boardAvailableDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::RevokeBoardAvailableDataWrapper ^revokeBoardAvailableDataWrapper) {
			downStream->Signal(sessionId, revokeBoardAvailableDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::TransportFinishedDataWrapper ^transportFinishedDataWrapper) {
			downStream->Signal(sessionId, transportFinishedDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::BoardForecastDataWrapper ^boardForecastDataWrapper) {
			downStream->Signal(sessionId, boardForecastDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::SendBoardInfoDataWrapper ^sendBoardInfoDataWrapper) {
			downStream->Signal(sessionId, sendBoardInfoDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::NotificationDataWrapper ^notificationDataWrapper) {
			downStream->Signal(sessionId, notificationDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::CheckAliveDataWrapper ^checkAliveDataWrapper) {
			downStream->Signal(sessionId, checkAliveDataWrapper->toNative());
		}
		void Reset(HermesDataWrapper::NotificationDataWrapper ^notificationDataWrapper) {
			downStream->Reset(notificationDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, const Hermes::StringView data) { // to edit
			downStream->Signal(sessionId, data);
		}
		void Reset(const Hermes::StringView data) { // to edit
			downStream->Reset(data);
		}
		void Disable(HermesDataWrapper::NotificationDataWrapper ^notificationDataWrapper) { // to edit
			downStream->Disable(notificationDataWrapper->toNative());
		}
		void Stop() {
			downStream->Stop();
		}

	};
}