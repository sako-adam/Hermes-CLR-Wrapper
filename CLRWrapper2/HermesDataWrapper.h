#pragma once
#include "Hermes.hpp"
#include "HermesOptional.hpp"
#include "HermesStringView.hpp"
#include <msclr/marshal_cppstd.h>
#include <cliext/vector>

using namespace System;
using namespace msclr::interop;
using namespace System::Collections::Generic;

namespace HermesDataWrapper {

	public enum class ECheckAliveResponseModeWrapper
	{
		eAUTO, // automatically respond to a check alive ping with a pong
		eAPPLICATION // let the application respond with a pong
	};

	//========== Internal state check modes of the implementation (not part of The Hermes Standard) ==========
	enum class ECheckStateWrapper
	{
		eSEND_AND_RECEIVE, // check sent and received messages for conformance with state machine
		eONLY_RECEIVE // check only received message for conformance with state machine
	};

	public ref class DownstreamSettingsWrapper {
	public:
		//DownstreamSettingsWrapper() = default;
		String ^m_machineId = "";
		uint16_t  m_port{ 0 };
		double m_checkAlivePeriodInSeconds{ 60 };
		double m_reconnectWaitTimeInSeconds{ 10 };
		ECheckAliveResponseModeWrapper m_checkAliveResponseMode{ ECheckAliveResponseModeWrapper::eAUTO };
		ECheckStateWrapper m_checkState{ ECheckStateWrapper::eSEND_AND_RECEIVE };
		String ^m_optionalClientAddress = "";
	internal:
		Hermes::DownstreamSettings toNative() {
			Hermes::DownstreamSettings d_setting;
			auto copy_m_machineId = this->m_machineId;
			d_setting.m_machineId = marshal_as<std::string>(copy_m_machineId);
			d_setting.m_port = m_port;
			d_setting.m_checkAlivePeriodInSeconds = m_checkAlivePeriodInSeconds;
			d_setting.m_reconnectWaitTimeInSeconds = m_reconnectWaitTimeInSeconds;
			d_setting.m_checkAliveResponseMode = static_cast<Hermes::ECheckAliveResponseMode>(m_checkAliveResponseMode);
			d_setting.m_checkState = static_cast<Hermes::ECheckState>(m_checkState);
			auto copy_m_optionalClientAddress = this->m_optionalClientAddress;
			d_setting.m_optionalClientAddress = marshal_as<std::string>(copy_m_optionalClientAddress);
			
			return d_setting;
		}
	};

	public ref class FeatureCheckAliveResponseWrapper {
	public:
	internal:
		Hermes::FeatureCheckAliveResponse toNative() {
			Hermes::FeatureCheckAliveResponse featureCheckAliveResponse;

			return featureCheckAliveResponse;
		}
	};


	public ref class FeatureBoardForecastWrapper {
	public:
	internal:
		Hermes::FeatureBoardForecast toNative() {
			Hermes::FeatureBoardForecast data = Hermes::FeatureBoardForecast();

			return data;
		}
	};
	public ref class FeatureQueryBoardInfoWrapper {
	public:
	internal:
		Hermes::FeatureQueryBoardInfo toNative() {
			Hermes::FeatureQueryBoardInfo data = Hermes::FeatureQueryBoardInfo();

			return data;
		}
	};
	public ref class FeatureSendBoardInfoWrapper {
	public:
	internal:
		Hermes::FeatureSendBoardInfo toNative() {
			Hermes::FeatureSendBoardInfo data = Hermes::FeatureSendBoardInfo();

			return data;
		}
	};
	public ref class SupportedFeaturesWrapper
	{
	public:
		FeatureBoardForecastWrapper ^m_optionalFeatureBoardForecast = gcnew FeatureBoardForecastWrapper();
		FeatureCheckAliveResponseWrapper ^m_optionalFeatureCheckAliveResponse = gcnew FeatureCheckAliveResponseWrapper();
		FeatureQueryBoardInfoWrapper ^m_optionalFeatureQueryBoardInfo = gcnew FeatureQueryBoardInfoWrapper();
		FeatureSendBoardInfoWrapper ^m_optionalFeatureSendBoardInfo = gcnew FeatureSendBoardInfoWrapper();

	internal:
		Hermes::SupportedFeatures toNative() {
			Hermes::SupportedFeatures supportedFeatures;

			supportedFeatures.m_optionalFeatureBoardForecast = m_optionalFeatureBoardForecast->toNative();
			supportedFeatures.m_optionalFeatureCheckAliveResponse = m_optionalFeatureCheckAliveResponse->toNative();
			supportedFeatures.m_optionalFeatureQueryBoardInfo = m_optionalFeatureQueryBoardInfo->toNative();
			supportedFeatures.m_optionalFeatureSendBoardInfo = m_optionalFeatureSendBoardInfo->toNative();

			return supportedFeatures;
		}
	};
	public ref class ServiceDescriptionDataWrapper {
	public:
		String ^m_machineId = "";
		unsigned m_laneId{ 0 };
		String ^m_optionalInterfaceId = "";
		String ^m_version{ "1.2" };
		SupportedFeaturesWrapper ^m_supportedFeatures = gcnew SupportedFeaturesWrapper();
	internal:
		Hermes::ServiceDescriptionData toNative() {
			Hermes::ServiceDescriptionData service_d;
			auto copy_m_machineId = this->m_machineId;
			service_d.m_machineId = marshal_as<std::string>(copy_m_machineId);
			service_d.m_laneId = this->m_laneId;
			auto copy_m_version = this->m_version;
			service_d.m_version = marshal_as<std::string>(copy_m_version);
			auto copy_m_optionalInterfaceId = this->m_optionalInterfaceId;
			service_d.m_optionalInterfaceId = marshal_as<std::string>(copy_m_optionalInterfaceId);
			service_d.m_supportedFeatures = m_supportedFeatures->toNative();

			return service_d;
		}

	};
	public enum class EBoardQualityWrapper
	{
		eANY,
		eGOOD,
		eBAD
	};
	public enum class EFlippedBoardWrapper
	{
		eSIDE_UP_IS_UNKNOWN,
		eTOP_SIDE_IS_UP,
		eBOTTOM_SIDE_IS_UP
	};
	public ref class BoardAvailableDataWrapper {
	public:
		String ^m_boardId = "00000000-0000-0000-0000-000000000000" ;
		String ^m_boardIdCreatedBy = "";
		EBoardQualityWrapper m_failedBoard{ EBoardQualityWrapper::eANY };
		EFlippedBoardWrapper m_flippedBoard{ EFlippedBoardWrapper::eSIDE_UP_IS_UNKNOWN };
		String ^m_optionalProductTypeId = "";
		String ^m_optionalTopBarcode = "";
		String ^m_optionalBottomBarcode = "";
		double m_optionalLengthInMM;
		double m_optionalWidthInMM;
		double m_optionalThicknessInMM;
		double m_optionalConveyorSpeedInMMPerSecs;
		double m_optionalTopClearanceHeightInMM;
		double m_optionalBottomClearanceHeightInMM;
		double m_optionalWeightInGrams;
		String ^m_optionalWorkOrderId = "";

	internal:
		Hermes::BoardAvailableData toNative() {
			Hermes::BoardAvailableData boardAvailableData;
			auto copy_m_boardId = this->m_boardId;
			auto copy_m_boardIdCreatedBy = this->m_boardIdCreatedBy;
			boardAvailableData.m_boardId = marshal_as<std::string>(copy_m_boardId);
			boardAvailableData.m_boardIdCreatedBy = marshal_as<std::string>(copy_m_boardIdCreatedBy);
			boardAvailableData.m_failedBoard = static_cast<Hermes::EBoardQuality>(m_failedBoard);
			boardAvailableData.m_flippedBoard = static_cast<Hermes::EFlippedBoard>(m_flippedBoard);


			auto copy_m_optionalProductTypeId = this->m_optionalProductTypeId;
			boardAvailableData.m_optionalProductTypeId = marshal_as<std::string>(copy_m_optionalProductTypeId);
			auto copy_m_optionalTopBarcode = this->m_optionalTopBarcode;
			boardAvailableData.m_optionalTopBarcode = marshal_as<std::string>(copy_m_optionalTopBarcode);
			auto copy_m_optionalBottomBarcode = this->m_optionalBottomBarcode;
			boardAvailableData.m_optionalBottomBarcode = marshal_as < std::string>(copy_m_optionalBottomBarcode);
			boardAvailableData.m_optionalLengthInMM = System::Double(0 + m_optionalLengthInMM);//m_optionalLengthInMM;
			boardAvailableData.m_optionalWidthInMM = System::Double(0 + m_optionalWidthInMM);
			boardAvailableData.m_optionalThicknessInMM = System::Double(0 + m_optionalThicknessInMM);
			boardAvailableData.m_optionalConveyorSpeedInMMPerSecs = System::Double(0 + m_optionalConveyorSpeedInMMPerSecs);
			boardAvailableData.m_optionalTopClearanceHeightInMM = System::Double(0 + m_optionalTopClearanceHeightInMM);
			boardAvailableData.m_optionalBottomClearanceHeightInMM = System::Double(0 + m_optionalBottomClearanceHeightInMM);
			boardAvailableData.m_optionalWeightInGrams = System::Double(0 + m_optionalWeightInGrams);
			auto copy_m_optionalWorkOrderId = this->m_optionalWorkOrderId;
			boardAvailableData.m_optionalWorkOrderId = marshal_as<std::string>(copy_m_optionalWorkOrderId);
			boardAvailableData.m_failedBoard = static_cast<Hermes::EBoardQuality>(m_failedBoard);
			boardAvailableData.m_flippedBoard = static_cast<Hermes::EFlippedBoard>(m_flippedBoard);

			return boardAvailableData;
		}
	};
	public ref class RevokeBoardAvailableDataWrapper {
	public:
	internal:
		Hermes::RevokeBoardAvailableData toNative() {
			Hermes::RevokeBoardAvailableData revokeBoardAvailableData;

			return revokeBoardAvailableData;
		}
	};

