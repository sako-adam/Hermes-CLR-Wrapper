#pragma once
#include "Hermes.h"
#include "Hermes.hpp"

using namespace System;
namespace HermesWrapper {

	//======================= DownstreamWrapper interface =====================================
	ref struct IDownstreamCallbackWrapper;
	public ref class DownstreamWrapper
	{
	public:
		explicit DownstreamWrapper(unsigned laneId, Hermes::IDownstreamCallback&);
		//DownstreamWrapper(const Hermes::Downstream&) = delete;

		void Run();
		template<class F> void Post(F&&);
		void Enable(const Hermes::DownstreamSettings&);

		void Signal(unsigned sessionId, const Hermes::ServiceDescriptionData&);
		void Signal(unsigned sessionId, const Hermes::BoardAvailableData&);
		void Signal(unsigned sessionId, const Hermes::RevokeBoardAvailableData&);
		void Signal(unsigned sessionId, const Hermes::TransportFinishedData&);
		void Signal(unsigned sessionId, const Hermes::BoardForecastData&);
		void Signal(unsigned sessionId, const Hermes::SendBoardInfoData&);
		void Signal(unsigned sessionId, const Hermes::NotificationData&);
		void Signal(unsigned sessionId, const Hermes::CheckAliveData&);
		void Reset(const Hermes::NotificationData&);

		// raw XML for testing
		void Signal(unsigned sessionId, Hermes::StringView rawXml);
		void Reset(Hermes::StringView rawXml);

		void Disable(const Hermes::NotificationData&);
		void Stop();

	private:
		HermesDownstream* m_pImpl = nullptr;
		Hermes::Downstream *downStream;

	};

	/*ref struct IDownstreamCallbackWrapper {
		IDownstreamCallbackWrapper() {}
		Hermes::IDownstreamCallback &callback;

	protected:
		virtual ~IDownstreamCallbackWrapper();

	};*/
	//======================= UpstreamWrapper interface =====================================
	public ref class UpstreamWrapper
	{
	public:
		explicit UpstreamWrapper(unsigned laneId, Hermes::IUpstreamCallback&);
		//UpstreamWrapper(const Hermes::Upstream&) = delete;
		~UpstreamWrapper() { ::DeleteHermesUpstream(m_pImpl); }

		void Run();
		template<class F> void Post(F&&);
		void Enable(const Hermes::UpstreamSettings&);

		void Signal(unsigned sessionId, const Hermes::ServiceDescriptionData&);
		void Signal(unsigned sessionId, const Hermes::MachineReadyData&);
		void Signal(unsigned sessionId, const Hermes::RevokeMachineReadyData&);
		void Signal(unsigned sessionId, const Hermes::StartTransportData&);
		void Signal(unsigned sessionId, const Hermes::StopTransportData&);
		void Signal(unsigned sessionId, const Hermes::QueryBoardInfoData&);
		void Signal(unsigned sessionId, const Hermes::NotificationData&);
		void Signal(unsigned sessionId, const Hermes::CheckAliveData&);
		void Reset(const Hermes::NotificationData&);

		// raw XML for testing
		void Signal(unsigned sessionId, Hermes::StringView rawXml);
		void Reset(Hermes::StringView rawXml);

		void Disable(const Hermes::NotificationData&);
		void Stop();

	private:
		HermesUpstream* m_pImpl = nullptr;
		Hermes::Upstream *upStream;
	};

	//======================= ConfigurationServiceWrapper interface =====================================
	public ref class ConfigurationServiceWrapper
	{
	public:
		explicit ConfigurationServiceWrapper(Hermes::IConfigurationServiceCallback& callback);
		//ConfigurationServiceWrapper(const Hermes::ConfigurationService&) = delete;
		~ConfigurationServiceWrapper() { ::DeleteHermesConfigurationService(m_pImpl); }

		void Run();
		template<class F> void Post(F&&);
		void Enable(const Hermes::ConfigurationServiceSettings&);
		void Disable(const Hermes::NotificationData&);
		void Stop();

	private:
		HermesConfigurationService* m_pImpl = nullptr;
		Hermes::IConfigurationServiceCallback& m_callback;
		Hermes::ConfigurationService *configurationService;
	};

	//======================= VerticalServiceWrapper interface =====================================
	public ref class VerticalServiceWrapper
	{
	public:
		explicit VerticalServiceWrapper(Hermes::IVerticalServiceCallback&);
		//VerticalServiceWrapper(const Hermes::VerticalService&) = delete;
		~VerticalServiceWrapper() { ::DeleteHermesVerticalService(m_pImpl); }

		void Run();
		template<class F> void Post(F&&);
		void Enable(const Hermes::VerticalServiceSettings&);

		void Signal(unsigned sessionId, const Hermes::SupervisoryServiceDescriptionData&);
		void Signal(unsigned sessionId, const Hermes::BoardArrivedData&); // only to a specific client
		void Signal(const Hermes::BoardArrivedData&); // to all clients that have specified FeatureBoardTracking
		void Signal(unsigned sessionId, const Hermes::BoardDepartedData&); // only to a specific client
		void Signal(const Hermes::BoardDepartedData&); // to all clients that have specified FeatureBoardTracking
		void Signal(unsigned sessionId, const Hermes::QueryWorkOrderInfoData&);
		void Signal(unsigned sessionId, const Hermes::CurrentConfigurationData&);
		void Signal(unsigned sessionId, const Hermes::NotificationData&);
		void Signal(unsigned sessionId, const Hermes::CheckAliveData&);
		void ResetSession(unsigned sessionId, const Hermes::NotificationData&);

		void Disable(const Hermes::NotificationData&);
		void Stop();

	private:
		HermesVerticalService* m_pImpl = nullptr;
		Hermes::VerticalService *verticalService;
	};

	//======================= VerticalClientWrapper interface =====================================
	public ref class VerticalClientWrapper
	{
	public:
		explicit VerticalClientWrapper(Hermes::IVerticalClientCallback&);
		//VerticalClientWrapper(const Hermes::VerticalClient&) = delete;
		~VerticalClientWrapper() { ::DeleteHermesVerticalClient(m_pImpl); }

		void Run();
		template<class F> void Post(F&&);
		void Enable(const Hermes::VerticalClientSettings&);

		void Signal(unsigned sessionId, const Hermes::SupervisoryServiceDescriptionData&);
		void Signal(unsigned sessionId, const Hermes::GetConfigurationData&);
		void Signal(unsigned sessionId, const Hermes::SetConfigurationData&);
		void Signal(unsigned sessionId, const Hermes::SendWorkOrderInfoData&);
		void Signal(unsigned sessionId, const Hermes::NotificationData&);
		void Signal(unsigned sessionId, const Hermes::CheckAliveData&);
		void Reset(const Hermes::NotificationData&);

		// raw XML for testing
		void Signal(unsigned sessionId, Hermes::StringView rawXml);
		void Reset(Hermes::StringView rawXml);

		void Disable(const Hermes::NotificationData&);
		void Stop();

	private:
		HermesVerticalClient* m_pImpl = nullptr;
		Hermes::VerticalClient *verticalClient;
	};

}