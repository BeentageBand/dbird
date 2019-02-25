#pragma once
#include <string>
#include <vector>
#include "checkin-bundle.h"

namespace bird
{
    class Checkin_Bundle_Parser
    {
        public:
        virtual Checkin_Bundle parse_to_checkin_bundle(std::string const & data) = 0;
        virtual std::string parse_to_string(std::vector<Checkin_Bundle> const & checkin_bundles) = 0;
    };
}