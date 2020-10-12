#include "stdafx.h"
#include <Hermes.hpp>
#include "HermesData.hpp"
#include "HermesDataWrapper.h"
#include "CLRWrapper2.h"

using namespace System;
using namespace msclr::interop;
using namespace System;
UpstreamSink::UpstreamSink(UpstreamSink &obj) {

}
namespace UpstreamWrapper {
	
	public ref class Upstream {
	private:
		Hermes::Upstream *upStream;
		HermesUpstream* m_pImpl = nullptr;
	public:
		Upstream(unsigned laneId, UpstreamSinkWrapper^ wrapper) {
			HermesUpstreamCallbacks callbacks{};
			m_pImpl = ::CreateHermesUpstream(laneId, &callbacks);
			upStream = &Hermes::Upstream::Upstream(laneId, wrapper->toNative());
		}
		~Upstream() {
			::DeleteHermesUpstream(m_pImpl);
		}
		void run() {
			upStream->Run();
		}
		void Enable(HermesDataWrapper::UpstreamSettingsWrapper ^upStreamSettingsWrapper) {
			upStream->Enable(upStreamSettingsWrapper->toNative());
		}
		template<class F> void Post(F^ f) {
			upStream->Post(f);
		}
		void Signal(unsigned sessionId, HermesDataWrapper::ServiceDescriptionDataWrapper ^serviceDescriptionDataWrapper) {
			upStream->Signal(sessionId, serviceDescriptionDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::MachineReadyDataWrapper ^machineReadyDataWrapper) {
			upStream->Signal(sessionId, machineReadyDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::RevokeMachineReadyDataWarpper ^revokeMachineReadyDataWarpper) {
			upStream->Signal(sessionId, revokeMachineReadyDataWarpper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::StartTransportDataWrapper ^startTransportDataWrapper) {
			upStream->Signal(sessionId, startTransportDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::StopTransportDataWrapper ^stopTransportDataWrapper) {
			upStream->Signal(sessionId, stopTransportDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::QueryBoardInfoDataWrapper ^queryBoardInfoDataWrapper) {
			upStream->Signal(sessionId, queryBoardInfoDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::NotificationDataWrapper ^notificationDataWrapper) {
			upStream->Signal(sessionId, notificationDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, HermesDataWrapper::CheckAliveDataWrapper ^checkAliveDataWrapper) {
			upStream->Signal(sessionId, checkAliveDataWrapper->toNative());
		}
		void Reset(HermesDataWrapper::NotificationDataWrapper ^notificationDataWrapper) {
			upStream->Reset(notificationDataWrapper->toNative());
		}
		void Signal(unsigned sessionId, const Hermes::StringView data) { // to edit
			upStream->Signal(sessionId, data);
		}
		void Reset(const Hermes::StringView data) { // to edit
			upStream->Reset(data);
		}
		void Disable(HermesDataWrapper::NotificationDataWrapper ^notificationDataWrapper) { // to edit
			upStream->Disable(notificationDataWrapper->toNative());
		}
		void Stop() {
			upStream->Stop();
		}
	};

}