#pragma once
#include "gmock/gmock.h"
#include "sip/sip-interface.h"

class SIPMock : public protocols::SIP_Interface
{
    public:
    MOCK_METHOD0(empty, bool (void));
    MOCK_METHOD0(read, std::string (void));
    MOCK_METHOD1(write, void (std::string const & data));
};
