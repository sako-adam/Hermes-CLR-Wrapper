// CLRWrapper2.h

#pragma once
#include <Hermes.hpp>
#include "HermesData.hpp";
#include "HermesDataWrapper.h";
#include <msclr/marshal_cppstd.h>
#include <string.h>
#include <type_traits>
#include <vector>
#include "HermesDataWrapper.h"
#include <iostream>
//#include <mutex>
#include <sstream>
#include <map>

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
	DownstreamSink() = default;
	DownstreamSink(DownstreamSink&) {
	};
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


////////////////////////////////// Upstream data ////////////////////////
struct UpstreamSink : Hermes::IUpstreamCallback
{
	UpstreamSink() = default;
	UpstreamSink(UpstreamSink&);
	//Mutex m_mutex;
	//Cv m_cv;
	//using ChangeLock = ::ChangeLock<UpstreamSink>;
	unsigned m_sessionId{ 0U };
	Hermes::EState m_state{ Hermes::EState::eNOT_CONNECTED };
	Hermes::ConnectionInfo m_connectionInfo;
	Hermes::ServiceDescriptionData m_serviceDescription;
	Hermes::BoardAvailableData m_boardAvailableData;
	Hermes::TransportFinishedData m_transportFinishedData;
	Hermes::BoardForecastData m_boardForecastData;
	Hermes::SendBoardInfoData m_sendBoardInfoData;
	Hermes::NotificationData m_notificationData;
	Hermes::CheckAliveData m_checkAliveData;