	public enum class ETransferStateWrapper
	{
		eUNKNOWN,
		eNOT_STARTED,
		eINCOMPLETE,
		eCOMPLETE
	};

	public ref class TransportFinishedDataWrapper {
	public:
		ETransferStateWrapper m_transferState{ ETransferStateWrapper::eUNKNOWN };
		String ^m_boardId{ "00000000-0000-0000-0000-000000000000" };

	internal:
		Hermes::TransportFinishedData toNative() {
			Hermes::TransportFinishedData transportFinishedData;
			auto copy_m_boardId = this->m_boardId;
			transportFinishedData.m_boardId = marshal_as<std::string>(copy_m_boardId);
			transportFinishedData.m_transferState = static_cast<Hermes::ETransferState>(m_transferState);

			return transportFinishedData;
		}
	};

	public ref class BoardForecastDataWrapper {
	public:

		EBoardQualityWrapper m_failedBoard{ EBoardQualityWrapper::eANY };
		EFlippedBoardWrapper m_flippedBoard{ EFlippedBoardWrapper::eSIDE_UP_IS_UNKNOWN };

		String ^m_optionalForecastId = "";
		double m_optionalTimeUntilAvailableInSeconds;
		String ^m_optionalBoardId = "";
		String ^m_optionalBoardIdCreatedBy = "";
		String ^m_optionalProductTypeId = "";
		String ^m_optionalTopBarcode = "";
		String ^m_optionalBottomBarcode = "";
		double m_optionalLengthInMM;
		double m_optionalWidthInMM;
		double m_optionalThicknessInMM;
		double m_optionalConveyorSpeedInMMPerSecs;
		double m_optionalTopClearanceHeightInMM;
		double m_optionalBottomClearanceHeightInMM;
		double m_optionalWeightInGrams;
		String ^m_optionalWorkOrderId = "";

	internal:
		Hermes::BoardForecastData toNative() {
			Hermes::BoardForecastData boardForecastData;
			boardForecastData.m_failedBoard = static_cast<Hermes::EBoardQuality>(m_failedBoard);
			boardForecastData.m_flippedBoard = static_cast<Hermes::EFlippedBoard>(m_flippedBoard);

			auto copy_m_optionalProductTypeId = this->m_optionalProductTypeId;
			boardForecastData.m_optionalProductTypeId = marshal_as<std::string>(copy_m_optionalProductTypeId);
			auto copy_m_optionalTopBarcode = this->m_optionalTopBarcode;
			boardForecastData.m_optionalTopBarcode = marshal_as<std::string>(copy_m_optionalTopBarcode);
			auto copy_m_optionalBottomBarcode = this->m_optionalBottomBarcode;
			boardForecastData.m_optionalBottomBarcode = marshal_as < std::string>(copy_m_optionalBottomBarcode);
			boardForecastData.m_optionalLengthInMM = System::Double(0 + m_optionalLengthInMM);//m_optionalLengthInMM;
			boardForecastData.m_optionalWidthInMM = System::Double(0 + m_optionalWidthInMM);
			boardForecastData.m_optionalThicknessInMM = System::Double(0 + m_optionalThicknessInMM);
			boardForecastData.m_optionalConveyorSpeedInMMPerSecs = System::Double(0 + m_optionalConveyorSpeedInMMPerSecs);
			boardForecastData.m_optionalTopClearanceHeightInMM = System::Double(0 + m_optionalTopClearanceHeightInMM);
			boardForecastData.m_optionalBottomClearanceHeightInMM = System::Double(0 + m_optionalBottomClearanceHeightInMM);
			boardForecastData.m_optionalWeightInGrams = System::Double(0 + m_optionalWeightInGrams);
			auto copy_m_optionalWorkOrderId = this->m_optionalWorkOrderId;
			boardForecastData.m_optionalWorkOrderId = marshal_as<std::string>(copy_m_optionalWorkOrderId);
			auto copy_m_optionalBoardId = this->m_optionalBoardId;
			boardForecastData.m_optionalBoardId = marshal_as<std::string>(copy_m_optionalBoardId);
			auto copy_m_optionalBoardIdCreatedBy = this->m_optionalBoardIdCreatedBy;
			boardForecastData.m_optionalBoardIdCreatedBy = marshal_as<std::string>(copy_m_optionalBoardIdCreatedBy);

			boardForecastData.m_flippedBoard = static_cast<Hermes::EFlippedBoard>(m_flippedBoard);

			return boardForecastData;
		}

	};

