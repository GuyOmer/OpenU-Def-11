#include <gtest/gtest.h>
#include "USocial.h"

class USocialTests : public ::testing::Test {
protected:
    USocial *usocial;
    void SetUp() override {
        usocial = new USocial();
    }
     void TearDown() override {
        delete usocial;
    }
};

TEST_F(USocialTests, SanityUserLifeCycle) {
    auto u= usocial->registerUser("test");
    EXPECT_NE(u, nullptr);
    EXPECT_EQ(usocial->getUserById(u->getId()), u);
    usocial->removeUser(u);
}

TEST_F(USocialTests, DoubleRemove) {
    auto u= usocial->registerUser("test");
    EXPECT_NE(u, nullptr);
    EXPECT_EQ(usocial->getUserById(u->getId()), u);

    usocial->removeUser(u);
    EXPECT_THROW(usocial->removeUser(u);, std::invalid_argument);
}

TEST_F(USocialTests, GetNonExistingUserID) {
    EXPECT_THROW(usocial->getUserById(0), std::invalid_argument);
}