	void OnConnected(unsigned sessionId, Hermes::EState state, const Hermes::ConnectionInfo& connectionInfo) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_connectionInfo = connectionInfo;
	}

	void On(unsigned sessionId, Hermes::EState state, const Hermes::ServiceDescriptionData& serviceDescription) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_serviceDescription = serviceDescription;
	}

	void On(unsigned sessionId, const Hermes::NotificationData& data) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_notificationData = data;
	}

	void On(unsigned sessionId, const Hermes::CheckAliveData& data) override
	{
		//ChangeLock lock(this);
		m_checkAliveData = data;
		m_sessionId = sessionId;
	}

	void OnState(unsigned sessionId, Hermes::EState state) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
	}

	void OnDisconnected(unsigned sessionId, Hermes::EState state, const Hermes::Error&) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
	}


	void On(unsigned sessionId, Hermes::EState state, const Hermes::BoardAvailableData& data) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_boardAvailableData = data;
	}

	void On(unsigned sessionId, Hermes::EState state, const Hermes::RevokeBoardAvailableData&) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
	}

	void On(unsigned sessionId, Hermes::EState state, const Hermes::TransportFinishedData& data) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_transportFinishedData = data;
	}

	void On(unsigned sessionId, Hermes::EState state, const Hermes::BoardForecastData& data) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_boardForecastData = data;
	}

	void On(unsigned sessionId, const Hermes::SendBoardInfoData& data) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_sendBoardInfoData = data;
	}

	void OnTrace(unsigned sessionId, Hermes::ETraceType type, Hermes::StringView trace) override
	{
		//TestTrace("UpstreamTrace", type, sessionId, trace);
	}

};
public ref class UpstreamSinkWrapper
{
public:
	//Mutex m_mutex;
	//Cv m_cv;
	//using ChangeLock = ::ChangeLock<UpstreamSink>;
	unsigned m_sessionId{ 0U };
	EStateWrapper m_state{ EStateWrapper::eNOT_CONNECTED };
	HermesDataWrapper::ConnectionInfoWrapper ^m_connectionInfo = gcnew HermesDataWrapper::ConnectionInfoWrapper();;
	HermesDataWrapper::ServiceDescriptionDataWrapper ^m_serviceDescription = gcnew HermesDataWrapper::ServiceDescriptionDataWrapper();;
	HermesDataWrapper::BoardAvailableDataWrapper ^m_boardAvailableData = gcnew HermesDataWrapper::BoardAvailableDataWrapper();
	HermesDataWrapper::TransportFinishedDataWrapper ^m_transportFinishedData = gcnew HermesDataWrapper::TransportFinishedDataWrapper();
	HermesDataWrapper::BoardForecastDataWrapper ^m_boardForecastData = gcnew HermesDataWrapper::BoardForecastDataWrapper();
	HermesDataWrapper::SendBoardInfoDataWrapper ^m_sendBoardInfoData = gcnew HermesDataWrapper::SendBoardInfoDataWrapper();
	HermesDataWrapper::NotificationDataWrapper ^m_notificationData = gcnew HermesDataWrapper::NotificationDataWrapper();
	HermesDataWrapper::CheckAliveDataWrapper ^m_checkAliveData = gcnew HermesDataWrapper::CheckAliveDataWrapper();

	void OnConnected(unsigned sessionId, EStateWrapper state, HermesDataWrapper::ConnectionInfoWrapper ^connectionInfo)
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_connectionInfo = connectionInfo;
	}

	void On(unsigned sessionId, EStateWrapper state,  HermesDataWrapper::ServiceDescriptionDataWrapper ^serviceDescription)
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_serviceDescription = serviceDescription;
	}

	void On(unsigned sessionId,  HermesDataWrapper::NotificationDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_notificationData = data;
	}

	void On(unsigned sessionId,  HermesDataWrapper::CheckAliveDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_checkAliveData = data;
		m_sessionId = sessionId;
	}

	void OnState(unsigned sessionId, EStateWrapper state) 
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
	}

	void OnDisconnected(unsigned sessionId, EStateWrapper state, Hermes::Error&) 
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
	}


	void On(unsigned sessionId, EStateWrapper state, HermesDataWrapper::BoardAvailableDataWrapper ^data) 
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_boardAvailableData = data;
	}

	void On(unsigned sessionId, EStateWrapper state, Hermes::RevokeBoardAvailableData&) 
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
	}

	void On(unsigned sessionId, EStateWrapper state, HermesDataWrapper::TransportFinishedDataWrapper ^data) 
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_transportFinishedData = data;
	}

	void On(unsigned sessionId, EStateWrapper state, HermesDataWrapper::BoardForecastDataWrapper ^data) 
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_boardForecastData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::SendBoardInfoDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_sendBoardInfoData = data;
	}

	/*void OnTrace(unsigned sessionId, ETraceType type, StringView trace) override
	{
		TestTrace("UpstreamTrace", type, sessionId, trace);
	}*/

internal:
	UpstreamSink toNative() {
		UpstreamSink upstreamSink;

		upstreamSink.m_boardAvailableData = this->m_boardAvailableData->toNative();
		upstreamSink.m_boardForecastData = this->m_boardForecastData->toNative();
		upstreamSink.m_checkAliveData = this->m_checkAliveData->toNative();
		upstreamSink.m_connectionInfo = this->m_connectionInfo->toNative();
		upstreamSink.m_notificationData = this->m_notificationData->toNative();
		upstreamSink.m_sendBoardInfoData = this->m_sendBoardInfoData->toNative();
		upstreamSink.m_serviceDescription = this->m_serviceDescription->toNative();
		upstreamSink.m_sessionId = this->m_sessionId;
		upstreamSink.m_state = static_cast<Hermes::EState>(this->m_state);

		return upstreamSink;

	}

};
//////////////////////////////////////////// ConfigurationService data /////////////////////////
struct ConfigurationProvider : Hermes::IConfigurationServiceCallback
{
	ConfigurationProvider() = default;
	ConfigurationProvider(ConfigurationProvider&) {

	}
	Hermes::CurrentConfigurationData m_currentConfiguration;
	Hermes::ConnectionInfo m_info;
	unsigned m_sessionId = 0U;
	Hermes::ConnectionInfo m_connectionInfo;
	Hermes::ConfigurationService m_service{ *this };

