#pragma once
#include "gmock/gmock.h"
#include "checkin-bundle.h"
#include "persistency/checkin-bundle-access.h"

class CheckinBundleAccessMock : public persistency::Checkin_Bundle_Access
{
    public:
    MOCK_METHOD0(empty, bool (void));
    MOCK_METHOD1(push, void (bird::Checkin_Bundle & checkin_bundle));
    MOCK_METHOD0(pop, bird::Checkin_Bundle (void));
    MOCK_METHOD0(commit, void (void));
};

