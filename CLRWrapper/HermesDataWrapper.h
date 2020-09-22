#pragma once
#include "HermesData.h"
#include "HermesData.hpp"

using namespace System;
namespace HermesWrapper {

	ref struct ServiceDescriptionData {
		Hermes::ServiceDescriptionData &serviceDescriptionData;
		//ServiceDescriptionData() {};

	};
	ref struct BoardAvailableData {

		Hermes::BoardAvailableData &boardAvailableData(){};

	};
	ref struct RevokeBoardAvailableData {

		Hermes::RevokeBoardAvailableData &revokeBoardAvailableData(){};

	};

	ref struct TransportFinishedData {

		Hermes::TransportFinishedData &transportFinishedData(){};

	};

	ref struct BoardForecastData {

		Hermes::BoardForecastData &boardForecastData(){};

	};
	ref struct  SendBoardInfoData {

		Hermes::SendBoardInfoData &sendBoardInfoData() {};

	};
	ref struct NotificationData {

		Hermes::NotificationData &notificationData() {};

	};
	ref struct CheckAliveData {

		Hermes::CheckAliveData &checkAliveData() {};

	};
	ref struct NotificationData {

		Hermes::NotificationData &notificationData() {};

	};
	ref struct MachineReadyData {

		Hermes::MachineReadyData &machineReadyData() {};

	};
	ref struct RevokeMachineReadyData{

		Hermes::RevokeMachineReadyData &revokeMachineReadyData() {};

	};
	ref struct StartTransportData {

		Hermes::StartTransportData &startTransportData() {};

	};
	ref struct StopTransportData {

		Hermes::StopTransportData &stopTransportData() {};

	};
	ref struct QueryBoardInfoData {

		Hermes::QueryBoardInfoData &queryBoardInfoData() {};

	};
	ref struct SupervisoryServiceDescriptionData {

		Hermes::SupervisoryServiceDescriptionData &supervisoryServiceDescriptionData() {};

	};
	ref struct BoardArrivedData {

		Hermes::BoardArrivedData &boardArrivedData() {};

	};
	ref struct BoardDepartedData {

		Hermes::BoardDepartedData &boardDepartedData() {};

	};
	ref struct QueryWorkOrderInfoData {

		Hermes::QueryWorkOrderInfoData &queryWorkOrderInfoData() {};

	};
	ref struct CurrentConfigurationData {

		Hermes::CurrentConfigurationData &currentConfigurationData() {};

	};
	ref struct SendWorkOrderInfoData {

		Hermes::SendWorkOrderInfoData &sendWorkOrderInfoData() {};

	};
}