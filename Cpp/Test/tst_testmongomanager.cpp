#include "mongomanager.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <QVariant>
#include <QMap>
#include <QList>
using namespace testing;

// -------------------------
// تست اتصال و افزودن داده
// -------------------------
TEST(TestMongoManager, AddAndSearch) {
    MongoManager manager("mongodb://localhost", "27017");
    ASSERT_TRUE(manager.connction());  // بررسی اتصال

    bsoncxx::builder::stream::document doc{};
    doc << "id" << 1
        << "FirstName" << "Ali"
        << "LastName" << "Rezaei"
        << "PhoneNumber" << "09123456789"
        << "email" << "ali@example.com";

    manager.addToDatabase(std::move(doc));

    QList<QVariantMap>  results = manager.search("Ali");
    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0].value("FirstName").toString(), "Ali");


    manager.deleteall();  // پاکسازی داده‌ها بعد از تست
}

// -------------------------
// تست بروزرسانی
// -------------------------
TEST(TestMongoManager, UpdateItem) {
    MongoManager manager("mongodb://localhost", "27017");
    ASSERT_TRUE(manager.connction());

    bsoncxx::builder::stream::document doc{};
    doc << "id" << 2
        << "FirstName" << "Sara"
        << "LastName" << "Ahmadi"
        << "PhoneNumber" << "09112223344"
        << "email" << "sara@example.com";

    manager.addToDatabase(doc);

    manager.updateItem(2, "SaraUpdated", "Ahmadi", "09998887766", "sara@new.com");

    auto results = manager.search("SaraUpdated");
    ASSERT_EQ(results.size(), 1);
    EXPECT_EQ(results[0]["PhoneNumber"].toString(), "09998887766");

    manager.deleteall();
}

// -------------------------
// تست حذف
// -------------------------
TEST(TestMongoManager, DeleteItem) {
    MongoManager manager("mongodb://localhost", "27017");
    ASSERT_TRUE(manager.connction());

    bsoncxx::builder::stream::document doc{};
    doc << "id" << 3
        << "FirstName" << "Mehdi";

    manager.addToDatabase(doc);

    manager.deleteItem(3);

    auto results = manager.search("Mehdi");
    EXPECT_EQ(results.size(), 0);

    manager.deleteall();
}

// -------------------------
// تست پاکسازی همه داده‌ها
// -------------------------
TEST(TestMongoManager, DeleteAll) {
    MongoManager manager("mongodb://localhost", "27017");
    ASSERT_TRUE(manager.connction());

    bsoncxx::builder::stream::document doc1{};
    doc1 << "id" << 4 << "FirstName" << "Test1";
    bsoncxx::builder::stream::document doc2{};
    doc2 << "id" << 5 << "FirstName" << "Test2";

    manager.addToDatabase(doc1);
    manager.addToDatabase(doc2);

    manager.deleteall();

    auto results1 = manager.search("Test1");
    auto results2 = manager.search("Test2");
    EXPECT_EQ(results1.size(), 0);
    EXPECT_EQ(results2.size(), 0);
}