	void OnConnected(unsigned sessionId, const Hermes::ConnectionInfo& info) override
	{
		m_sessionId = sessionId;
		m_connectionInfo = info;
	}

	Hermes::Error OnSetConfiguration(unsigned sessionId, const Hermes::ConnectionInfo& info, const Hermes::SetConfigurationData& configuration) override
	{
		std::ostringstream oss;
		oss << "Configuration::OnSetConfiguration(" << sessionId << ',' << configuration << ',' << info << ')';

		m_currentConfiguration.m_optionalMachineId = configuration.m_machineId;
		m_currentConfiguration.m_downstreamConfigurations = configuration.m_downstreamConfigurations;
		m_currentConfiguration.m_upstreamConfigurations = configuration.m_upstreamConfigurations;
		m_info = info;
		return{};
	}

	Hermes::CurrentConfigurationData OnGetConfiguration(unsigned sessionId, const Hermes::ConnectionInfo& info) override
	{
		std::ostringstream oss;
		oss << "Configuration::OnGetConfiguration(" << sessionId << ',' << info << "), m_currentConfiguration=" << m_currentConfiguration;
		return m_currentConfiguration;
	}

	void OnDisconnected(unsigned sessionId, const Hermes::Error& error) override
	{
	}

	void OnTrace(unsigned sessionId, Hermes::ETraceType type, Hermes::StringView trace) override
	{
	}
};


public ref class ConfigurationProviderWrapper {
public:
	HermesDataWrapper::CurrentConfigurationDataWrapper ^m_currentConfiguration;
	HermesDataWrapper::ConnectionInfoWrapper ^m_info;
	unsigned m_sessionId = 0U;
	HermesDataWrapper::ConnectionInfoWrapper ^m_connectionInfo;
	//Hermes::ConfigurationService m_service{ *this };

	void OnConnected(unsigned sessionId, HermesDataWrapper::ConnectionInfoWrapper ^info)
	{
		m_sessionId = sessionId;
		m_connectionInfo = info;
	}

	Hermes::Error OnSetConfiguration(unsigned sessionId, HermesDataWrapper::ConnectionInfoWrapper ^info, HermesDataWrapper::SetConfigurationDataWrapper ^configuration)
	{
		std::ostringstream oss;
		oss << "Configuration::OnSetConfiguration(" << sessionId << ',' /*<< configuration << ',' << info*/ << ')';

		//m_currentConfiguration->m_optionalMachineId = configuration.m_machineId;
		m_currentConfiguration->m_downstreamConfigurations = configuration->m_downstreamConfigurations;
		m_currentConfiguration->m_upstreamConfigurations = configuration->m_upstreamConfigurations;
		m_info = info;
		return{};
	}

	HermesDataWrapper::CurrentConfigurationDataWrapper^ OnGetConfiguration(unsigned sessionId, HermesDataWrapper::ConnectionInfoWrapper ^info)
	{
		std::ostringstream oss;
		oss << "Configuration::OnGetConfiguration(" << sessionId << ',' << /*info <<*/ "), m_currentConfiguration=" /*<< m_currentConfiguration*/;
		return m_currentConfiguration;
	}

	void OnDisconnected(unsigned sessionId, const Hermes::Error& error)
	{
	}

internal:
	ConfigurationProvider toNative() {
		ConfigurationProvider configurationProvider;

		configurationProvider.m_currentConfiguration = this->m_currentConfiguration->toNative();
		configurationProvider.m_connectionInfo = this->m_connectionInfo->toNative();
		configurationProvider.m_info = this->m_info->toNative();
		configurationProvider.m_sessionId = this->m_sessionId;

		return configurationProvider;
	}


};