	public ref class SendBoardInfoDataWrapper {
	public:
		String ^m_optionalBoardId = "";
		String ^m_optionalBoardIdCreatedBy = "";
		EBoardQualityWrapper m_optionalFailedBoard;
		String ^m_optionalProductTypeId = "";
		EFlippedBoardWrapper m_optionalFlippedBoard;
		String ^m_optionalTopBarcode = "";
		String ^m_optionalBottomBarcode = "";
		double m_optionalLengthInMM;
		double m_optionalWidthInMM;
		double m_optionalThicknessInMM;
		double m_optionalConveyorSpeedInMMPerSecs;
		double m_optionalTopClearanceHeightInMM;
		double m_optionalBottomClearanceHeightInMM;
		double m_optionalWeightInGrams;
		String ^m_optionalWorkOrderId = "";

	internal:
		Hermes::SendBoardInfoData toNative() {
			Hermes::SendBoardInfoData sendBoardInfoData;

			auto copy_m_optionalProductTypeId = this->m_optionalProductTypeId;
			sendBoardInfoData.m_optionalProductTypeId = marshal_as<std::string>(copy_m_optionalProductTypeId);
			auto copy_m_optionalTopBarcode = this->m_optionalTopBarcode;
			sendBoardInfoData.m_optionalTopBarcode = marshal_as<std::string>(copy_m_optionalTopBarcode);
			auto copy_m_optionalBottomBarcode = this->m_optionalBottomBarcode;
			sendBoardInfoData.m_optionalBottomBarcode = marshal_as < std::string>(copy_m_optionalBottomBarcode);
			sendBoardInfoData.m_optionalLengthInMM = System::Double(0 + m_optionalLengthInMM);//m_optionalLengthInMM;
			sendBoardInfoData.m_optionalWidthInMM = System::Double(0 + m_optionalWidthInMM);
			sendBoardInfoData.m_optionalThicknessInMM = System::Double(0 + m_optionalThicknessInMM);
			sendBoardInfoData.m_optionalConveyorSpeedInMMPerSecs = System::Double(0 + m_optionalConveyorSpeedInMMPerSecs);
			sendBoardInfoData.m_optionalTopClearanceHeightInMM = System::Double(0 + m_optionalTopClearanceHeightInMM);
			sendBoardInfoData.m_optionalBottomClearanceHeightInMM = System::Double(0 + m_optionalBottomClearanceHeightInMM);
			sendBoardInfoData.m_optionalWeightInGrams = System::Double(0 + m_optionalWeightInGrams);
			auto copy_m_optionalWorkOrderId = this->m_optionalWorkOrderId;
			sendBoardInfoData.m_optionalWorkOrderId = marshal_as<std::string>(copy_m_optionalWorkOrderId);
			sendBoardInfoData.m_optionalFlippedBoard = static_cast<Hermes::EFlippedBoard>(m_optionalFlippedBoard);


			auto copy_m_optionalBoardId = this->m_optionalBoardId;
			sendBoardInfoData.m_optionalBoardId = marshal_as<std::string>(copy_m_optionalBoardId);
			auto copy_m_optionalBoardIdCreatedBy = this->m_optionalBoardIdCreatedBy;
			sendBoardInfoData.m_optionalBoardIdCreatedBy = marshal_as<std::string>(copy_m_optionalBoardIdCreatedBy);

			return sendBoardInfoData;
		}

	};

	public enum class ENotificationCodeWrapper
	{
		eUNSPECIFIC,
		ePROTOCOL_ERROR,
		eCONNECTION_REFUSED_BECAUSE_OF_ESTABLISHED_CONNECTION,
		eCONNECTION_RESET_BECAUSE_OF_CHANGED_CONFIGURATION,
		eCONFIGURATION_ERROR,
		eMACHINE_SHUTDOWN,
		eBOARD_FORECAST_ERROR
	};
	public enum class ESeverityWrapper
	{
		eUNKNOWN,
		eFATAL,
		eERROR,
		eWARNING,
		eINFO
	};

	public ref class NotificationDataWrapper {
	public:
		ENotificationCodeWrapper m_notificationCode{ ENotificationCodeWrapper::eUNSPECIFIC };
		ESeverityWrapper m_severity{ ESeverityWrapper::eUNKNOWN };
		String ^m_description = "";
	internal:
		Hermes::NotificationData toNative() {
			Hermes::NotificationData notificationData;

			notificationData.m_notificationCode = static_cast<Hermes::ENotificationCode>(m_notificationCode);
			notificationData.m_severity = static_cast<Hermes::ESeverity>(m_severity);
			auto copy_m_description = this->m_description;
			notificationData.m_description = marshal_as<std::string>(copy_m_description);

			return notificationData;
		}
	};

	public enum class ECheckAliveTypeWrapper
	{
		eUNKNOWN,
		ePING,
		ePONG
	};

	public ref class CheckAliveDataWrapper {
	public:
		ECheckAliveTypeWrapper m_optionalType;
		String ^m_optionalId = "";
	internal:
		Hermes::CheckAliveData toNative() {
			Hermes::CheckAliveData checkAliveData;
			auto copy_m_optionalId = this->m_optionalId;
			checkAliveData.m_optionalId = marshal_as < std::string>(copy_m_optionalId);
			checkAliveData.m_optionalType = static_cast<Hermes::ECheckAliveType>(m_optionalType);

			return checkAliveData;

		}
	};

