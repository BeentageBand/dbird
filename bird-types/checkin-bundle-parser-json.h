#ifndef CHECKIN_BUNDLE_PARSER_JSON_H_
#define CHECKIN_BUNDLE_PARSER_JSON_H_
#include <string>
#include "checkin-bundle.h"
#include "checkin-bundle-parser.h"
#include "json/json.h"

namespace bird
{
class CheckinBundleParserJSON : public CheckinBundleParser
{
	static char const * const ACCOUNT_KEY = "account";
	static char const * const TIME_KEY = "timestamp";

public:
	CheckinBundle parse_to_checkin_bundle(std::string const & data)
	{
		Json::Value json_value(data);
		return this->json_to_checkin_bundle(json_value);
	}

	std::vector<CheckinBundle> parse_to_checkin_bundles(std::string const & data)
	{
		Json::Value json_value(data);
		std::vector<CheckinBundle> checkin_bundles;
		for (auto it = json_value.begin(); it != json_value.end(); ++it)
		{
			checkin_bundles.push_back(this->json_to_checkin_bundle(*it));
		}
		return checkin_bundles;
	}

	std::string parse_to_string(std::vector<CheckinBundle> const & checkin_bundles)
	{
		Json::Value json_data;
		for(auto & checkin_bundle : checkin_bundles)
		{
			json_data.append(this->checkin_bundle_to_json(checkin_bundle));
		}
		return json_data.toStyledString();
	}

	std::string parse_to_string(CheckinBundle const & checkin_bundle)
	{
		Json::Value json_value(this->checkin_bundle_to_json(checkin_bundle));
		return json_value.asString();
	}

private:
	CheckinBundle && json_to_checkin_bundle(Json::Value const & json_value)
	{
		Json::Value account_json = json_value.get(ACCOUNT_KEY, "");
		Json::Value time_json = json_value.get(TIME_KEY, "");
		return std::move(CheckinBundle(account_json.asString(), time_json.asString()));
	}

	Json::Value && checkin_bundle_to_json(CheckinBundle const & checkin_bundle)
	{
		Json::Value json_value;
		json_value[ACCOUNT_KEY] = Json::Value(checkin_bundle.get_account_id());
		json_value[TIME_KEY] = Json::Value(checkin_bundle.get_timestamp());
		return std::move(json_value);
	}
};
}

#endif /* CHECKIN_BUNDLE_PARSER_JSON_H_ */
