/*
 * standalone-component.h
 *
 *  Created on: Sep 14, 2019
 *      Author: roalanis
 */

#ifndef STANDALONE_COMPONENT_H_
#define STANDALONE_COMPONENT_H_

#include "ccjuice/ccjuice.h"
#include "checkin-bundle-parser-json.h"
#include "checkin-bundle-parser-sip-block.h"
#include "connection-manager-app/connection-manager-app.h"
#include "connection-service/connection-http.h"
#include "data-access-service/data-access-persistency.h"
#include "data-reader-service/data-reader-sip.h"
#include "persistency/checkin-bundle-access-fs.h"
#include "push-data-app/push-data-app.h"
#include "read-data-app/read-data-app.h"
#include "server-service/server-modem.h"
#include "sip/sip-mifare.h"

namespace bird {

class StandaloneServiceModule {

public:
	typedef meta::List<
			ccjuice::Provide<service::ConnectionInterface, service::ConnectionHTTP>,
			ccjuice::Provide<service::DataAccessInterface, service::DataAccessPersistency>,
			ccjuice::Provide<service::DataReaderInterface, service::DataReaderSIP>,
			ccjuice::Provide<service::ServerModem>
			> ModuleList;

};
class StandaloneComponent {

public:
	typedef meta::List<
			StandaloneServiceModule
			> ModuleList;
	typedef meta::List<
			application::ConnectionManagerApp,
			application::PushDataApp,
			application::ReadDataApp
			> ComponentList;
};

}

#endif /* STANDALONE_COMPONENT_H_ */