	public ref class ConnectionInfoWrapper {
	public:
		String ^m_address = "";
		uint16_t m_port{ 0 };
		String ^m_hostName = "";

	internal:
		Hermes::ConnectionInfo toNative() {
			Hermes::ConnectionInfo connectionInfo;

			auto copy_m_address = this->m_address;
			connectionInfo.m_address = marshal_as<std::string>(copy_m_address);
			connectionInfo.m_port = m_port;
			auto copy_m_hostName = this->m_hostName;
			connectionInfo.m_hostName = marshal_as<std::string>(copy_m_hostName);

			return connectionInfo;
		}

	};
	public ref class UpstreamSettingsWrapper {
	public:
		String ^m_machineId = "";
		String ^m_hostAddress = "";
		uint16_t m_port{ 0 };
		double m_checkAlivePeriodInSeconds{ 60 };
		double m_reconnectWaitTimeInSeconds{ 10 };
		ECheckAliveResponseModeWrapper m_checkAliveResponseMode{ ECheckAliveResponseModeWrapper::eAUTO };
		ECheckStateWrapper m_checkState{ ECheckStateWrapper::eSEND_AND_RECEIVE };

	internal:
		Hermes::UpstreamSettings toNative() {
			Hermes::UpstreamSettings d_setting = Hermes::UpstreamSettings();
			auto copy_m_machineId = this->m_machineId;
			d_setting.m_machineId = marshal_as<std::string>(copy_m_machineId);
			auto copy_m_hostAddress = this->m_hostAddress;
			d_setting.m_hostAddress = marshal_as<std::string>(copy_m_hostAddress);
			d_setting.m_port = m_port;
			d_setting.m_checkAlivePeriodInSeconds = m_checkAlivePeriodInSeconds;
			d_setting.m_reconnectWaitTimeInSeconds = m_reconnectWaitTimeInSeconds;
			d_setting.m_checkAliveResponseMode = static_cast<Hermes::ECheckAliveResponseMode>(m_checkAliveResponseMode);
			d_setting.m_checkState = static_cast<Hermes::ECheckState>(m_checkState);

			return d_setting;
		}
	};
	public ref class MachineReadyDataWrapper {
	public:
		EBoardQualityWrapper m_failedBoard{ EBoardQualityWrapper::eANY };
		String ^m_optionalForecastId = "";
		String ^m_optionalBoardId = "";
		String ^m_optionalProductTypeId = "";
		EFlippedBoardWrapper m_optionalFlippedBoard;
		String ^m_optionalTopBarcode = "";
		String ^m_optionalBottomBarcode;
		double m_optionalLengthInMM;
		double m_optionalWidthInMM;
		double m_optionalThicknessInMM;
		double m_optionalConveyorSpeedInMMPerSecs;
		double m_optionalTopClearanceHeightInMM;
		double m_optionalBottomClearanceHeightInMM;
		double m_optionalWeightInGrams;
		String ^m_optionalWorkOrderId = "";

	internal:
		Hermes::MachineReadyData toNative() {
			Hermes::MachineReadyData machineReadyData;

			machineReadyData.m_failedBoard = static_cast<Hermes::EBoardQuality>(m_failedBoard);


			auto copy_m_optionalProductTypeId = this->m_optionalProductTypeId;
			machineReadyData.m_optionalProductTypeId = marshal_as<std::string>(copy_m_optionalProductTypeId);
			auto copy_m_optionalTopBarcode = this->m_optionalTopBarcode;
			machineReadyData.m_optionalTopBarcode = marshal_as<std::string>(copy_m_optionalTopBarcode);
			auto copy_m_optionalBottomBarcode = this->m_optionalBottomBarcode;
			machineReadyData.m_optionalBottomBarcode = marshal_as < std::string>(copy_m_optionalBottomBarcode);
			machineReadyData.m_optionalLengthInMM = System::Double(0 + m_optionalLengthInMM);//m_optionalLengthInMM;
			machineReadyData.m_optionalWidthInMM = System::Double(0 + m_optionalWidthInMM);
			machineReadyData.m_optionalThicknessInMM = System::Double(0 + m_optionalThicknessInMM);
			machineReadyData.m_optionalConveyorSpeedInMMPerSecs = System::Double(0 + m_optionalConveyorSpeedInMMPerSecs);
			machineReadyData.m_optionalTopClearanceHeightInMM = System::Double(0 + m_optionalTopClearanceHeightInMM);
			machineReadyData.m_optionalBottomClearanceHeightInMM = System::Double(0 + m_optionalBottomClearanceHeightInMM);
			machineReadyData.m_optionalWeightInGrams = System::Double(0 + m_optionalWeightInGrams);
			auto copy_m_optionalWorkOrderId = this->m_optionalWorkOrderId;
			machineReadyData.m_optionalWorkOrderId = marshal_as<std::string>(copy_m_optionalWorkOrderId);
			machineReadyData.m_failedBoard = static_cast<Hermes::EBoardQuality>(m_failedBoard);

			auto copy_m_optionalBoardId = this->m_optionalBoardId;
			machineReadyData.m_optionalBoardId = marshal_as<std::string>(copy_m_optionalBoardId);

			return machineReadyData;
		}
	};

	public ref class RevokeMachineReadyDataWarpper {
	public:
	internal:
		Hermes::RevokeMachineReadyData toNative() {
			Hermes::RevokeMachineReadyData revokeMachineReadyData;

			return revokeMachineReadyData;
		}
	};

	public ref class StartTransportDataWrapper {
	public:
		String ^m_boardId{ "00000000-0000-0000-0000-000000000000" };
		double m_optionalConveyorSpeedInMMPerSecs;
	internal:
		Hermes::StartTransportData toNative() {
			Hermes::StartTransportData startTransportData;

			auto copy_m_boardId = this->m_boardId;
			startTransportData.m_boardId = marshal_as<std::string>(copy_m_boardId);
			startTransportData.m_optionalConveyorSpeedInMMPerSecs = System::Double(0 + m_optionalConveyorSpeedInMMPerSecs);

			return startTransportData;
		}
	};

	public ref class StopTransportDataWrapper {
	public:
		ETransferStateWrapper m_transferState{ ETransferStateWrapper::eUNKNOWN };
		String ^m_boardId{ "00000000-0000-0000-0000-000000000000" };

	internal:
		Hermes::StopTransportData toNative() {
			Hermes::StopTransportData stopTransportData;

			stopTransportData.m_transferState = static_cast<Hermes::ETransferState>(m_transferState);
			auto copy_m_boardId = this->m_boardId;
			stopTransportData.m_boardId = marshal_as<std::string>(copy_m_boardId);

			return stopTransportData;
		}
	};

	public ref class QueryBoardInfoDataWrapper {
	public:
		String ^m_optionalTopBarcode = "";
		String ^m_optionalBottomBarcode = "";
	internal:
		Hermes::QueryBoardInfoData toNative() {
			Hermes::QueryBoardInfoData queryBoardInfoData;

			auto copy_m_optionalTopBarcode = this->m_optionalTopBarcode;
			queryBoardInfoData.m_optionalTopBarcode = marshal_as<std::string>(copy_m_optionalTopBarcode);
			auto copy_m_optionalBottomBarcode = this->m_optionalBottomBarcode;
			queryBoardInfoData.m_optionalBottomBarcode = marshal_as<std::string>(copy_m_optionalBottomBarcode);

			return queryBoardInfoData;
		}
	};

