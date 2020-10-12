#include "stdafx.h"
#include <Hermes.hpp>
#include "HermesData.hpp";
#include "HermesDataWrapper.h";
#include <msclr/marshal_cppstd.h>
#include <string.h>
#include <type_traits>
#include <vector>

using namespace System;
using namespace msclr::interop;

using namespace System;
namespace SakoHermesWrapper {
	public ref class ConnectionInfoWrapper {
	public:
		String ^m_address;
		uint16_t m_port;
		String ^ m_hostName;
		ConnectionInfoWrapper() {};
	internal:
		Hermes::ConnectionInfo toNative() {
			Hermes::ConnectionInfo conn_info;
			auto copy_m_address = this->m_address;
			auto copy_m_hostName = this->m_address;
			conn_info.m_address = marshal_as<std::string>(copy_m_address);
			conn_info.m_hostName = marshal_as<std::string>(copy_m_hostName);
			conn_info.m_port = m_port;

			return conn_info;
		}
		
		/*ConnectionInfoWrapper(const ConnectionInfo &conn_info) {
			m_address = gcnew String(conn_info.m_address.c_str());
			m_hostName = gcnew String(conn_info.m_hostName.c_str());
			m_port = conn_info.m_port;
		};*/
	};
	struct ConnectionInfo
	{
		std::string m_address;
		uint16_t m_port{ 0 };
		std::string m_hostName;

		ConnectionInfo() = default;
		ConnectionInfo(Hermes::StringView address,
			uint16_t port,
			Hermes::StringView hostName) :
			m_address(address),
			m_port(port),
			m_hostName(hostName)
		{}

		friend bool operator==(const ConnectionInfo& lhs, const ConnectionInfo& rhs)
		{
			return lhs.m_address == rhs.m_address
				&& lhs.m_port == rhs.m_port
				&& lhs.m_hostName == rhs.m_hostName;
		}
		friend bool operator!=(const ConnectionInfo& lhs, const ConnectionInfo& rhs) { return !operator==(lhs, rhs); }

		template <class S> friend S& operator<<(S& s, const ConnectionInfo& data)
		{
			s << '{';
			s << " Address=" << data.m_address;
			s << " Port=" << data.m_port;
			s << " HostName=" << data.m_hostName;
			s << " }";
			return s;
		}
	};
	public enum class EStateWrapper
	{
		eNOT_CONNECTED,
		eSOCKET_CONNECTED,
		eSERVICE_DESCRIPTION_DOWNSTREAM,
		eNOT_AVAILABLE_NOT_READY,
		eBOARD_AVAILABLE,
		eMACHINE_READY,
		eAVAILABLE_AND_READY,
		eTRANSPORTING,
		eTRANSPORT_STOPPED,
		eTRANSPORT_FINISHED,
		eDISCONNECTED

	};
	struct DownstreamSink : Hermes::IDownstreamCallback
	{
		DownstreamSink()=default;
		DownstreamSink(DownstreamSink&);
		unsigned m_sessionId{ 0U };
		Hermes::EState m_state{ Hermes::EState::eNOT_CONNECTED };
		Hermes::ConnectionInfo m_connectionInfo;

		void OnConnected(unsigned sessionId, Hermes::EState state, const Hermes::ConnectionInfo& connectionInfo) override
		{
			//ChangeLock lock(this);
			m_state = state;
			m_sessionId = sessionId;
			m_connectionInfo = connectionInfo;

			/**/
		}
		void On(unsigned sessionId, Hermes::EState state, const Hermes::ServiceDescriptionData& serviceDescription) override
		{
			/*ChangeLock lock(this);
			m_state = state;
			m_sessionId = sessionId;
			m_serviceDescription = serviceDescription;
			*/
		}

		void On(unsigned sessionId, const Hermes::NotificationData& data) override
		{
			/*ChangeLock lock(this);
			m_notificationData = data;
			m_sessionId = sessionId;*/
		}

		void On(unsigned sessionId, const Hermes::CheckAliveData& data) override
		{
			/*ChangeLock lock(this);
			m_checkAliveData = data;
			m_sessionId = sessionId;*/
		}

		void OnState(unsigned sessionId, Hermes::EState state) override
		{
			/*ChangeLock lock(this);
			m_state = state;
			m_sessionId = sessionId;*/
		}

		void OnDisconnected(unsigned sessionId, Hermes::EState state, const Hermes::Error&) override
		{
			/*ChangeLock lock(this);
			m_state = state;
			m_sessionId = sessionId;*/
		}


		void On(unsigned sessionId, Hermes::EState state, const Hermes::MachineReadyData& data) override
		{
			/*ChangeLock lock(this);
			m_state = state;
			m_machineReadyData = data;
			m_sessionId = sessionId;*/
		}

		void On(unsigned sessionId, Hermes::EState state, const Hermes::RevokeMachineReadyData&) override
		{
			/*
			ChangeLock lock(this);
			m_state = state;
			m_sessionId = sessionId;
			*/
		}

		void On(unsigned sessionId, Hermes::EState state, const Hermes::StartTransportData& data) override
		{
			/*ChangeLock lock(this);
			m_state = state;
			m_startTransportData = data;
			m_sessionId = sessionId;*/
		}

		void On(unsigned sessionId, Hermes::EState state, const Hermes::StopTransportData& data) override
		{
			/* ChangeLock lock(this);
			m_state = state;
			m_stopTransportData = data;
			m_sessionId = sessionId;*/
		}

		void On(unsigned sessionId, const Hermes::QueryBoardInfoData& data) override
		{
			/*ChangeLock lock(this);
			m_queryBoardInfoData = data;
			m_sessionId = sessionId;*/
		}

		void OnTrace(unsigned sessionId, Hermes::ETraceType type, Hermes::StringView trace) override
		{
			//TestTrace("DownstreamTrace", type, sessionId, trace);
		}

	};
	DownstreamSink::DownstreamSink(DownstreamSink &obj) {

	}
	public ref class DownstreamSinkWrapper {
	public:
		unsigned m_sessionId{ 0U };
		ConnectionInfoWrapper ^m_connectionInfo;
		EStateWrapper m_state;

		DownstreamSinkWrapper() {
			m_connectionInfo = gcnew ConnectionInfoWrapper();
			//m_state = gcnew EStateWrapper();
			//downstreamSink2 = new DownstreamSink();

		}
	internal:
		DownstreamSink toNative() {
			DownstreamSink downstreamSink;
			downstreamSink.m_sessionId = m_sessionId;
			downstreamSink.m_connectionInfo = m_connectionInfo->toNative();
			downstreamSink.m_state = static_cast<Hermes::EState>(m_state);

			return downstreamSink;
		}

	};
	template<class F> ref class F {
		// Instantiate a generic with a template parameter.
		//R<T>^ r;    // OK
	};
	public ref class Packer {
	private:
		//DownstreamSink* d_sink;
		Hermes::Downstream *downStream;
	public:
		Packer() {
			//d_sink = new DownstreamSink();
		}
		~Packer() {
			//delete d_sink;
		}
		void init(unsigned laneId, DownstreamSinkWrapper^ wrapper) {
			downStream = &Hermes::Downstream::Downstream(laneId, wrapper->toNative());  //laneId, callback
		}
		void test() {

		}
		void run() {
			downStream->Run();
		}
		void Enable(HermesDataWrapper::DownstreamSettingsWrapper ^downstreamSettingsWrapper) {
			downStream->Enable(downstreamSettingsWrapper->toNative());
		}
		template<class F> void Post(F^ f) {
			downStream->Post(f);
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