////////////////////////////////////////////// Vertical client Data //////////////////
public enum class EVerticalStateWrapper
{
	eNOT_CONNECTED,
	eSOCKET_CONNECTED,
	eSUPERVISORY_SERVICE_DESCRIPTION,
	eCONNECTED,
	eDISCONNECTED
};
struct VerticalClientSink : Hermes::IVerticalClientCallback
{
	VerticalClientSink() = default;
	VerticalClientSink(VerticalClientSink&) {

	};
	/*Mutex m_mutex;
	Cv m_cv;
	using ChangeLock = ::ChangeLock<VerticalClientSink>;
	*/
	unsigned m_sessionId{ 0U };
	Hermes::EVerticalState m_state{ Hermes::EVerticalState::eNOT_CONNECTED };
	Hermes::ConnectionInfo m_connectionInfo;
	Hermes::SupervisoryServiceDescriptionData m_serviceDescription;
	Hermes::CurrentConfigurationData m_currentConfigurationData;
	Hermes::BoardArrivedData m_boardArrivedData;
	Hermes::BoardDepartedData m_boardDepartedData;
	Hermes::QueryWorkOrderInfoData m_queryWorkOrderInfoData;
	Hermes::NotificationData m_notificationData;
	Hermes::CheckAliveData m_checkAliveData;

	void OnConnected(unsigned sessionId, Hermes::EVerticalState state, const Hermes::ConnectionInfo& connectionInfo) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_connectionInfo = connectionInfo;
	}

	void On(unsigned sessionId, Hermes::EVerticalState state, const Hermes::SupervisoryServiceDescriptionData& serviceDescription) override
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_serviceDescription = serviceDescription;
	}

	void On(unsigned sessionId, const Hermes::CurrentConfigurationData& data) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_currentConfigurationData = data;
	}

	void On(unsigned sessionId, const Hermes::BoardArrivedData& data) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_boardArrivedData = data;
	}

	void On(unsigned sessionId, const Hermes::BoardDepartedData& data) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_boardDepartedData = data;
	}

	void On(unsigned sessionId, const Hermes::QueryWorkOrderInfoData& data) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_queryWorkOrderInfoData = data;
	}

	void On(unsigned sessionId, const Hermes::NotificationData& data) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_notificationData = data;
	}

	void On(unsigned sessionId, const Hermes::CheckAliveData& data) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_checkAliveData = data;
	}

	void OnDisconnected(unsigned sessionId, Hermes::EVerticalState state, const Hermes::Error&) override
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_state = state;
	}


	void OnTrace(unsigned sessionId, Hermes::ETraceType type, Hermes::StringView trace) override
	{
		//TestTrace("VerticalClientTrace", type, sessionId, trace);
	}

};

public ref class VerticalClientSinkWrapper {
public:
	unsigned m_sessionId{ 0U };
	EVerticalStateWrapper m_state{ EVerticalStateWrapper::eNOT_CONNECTED };
	HermesDataWrapper::ConnectionInfoWrapper ^m_connectionInfo;
	HermesDataWrapper::SupervisoryServiceDescriptionDataWrapper ^m_serviceDescription;
	HermesDataWrapper::CurrentConfigurationDataWrapper ^m_currentConfigurationData;
	HermesDataWrapper::BoardArrivedDataWrapper ^m_boardArrivedData;
	HermesDataWrapper::BoardDepartedDataWrapper ^m_boardDepartedData;
	HermesDataWrapper::QueryWorkOrderInfoDataWrapper ^m_queryWorkOrderInfoData;
	HermesDataWrapper::NotificationDataWrapper ^m_notificationData;
	HermesDataWrapper::CheckAliveDataWrapper ^m_checkAliveData;

	void OnConnected(unsigned sessionId, EVerticalStateWrapper state, HermesDataWrapper::ConnectionInfoWrapper ^connectionInfo) 
	{

		m_state = state;
		m_sessionId = sessionId;
		m_connectionInfo = connectionInfo;
	}

	void On(unsigned sessionId, EVerticalStateWrapper state, HermesDataWrapper::SupervisoryServiceDescriptionDataWrapper ^serviceDescription) 
	{
		//ChangeLock lock(this);
		m_state = state;
		m_sessionId = sessionId;
		m_serviceDescription = serviceDescription;
	}

	void On(unsigned sessionId, HermesDataWrapper::CurrentConfigurationDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_currentConfigurationData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::BoardArrivedDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_boardArrivedData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::BoardDepartedDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_boardDepartedData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::QueryWorkOrderInfoDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_queryWorkOrderInfoData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::NotificationDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_notificationData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::CheckAliveDataWrapper ^data) 
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_checkAliveData = data;
	}

	void OnDisconnected(unsigned sessionId, EVerticalStateWrapper state, const Hermes::Error&) 
	{
		//ChangeLock lock(this);
		m_sessionId = sessionId;
		m_state = state;
	}


	/*void OnTrace(unsigned sessionId, ETraceType type, StringView trace) override
	{
		TestTrace("VerticalClientTrace", type, sessionId, trace);
	}*/

