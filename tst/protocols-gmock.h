#pragma once
#include "gmock/gmock.h"
#include "http/http-interface.h"
#include "sip/sip-interface.h"

class HTTPMock : public protocols::HTTPInterface
{
    public:
    MOCK_METHOD0(open_session, void (void));
    MOCK_METHOD1(post, void (std::string const & data));
    MOCK_METHOD0(close_session, void (void));
};

class SIPMock : public protocols::SIPInterface
{
    public:
    MOCK_METHOD0(empty, bool (void));
    MOCK_METHOD0(read, std::string (void));
    MOCK_METHOD1(write, void (std::string const & data));
};