	public ref class UpstreamConfigurationWrapper {
	public:
		unsigned m_upstreamLaneId{ 0 };
		String ^m_optionalUpstreamInterfaceId = "";
		String ^m_hostAddress = "";
		uint16_t m_port{ 0 };
		array< UpstreamConfigurationWrapper^ >^ ustreamConfiguration;

	internal:
		Hermes::UpstreamConfiguration toNative() {
			Hermes::UpstreamConfiguration upstreamConfiguration;

			upstreamConfiguration.m_upstreamLaneId = this->m_upstreamLaneId;
			auto copy_m_hostAddress = this->m_hostAddress;
			upstreamConfiguration.m_hostAddress = marshal_as<std::string>(copy_m_hostAddress);
			upstreamConfiguration.m_port = this->m_port;
			auto copy_m_optionalUpstreamInterfaceId = this->m_optionalUpstreamInterfaceId;
			upstreamConfiguration.m_optionalUpstreamInterfaceId = marshal_as<std::string>(copy_m_optionalUpstreamInterfaceId);

			return upstreamConfiguration;

		}
		Hermes::UpstreamConfigurations toNativeVector() {
			Hermes::UpstreamConfigurations upstreamConfigurations(ustreamConfiguration->Length);
			int i = 0;
			for (Hermes::UpstreamConfiguration elem : upstreamConfigurations) {
				auto copy_host = this->ustreamConfiguration[i]->m_hostAddress;
				elem.m_hostAddress = marshal_as<std::string>(copy_host);
				elem.m_port = ustreamConfiguration[i]->m_port;
				elem.m_upstreamLaneId = ustreamConfiguration[i]->m_upstreamLaneId;

				i += 1;
			}

			return upstreamConfigurations;
		}
	};

	public ref class DownstreamConfigurationWrapper {
	public:
		unsigned m_downstreamLaneId{ 0 };
		String ^m_optionalDownstreamInterfaceId = "";
		String ^m_optionalClientAddress = "";
		uint16_t m_port{ 0 };
		array< DownstreamConfigurationWrapper^ >^ downstreamConfiguration;

	internal:
		Hermes::DownstreamConfiguration toNative() {
			Hermes::DownstreamConfiguration downstreamConfiguration;

			downstreamConfiguration.m_downstreamLaneId = this->m_downstreamLaneId;
			downstreamConfiguration.m_port = this->m_port;

			return downstreamConfiguration;
		}
		Hermes::DownstreamConfigurations toNativeVector() {
			Hermes::DownstreamConfigurations downstreamConfigurations(downstreamConfiguration->Length);


			int i = 0;
			for (Hermes::DownstreamConfiguration elem : downstreamConfigurations) {
				elem.m_downstreamLaneId = downstreamConfiguration[i]->m_downstreamLaneId;
				elem.m_port = downstreamConfiguration[i]->m_port;
				auto copy_m_optionalDownstreamInterfaceId = downstreamConfiguration[i]->m_optionalDownstreamInterfaceId;
				elem.m_optionalDownstreamInterfaceId = marshal_as<std::string>(copy_m_optionalDownstreamInterfaceId);
				auto copy_m_optionalClientAddress = downstreamConfiguration[i]->m_optionalClientAddress;
				elem.m_optionalClientAddress = marshal_as<std::string>(copy_m_optionalClientAddress);

				i += 1;
			}
			
			return downstreamConfigurations;
		}
	};

	public ref class CurrentConfigurationDataWrapper {
	public:
		String ^m_optionalMachineId = "";
		int m_optionalSupervisorySystemPort;
		//array<UpstreamConfigurationWrapper^>^% m_upstreamConfigurations;
		UpstreamConfigurationWrapper ^m_upstreamConfigurations = gcnew UpstreamConfigurationWrapper();
		DownstreamConfigurationWrapper ^m_downstreamConfigurations = gcnew DownstreamConfigurationWrapper();

	internal:
		Hermes::CurrentConfigurationData toNative() {
			Hermes::CurrentConfigurationData currentConfigurationData;

			currentConfigurationData.m_downstreamConfigurations = m_downstreamConfigurations->toNativeVector();
			currentConfigurationData.m_upstreamConfigurations = m_upstreamConfigurations->toNativeVector();
			auto copy_m_optionalMachineId = this->m_optionalMachineId;
			currentConfigurationData.m_optionalMachineId = marshal_as<std::string>(copy_m_optionalMachineId);
			currentConfigurationData.m_optionalSupervisorySystemPort = System::UInt16(m_optionalSupervisorySystemPort);

			return currentConfigurationData;
		}
	};

	public ref class SetConfigurationDataWrapper {
	public:
		String ^m_machineId = "";
		int m_optionalSupervisorySystemPort;
		UpstreamConfigurationWrapper ^m_upstreamConfigurations = gcnew UpstreamConfigurationWrapper();
		DownstreamConfigurationWrapper ^m_downstreamConfigurations = gcnew DownstreamConfigurationWrapper();

	internal:
		Hermes::SetConfigurationData toNative() {
			Hermes::SetConfigurationData setConfigurationData;

			setConfigurationData.m_downstreamConfigurations = m_downstreamConfigurations->toNativeVector();
			setConfigurationData.m_upstreamConfigurations = m_upstreamConfigurations->toNativeVector();
			setConfigurationData.m_optionalSupervisorySystemPort = System::UInt16(m_optionalSupervisorySystemPort);

			return setConfigurationData;
		}
	};
	public ref class ConfigurationServiceSettingsWrapper
	{
	public:
		uint16_t m_port{ 0 };
		double m_reconnectWaitTimeInSeconds{ 10 };

	internal:
		Hermes::ConfigurationServiceSettings toNative() {
			Hermes::ConfigurationServiceSettings configurationServiceSettings;

			configurationServiceSettings.m_port = this->m_port;
			configurationServiceSettings.m_reconnectWaitTimeInSeconds = this->m_reconnectWaitTimeInSeconds;

			return configurationServiceSettings;
		}

	};

	public ref class FeatureConfigurationWrapper {
	public:
	internal:
		Hermes::FeatureConfiguration toNative() {
			Hermes::FeatureConfiguration featureConfiguration;

			return featureConfiguration;
		}
	};


	public ref class FeatureBoardTrackingWrapper {
	public:
	internal:
		Hermes::FeatureBoardTracking toNative() {
			Hermes::FeatureBoardTracking featureBoardTracking;

			return featureBoardTracking;

		}

	};

	public ref class FeatureQueryWorkOrderInfoWrapper {
	public:
	internal:
		Hermes::FeatureQueryWorkOrderInfo toNative() {
			Hermes::FeatureQueryWorkOrderInfo featureQueryWorkOrderInfo;

			return featureQueryWorkOrderInfo;
		}

	};

	public ref class FeatureSendWorkOrderInfoWrapper {
	public:
	internal:
		Hermes::FeatureSendWorkOrderInfo toNative() {
			Hermes::FeatureSendWorkOrderInfo featureSendWorkOrderInfo;

			return featureSendWorkOrderInfo;
		}

	};