internal:
	VerticalClientSink toNative() {
		VerticalClientSink verticalClientSink = VerticalClientSink();

		verticalClientSink.m_boardArrivedData = this->m_boardArrivedData->toNative();
		verticalClientSink.m_boardDepartedData = this->m_boardDepartedData->toNative();
		verticalClientSink.m_checkAliveData = this->m_checkAliveData->toNative();
		verticalClientSink.m_connectionInfo = this->m_connectionInfo->toNative();
		verticalClientSink.m_currentConfigurationData = this->m_currentConfigurationData->toNative();
		verticalClientSink.m_notificationData = this->m_notificationData->toNative();
		verticalClientSink.m_queryWorkOrderInfoData = this->m_queryWorkOrderInfoData->toNative();
		verticalClientSink.m_serviceDescription = this->m_serviceDescription->toNative();
		
		return verticalClientSink;
	}
	
};
struct VerticalServiceSink : Hermes::IVerticalServiceCallback
{
	/*Mutex m_mutex;
	Cv m_cv;*/
	//using ChangeLock = ::ChangeLock<VerticalServiceSink>;
	VerticalServiceSink() = default;
	VerticalServiceSink(VerticalServiceSink&) {};
	struct Session
	{
		unsigned m_sessionId{ 0U };
		Hermes::EVerticalState m_state{ Hermes::EVerticalState::eNOT_CONNECTED };
		Hermes::Optional<Hermes::ConnectionInfo> m_connectionInfo;
		Hermes::Optional<Hermes::SupervisoryServiceDescriptionData> m_serviceDescription;
		Hermes::Optional<Hermes::GetConfigurationData> m_getConfigurationData;
		Hermes::Optional<Hermes::SetConfigurationData> m_setConfigurationData;
		Hermes::Optional<Hermes::SendWorkOrderInfoData> m_sendWorkOrderInfoData;
		Hermes::Optional<Hermes::NotificationData> m_notificationData;
		Hermes::Optional<Hermes::CheckAliveData> m_checkAliveData;
	};
	std::map<unsigned int, Session> m_sessionMap;

	void OnConnected(unsigned sessionId, Hermes::EVerticalState state, const Hermes::ConnectionInfo& connectionInfo) override
	{
		//ChangeLock lock(this);
		auto& session = m_sessionMap[sessionId];
		session.m_state = state;
		session.m_sessionId = sessionId;
		session.m_connectionInfo = connectionInfo;
	}

	void On(unsigned sessionId, Hermes::EVerticalState state, const Hermes::SupervisoryServiceDescriptionData& serviceDescription) override
	{
		//ChangeLock lock(this);
		auto& session = m_sessionMap[sessionId];
		session.m_state = state;
		session.m_serviceDescription = serviceDescription;
	}

