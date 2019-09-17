#pragma once
#include "gmock/gmock.h"
#include "checkin-bundle.h"
#include "persistency/checkin-bundle-access.h"

class CheckinBundleAccessMock : public persistency::CheckinBundleAccess
{
    public:
    MOCK_METHOD0(empty, bool (void));
    MOCK_METHOD1(push, void (bird::CheckinBundle & checkin_bundle));
    MOCK_METHOD0(pop, bird::CheckinBundle (void));
    MOCK_METHOD0(commit, void (void));
};