	public ref class SupervisoryFeaturesWrapper {
	public:
		FeatureConfigurationWrapper ^m_optionalFeatureConfiguration = gcnew FeatureConfigurationWrapper();
		FeatureCheckAliveResponseWrapper ^m_optionalFeatureCheckAliveResponse = gcnew FeatureCheckAliveResponseWrapper();
		FeatureBoardTrackingWrapper ^m_optionalFeatureBoardTracking = gcnew FeatureBoardTrackingWrapper();
		FeatureQueryWorkOrderInfoWrapper ^m_optionalFeatureQueryWorkOrderInfo = gcnew FeatureQueryWorkOrderInfoWrapper();
		FeatureSendWorkOrderInfoWrapper ^m_optionalFeatureSendWorkOrderInfo = gcnew FeatureSendWorkOrderInfoWrapper();

	internal:
		Hermes::SupervisoryFeatures toNative() {
			Hermes::SupervisoryFeatures supervisoryFeatures = Hermes::SupervisoryFeatures();

			supervisoryFeatures.m_optionalFeatureConfiguration = m_optionalFeatureConfiguration->toNative();
			supervisoryFeatures.m_optionalFeatureCheckAliveResponse = m_optionalFeatureCheckAliveResponse->toNative();
			supervisoryFeatures.m_optionalFeatureBoardTracking = m_optionalFeatureBoardTracking->toNative();
			supervisoryFeatures.m_optionalFeatureQueryWorkOrderInfo = m_optionalFeatureQueryWorkOrderInfo->toNative();
			supervisoryFeatures.m_optionalFeatureSendWorkOrderInfo = m_optionalFeatureSendWorkOrderInfo->toNative();

			return supervisoryFeatures;
		}
	};

	public ref class SupervisoryServiceDescriptionDataWrapper {
	public:
		String ^m_systemId = "";
		String ^m_version{ "1.2" };
		SupervisoryFeaturesWrapper ^m_supportedFeatures = gcnew SupervisoryFeaturesWrapper();

	internal:
		Hermes::SupervisoryServiceDescriptionData toNative() {
			Hermes::SupervisoryServiceDescriptionData supervisoryServiceDescriptionData = Hermes::SupervisoryServiceDescriptionData();

			supervisoryServiceDescriptionData.m_supportedFeatures = m_supportedFeatures->toNative();
			auto copy_m_systemId = this->m_systemId;
			supervisoryServiceDescriptionData.m_systemId = marshal_as<std::string>(copy_m_systemId);
			auto copy_m_version = this->m_version;
			supervisoryServiceDescriptionData.m_version = marshal_as<std::string>(copy_m_version);

			return supervisoryServiceDescriptionData;
		}
	};

	public enum class EBoardArrivedTransferWrapper
	{
		eTRANSFERRED,
		eLOADED,
		eINSERTED
	};

	generic<class T>
	ref class OptionalWrapper;
	template<class T> ref class Optional
	{
	public:
		
	internal:
		Hermes::Optional<T> toNative() {
			Hermes::Optional<T> optional = new Hermes::Optional<T>();

			return optional;
		}

	};
	public ref class BoardArrivedDataWrapper {
	public:
		String ^m_machineId = "";
		unsigned m_upstreamLaneId{ 0 };
		String ^m_optionalUpstreamInterfaceId = "";
		String ^m_optionalMagazineId = "";
		int m_optionalSlotId;
		EBoardArrivedTransferWrapper m_boardTransfer{ EBoardArrivedTransferWrapper::eTRANSFERRED };
		String ^m_boardId{ "00000000-0000-0000-0000-000000000000" };
		String ^m_boardIdCreatedBy = "";
		EBoardQualityWrapper m_failedBoard{ EBoardQualityWrapper::eANY };
		String ^m_optionalProductTypeId = "";
		EFlippedBoardWrapper m_flippedBoard{ EFlippedBoardWrapper::eSIDE_UP_IS_UNKNOWN };
		String ^m_optionalTopBarcode = "";
		String ^m_optionalBottomBarcode = "";
		double m_optionalLengthInMM;
		double m_optionalWidthInMM;
		double m_optionalThicknessInMM;
		double m_optionalConveyorSpeedInMMPerSecs;
		double m_optionalTopClearanceHeightInMM;
		double m_optionalBottomClearanceHeightInMM;
		double m_optionalWeightInGrams;
		String ^m_optionalWorkOrderId = "";
	internal:
		Hermes::BoardArrivedData toNative() {
			Hermes::BoardArrivedData boardArrivedData = Hermes::BoardArrivedData();
			auto copy_m_machineId = this->m_machineId;
			boardArrivedData.m_boardId = marshal_as<std::string>(copy_m_machineId);
			boardArrivedData.m_upstreamLaneId = this->m_upstreamLaneId;
			auto copy_m_optionalUpstreamInterfaceId = this->m_optionalUpstreamInterfaceId;
			boardArrivedData.m_optionalUpstreamInterfaceId = marshal_as<std::string>(copy_m_optionalUpstreamInterfaceId);
			auto copy_m_optionalMagazineId = this->m_optionalMagazineId;
			boardArrivedData.m_optionalMagazineId = marshal_as<std::string>(copy_m_optionalMagazineId);
			boardArrivedData.m_optionalSlotId = System::UInt32(m_optionalSlotId);// m_optionalSlotId.ToUInt16;//marshal_as<std::int32_t>(m_optionalSlotId);
			auto copy_m_boardId = this->m_boardId;
			boardArrivedData.m_boardId = marshal_as<std::string>(copy_m_boardId);
			auto copy_m_boardIdCreatedBy = this->m_boardIdCreatedBy;
			boardArrivedData.m_boardIdCreatedBy = marshal_as<std::string>(copy_m_boardIdCreatedBy);
			auto copy_m_optionalProductTypeId = this->m_optionalProductTypeId;
			boardArrivedData.m_optionalProductTypeId = marshal_as<std::string>(copy_m_optionalProductTypeId);
			auto copy_m_optionalTopBarcode = this->m_optionalTopBarcode;
			boardArrivedData.m_optionalTopBarcode = marshal_as<std::string>(copy_m_optionalTopBarcode);
			auto copy_m_optionalBottomBarcode = this->m_optionalBottomBarcode;
			boardArrivedData.m_optionalBottomBarcode = marshal_as < std::string>(copy_m_optionalBottomBarcode);
			boardArrivedData.m_optionalLengthInMM = System::Double(0 + m_optionalLengthInMM);//m_optionalLengthInMM;
			boardArrivedData.m_optionalWidthInMM = System::Double(0 + m_optionalWidthInMM);
			boardArrivedData.m_optionalThicknessInMM = System::Double(0 + m_optionalThicknessInMM);
			boardArrivedData.m_optionalConveyorSpeedInMMPerSecs = System::Double(0 + m_optionalConveyorSpeedInMMPerSecs);
			boardArrivedData.m_optionalTopClearanceHeightInMM = System::Double(0 + m_optionalTopClearanceHeightInMM);
			boardArrivedData.m_optionalBottomClearanceHeightInMM = System::Double(0 + m_optionalBottomClearanceHeightInMM);
			boardArrivedData.m_optionalWeightInGrams = System::Double(0 + m_optionalWeightInGrams);
			auto copy_m_optionalWorkOrderId = this->m_optionalWorkOrderId;
			boardArrivedData.m_optionalWorkOrderId = marshal_as<std::string>(copy_m_optionalWorkOrderId);
			boardArrivedData.m_boardTransfer = static_cast<Hermes::EBoardArrivedTransfer>(m_boardTransfer);
			boardArrivedData.m_failedBoard = static_cast<Hermes::EBoardQuality>(m_failedBoard);
			boardArrivedData.m_flippedBoard = static_cast<Hermes::EFlippedBoard>(m_flippedBoard); 

			return boardArrivedData;
		}
	};