	void On(unsigned sessionId, const Hermes::GetConfigurationData& data, const Hermes::ConnectionInfo&) override
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId].m_getConfigurationData = data;
	}

	void On(unsigned sessionId, const Hermes::SetConfigurationData& data, const Hermes::ConnectionInfo&) override
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId].m_setConfigurationData = data;
	}

	void On(unsigned sessionId, const Hermes::SendWorkOrderInfoData& data) override
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId].m_sendWorkOrderInfoData = data;
	}

	void On(unsigned sessionId, const Hermes::NotificationData& data) override
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId].m_notificationData = data;
	}

	void On(unsigned sessionId, const Hermes::CheckAliveData& data) override
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId].m_checkAliveData = data;
	}

	void OnDisconnected(unsigned sessionId, Hermes::EVerticalState state, const Hermes::Error&) override
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId].m_state = state;
	}

	void OnTrace(unsigned sessionId, Hermes::ETraceType type, Hermes::StringView trace) override
	{
		//TestTrace("VerticalServiceTrace", type, sessionId, trace);
	}/**/

};
public ref class VerticalServiceSinkWrapper {
public:
	ref class Session {
	public:
		unsigned m_sessionId{ 0U };
		EVerticalStateWrapper m_state{ EVerticalStateWrapper::eNOT_CONNECTED };
		HermesDataWrapper::ConnectionInfoWrapper ^m_connectionInfo;
		HermesDataWrapper::SupervisoryServiceDescriptionDataWrapper ^m_serviceDescription;
		HermesDataWrapper::GetConfigurationDataWrapper ^m_getConfigurationData;
		HermesDataWrapper::SetConfigurationDataWrapper ^m_setConfigurationData;
		HermesDataWrapper::SendWorkOrderInfoDataWrapper ^m_sendWorkOrderInfoData;
		HermesDataWrapper::NotificationDataWrapper ^m_notificationData;
		HermesDataWrapper::CheckAliveDataWrapper ^m_checkAliveData;

	internal:
		VerticalServiceSink::Session toNative() {
			VerticalServiceSink::Session session;

			return session;

		}
	};
	Dictionary<int, Session^> ^m_sessionMap;
	void OnConnected(unsigned sessionId, EVerticalStateWrapper state, HermesDataWrapper::ConnectionInfoWrapper ^connectionInfo)
	{
		//ChangeLock lock(this);
		auto session = m_sessionMap[sessionId];
		session->m_state = state;
		session->m_sessionId = sessionId;
		session->m_connectionInfo = connectionInfo;
	}
	void On(unsigned sessionId, EVerticalStateWrapper state, HermesDataWrapper::SupervisoryServiceDescriptionDataWrapper ^serviceDescription)
	{
		//ChangeLock lock(this);
		auto session = m_sessionMap[sessionId];
		session->m_state = state;
		session->m_serviceDescription = serviceDescription;
	}

	void On(unsigned sessionId, HermesDataWrapper::GetConfigurationDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId]->m_getConfigurationData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::SetConfigurationDataWrapper ^data)
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId]->m_setConfigurationData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::SendWorkOrderInfoDataWrapper ^data) 
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId]->m_sendWorkOrderInfoData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::NotificationDataWrapper ^data) 
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId]->m_notificationData = data;
	}

	void On(unsigned sessionId, HermesDataWrapper::CheckAliveDataWrapper ^data) 
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId]->m_checkAliveData = data;
	}

	void OnDisconnected(unsigned sessionId, EVerticalStateWrapper state) 
	{
		//ChangeLock lock(this);
		m_sessionMap[sessionId]->m_state = state;
	}

internal:
	VerticalServiceSink toNative() {
		VerticalServiceSink verticalServiceSink;
		auto copy_m_sessionMap = this->m_sessionMap;
		for each(KeyValuePair<int, Session^> ^elem in m_sessionMap) {
			VerticalServiceSink::Session test;
						
			verticalServiceSink.m_sessionMap[elem->Key] = elem->Value->toNative();
		}
		verticalServiceSink.m_sessionMap;

		return verticalServiceSink;
	}
};