	public enum class EBoardDepartedTransferWrapper
	{
		eTRANSFERRED,
		eUNLOADED,
		eREMOVED
	};

	public ref class BoardDepartedDataWrapper {
	public:
		String ^m_machineId = "";
		unsigned m_downstreamLaneId{ 0 };
		String ^m_optionalDownstreamInterfaceId = "";
		String ^m_optionalMagazineId = "";
		int m_optionalSlotId;
		EBoardDepartedTransferWrapper m_boardTransfer{ EBoardDepartedTransferWrapper::eTRANSFERRED };
		String ^m_boardId{ "00000000-0000-0000-0000-000000000000" };
		String ^m_boardIdCreatedBy = "";
		EBoardQualityWrapper m_failedBoard{ EBoardQualityWrapper::eANY };
		String ^m_optionalProductTypeId = "";
		EFlippedBoardWrapper m_flippedBoard{ EFlippedBoardWrapper::eSIDE_UP_IS_UNKNOWN };
		String ^m_optionalTopBarcode = "";
		String ^m_optionalBottomBarcode = "";
		double m_optionalLengthInMM;
		double m_optionalWidthInMM;
		double m_optionalThicknessInMM;
		double m_optionalConveyorSpeedInMMPerSecs;
		double m_optionalTopClearanceHeightInMM;
		double m_optionalBottomClearanceHeightInMM;
		double m_optionalWeightInGrams;
		String ^m_optionalWorkOrderId = "";

	internal:
		Hermes::BoardDepartedData toNative() {
			Hermes::BoardDepartedData boardDepartedData;

			auto copy_m_machineId = this->m_machineId;
			boardDepartedData.m_boardId = marshal_as<std::string>(copy_m_machineId);
			boardDepartedData.m_downstreamLaneId = this->m_downstreamLaneId;
			auto copy_m_optionalDownstreamInterfaceId = this->m_optionalDownstreamInterfaceId;
			boardDepartedData.m_optionalDownstreamInterfaceId = marshal_as<std::string>(copy_m_optionalDownstreamInterfaceId);
			auto copy_m_optionalMagazineId = this->m_optionalMagazineId;
			boardDepartedData.m_optionalMagazineId = marshal_as<std::string>(copy_m_optionalMagazineId);
			boardDepartedData.m_optionalSlotId = System::UInt32(m_optionalSlotId);// m_optionalSlotId.ToUInt16;//marshal_as<std::int32_t>(m_optionalSlotId);
			auto copy_m_boardId = this->m_boardId;
			boardDepartedData.m_boardId = marshal_as<std::string>(copy_m_boardId);
			auto copy_m_boardIdCreatedBy = this->m_boardIdCreatedBy;
			boardDepartedData.m_boardIdCreatedBy = marshal_as<std::string>(copy_m_boardIdCreatedBy);
			auto copy_m_optionalProductTypeId = this->m_optionalProductTypeId;
			boardDepartedData.m_optionalProductTypeId = marshal_as<std::string>(copy_m_optionalProductTypeId);
			auto copy_m_optionalTopBarcode = this->m_optionalTopBarcode;
			boardDepartedData.m_optionalTopBarcode = marshal_as<std::string>(copy_m_optionalTopBarcode);
			auto copy_m_optionalBottomBarcode = this->m_optionalBottomBarcode;
			boardDepartedData.m_optionalBottomBarcode = marshal_as < std::string>(copy_m_optionalBottomBarcode);
			boardDepartedData.m_optionalLengthInMM = System::Double(0 + m_optionalLengthInMM);//m_optionalLengthInMM;
			boardDepartedData.m_optionalWidthInMM = System::Double(0 + m_optionalWidthInMM);
			boardDepartedData.m_optionalThicknessInMM = System::Double(0 + m_optionalThicknessInMM);
			boardDepartedData.m_optionalConveyorSpeedInMMPerSecs = System::Double(0 + m_optionalConveyorSpeedInMMPerSecs);
			boardDepartedData.m_optionalTopClearanceHeightInMM = System::Double(0 + m_optionalTopClearanceHeightInMM);
			boardDepartedData.m_optionalBottomClearanceHeightInMM = System::Double(0 + m_optionalBottomClearanceHeightInMM);
			boardDepartedData.m_optionalWeightInGrams = System::Double(0 + m_optionalWeightInGrams);
			auto copy_m_optionalWorkOrderId = this->m_optionalWorkOrderId;
			boardDepartedData.m_optionalWorkOrderId = marshal_as<std::string>(copy_m_optionalWorkOrderId);
			boardDepartedData.m_boardTransfer = static_cast<Hermes::EBoardDepartedTransfer>(m_boardTransfer);
			boardDepartedData.m_failedBoard = static_cast<Hermes::EBoardQuality>(m_failedBoard);
			boardDepartedData.m_flippedBoard = static_cast<Hermes::EFlippedBoard>(m_flippedBoard);

			return boardDepartedData;
		}
	};

	public ref class QueryWorkOrderInfoDataWrapper {
	public:
		String ^m_optionalQueryId = "";
		String ^m_machineId = "";
		String ^m_optionalMagazineId = "";
		int m_optionalSlotId ;
		String ^m_optionalBarcode = "";
	internal:
		Hermes::QueryWorkOrderInfoData toNative() {
			Hermes::QueryWorkOrderInfoData queryWorkOrderInfoData;

			auto coy_m_optionalQueryId = this->m_optionalQueryId;
			queryWorkOrderInfoData.m_optionalQueryId = marshal_as<std::string>(coy_m_optionalQueryId);
			auto coy_m_machineId = this->m_machineId;
			queryWorkOrderInfoData.m_machineId = marshal_as<std::string>(coy_m_machineId);
			auto coy_m_optionalMagazineId = this->m_optionalMagazineId;
			queryWorkOrderInfoData.m_optionalMagazineId = marshal_as<std::string>(coy_m_optionalMagazineId);
			queryWorkOrderInfoData.m_optionalSlotId = System::UInt32(m_optionalSlotId);

			auto coy_m_optionalBarcode = this->m_optionalBarcode;
			queryWorkOrderInfoData.m_optionalBarcode = marshal_as<std::string>(coy_m_optionalBarcode);

			return queryWorkOrderInfoData;
		}
	};

	public ref class VerticalClientSettingsWrapper {
	public:
		String ^m_systemId = "";
		String ^m_hostAddress = "";
		int m_port{ 0 };
		double m_reconnectWaitTimeInSeconds{ 10 };
		double m_checkAlivePeriodInSeconds{ 60 };
		ECheckAliveResponseModeWrapper m_checkAliveResponseMode{ ECheckAliveResponseModeWrapper::eAUTO };

	internal:
		Hermes::VerticalClientSettings toNative() {
			Hermes::VerticalClientSettings  verticalClientSettings;

			auto copy_m_systemId = this->m_systemId;
			verticalClientSettings.m_systemId = marshal_as<std::string>(copy_m_systemId);
			auto copy_m_hostAddress = this->m_hostAddress;
			verticalClientSettings.m_hostAddress = marshal_as<std::string>(copy_m_hostAddress);
			verticalClientSettings.m_port = System::UInt16(m_port);
			verticalClientSettings.m_reconnectWaitTimeInSeconds = System::Double(0 + m_reconnectWaitTimeInSeconds);
			verticalClientSettings.m_checkAlivePeriodInSeconds = System::Double(0 + m_checkAlivePeriodInSeconds);
			verticalClientSettings.m_checkAliveResponseMode = static_cast<Hermes::ECheckAliveResponseMode>(m_checkAliveResponseMode);

			return verticalClientSettings;
		}

	};

	public ref class SendWorkOrderInfoDataWrapper {
	public:
		String ^m_optionalQueryId = "";
		String ^m_optionalWorkOrderId = "";
		String ^m_optionalBoardId = "";
		String ^m_optionalBoardIdCreatedBy = "";
		EBoardQualityWrapper m_optionalFailedBoard;
		String ^m_optionalProductTypeId;
		EFlippedBoardWrapper m_optionalFlippedBoard;
		String ^m_optionalTopBarcode = "";
		String ^m_optionalBottomBarcode = "";
		double  m_optionalLengthInMM;
		double  m_optionalWidthInMM;
		double  m_optionalThicknessInMM;
		double  m_optionalConveyorSpeedInMMPerSecs;
		double  m_optionalTopClearanceHeightInMM;
		double  m_optionalBottomClearanceHeightInMM;
		double  m_optionalWeightInGrams;

	internal:
		Hermes::SendWorkOrderInfoData toNative() {
			Hermes::SendWorkOrderInfoData sendWorkOrderInfoData;

			auto copy_m_optionalQueryId = this->m_optionalQueryId;
			sendWorkOrderInfoData.m_optionalQueryId = marshal_as<std::string>(copy_m_optionalQueryId);
			auto copy_m_optionalWorkOrderId = this->m_optionalWorkOrderId;
			sendWorkOrderInfoData.m_optionalWorkOrderId = marshal_as<std::string>(copy_m_optionalWorkOrderId);
			auto copy_m_optionalBoardId = this->m_optionalBoardId;
			sendWorkOrderInfoData.m_optionalBoardId = marshal_as<std::string>(copy_m_optionalBoardId);
			auto copy_m_optionalBoardIdCreatedBy = this->m_optionalBoardIdCreatedBy;
			sendWorkOrderInfoData.m_optionalBoardIdCreatedBy = marshal_as<std::string>(copy_m_optionalBoardIdCreatedBy);
			auto copy_m_optionalProductTypeId = this->m_optionalProductTypeId;
			sendWorkOrderInfoData.m_optionalProductTypeId = marshal_as<std::string>(copy_m_optionalProductTypeId);
			sendWorkOrderInfoData.m_optionalFailedBoard = static_cast<Hermes::EBoardQuality>(m_optionalFailedBoard);
			sendWorkOrderInfoData.m_optionalFlippedBoard = static_cast<Hermes::EFlippedBoard>(m_optionalFlippedBoard);
			auto copy_m_optionalTopBarcode = this->m_optionalTopBarcode;
			sendWorkOrderInfoData.m_optionalTopBarcode = marshal_as<std::string>(copy_m_optionalTopBarcode);
			auto copy_m_optionalBottomBarcode = this->m_optionalBottomBarcode;
			sendWorkOrderInfoData.m_optionalBottomBarcode = marshal_as<std::string>(copy_m_optionalBottomBarcode);

			sendWorkOrderInfoData.m_optionalLengthInMM = System::Double(0 + m_optionalLengthInMM);
			sendWorkOrderInfoData.m_optionalWidthInMM = System::Double(0 + m_optionalWidthInMM);
			sendWorkOrderInfoData.m_optionalThicknessInMM = System::Double(0 + m_optionalThicknessInMM);
			sendWorkOrderInfoData.m_optionalConveyorSpeedInMMPerSecs = System::Double(0 + m_optionalConveyorSpeedInMMPerSecs);
			sendWorkOrderInfoData.m_optionalTopClearanceHeightInMM = System::Double(0 + m_optionalTopClearanceHeightInMM);
			sendWorkOrderInfoData.m_optionalBottomClearanceHeightInMM = System::Double(0 + m_optionalBottomClearanceHeightInMM);
			sendWorkOrderInfoData.m_optionalWeightInGrams = System::Double(0 + m_optionalWeightInGrams);

			return sendWorkOrderInfoData;
		}

	};
	public ref class GetConfigurationDataWrapper {
	public:
	internal:
		Hermes::GetConfigurationData toNative() {
			Hermes::GetConfigurationData getConfigurationData;

			return getConfigurationData;
		}
	};

	public ref class VerticalServiceSettingsWrapper {
	public:
		String ^m_systemId = "";
		int m_port{ 0 };
		double m_reconnectWaitTimeInSeconds{ 10 };
		double m_checkAlivePeriodInSeconds{ 60 };
		ECheckAliveResponseModeWrapper m_checkAliveResponseMode{ ECheckAliveResponseModeWrapper::eAUTO };

	internal:
		Hermes::VerticalServiceSettings toNative() {
			Hermes::VerticalServiceSettings  verticalServiceSettings;

			auto copy_m_systemId = this->m_systemId;
			verticalServiceSettings.m_systemId = marshal_as<std::string>(copy_m_systemId);
			verticalServiceSettings.m_port = System::UInt16(m_port);
			verticalServiceSettings.m_reconnectWaitTimeInSeconds = System::Double(0 + m_reconnectWaitTimeInSeconds);
			verticalServiceSettings.m_checkAlivePeriodInSeconds = System::Double(0 + m_checkAlivePeriodInSeconds);
			verticalServiceSettings.m_checkAliveResponseMode = static_cast<Hermes::ECheckAliveResponseMode>(m_checkAliveResponseMode);

			return verticalServiceSettings;
		}

	};

}
