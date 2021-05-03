#include "gtest/gtest.h"

#include "../depthOfMarket/depthOfMarket.h"

TEST(addLine, add_valid_line) {
    auto a = depthOfMarket();
    auto res = a.addLine(1,20.0,100);
//    Проверим, что функция завершилась без ошибок
    ASSERT_EQ(res, 0);
    auto b = a.findLine(1,20.0);
//    Проверим, что мы нашли искомый элемент
    ASSERT_EQ(b.second, 1);

//    Проверим ожидаемое значение цены и объема с имеющимися значениями
    ASSERT_EQ(b.first->first, 20.0);
    ASSERT_EQ(b.first->second, 100);
}

TEST(addLine, try_to_rewrite_existing_data) {
    auto a = depthOfMarket();
    a.addLine(1,1,1);
    auto b = a.addLine(1,1,1);
//    Проверим работу функции при попытке переписать существующие данные
    ASSERT_EQ(b, -1);
}

TEST(changeLine, change_valid_line_data) {
    auto a = depthOfMarket();
    a.addLine(1,1,1);
    auto res = a.changeLine(1,1,0,10,20);
//    Проверим, что функция завершилась без ошибок
    ASSERT_EQ(res, 0);
    auto b = a.findLine(0,10);
//    Проверим, что в мы нашли элемент
    ASSERT_EQ(b.second, 1);

//    Проверим ожидаемое значение цены и объема с имеющимися значениями
    ASSERT_EQ(b.first->first, 10);
    ASSERT_EQ(b.first->second, 20);
}

TEST(changeLine, change_non_existing_line_data) {
    auto a = depthOfMarket();
    auto res = a.changeLine(1,1,20,0,1);
//    Проверим, что функция завершилась c ошибкой
    ASSERT_EQ(res, 0);
    auto b = a.findLine(1,0);
//    Проверим, что в мы действительно вставили элемент
    ASSERT_EQ(b.second, 1);
}

TEST(deleteLine, delete_valid_line) {
    auto a = depthOfMarket();
    a.addLine(1,1,1);
    auto res = a.deleteLine(1,1);
//    Проверим, что функция завершилась без ошибки
    ASSERT_EQ(res, 0);
//  Проверим, что элемент действительно удалился
    auto element = a.findLine(1,1);
    ASSERT_EQ(element.second, 0);
}

TEST(deleteLine, delete_non_existing_line) {
//    Удалим несуществующий элемент
    auto a = depthOfMarket();
    auto res = a.deleteLine(1,1);
//    Проверим, что функция завершилась без ошибки
    ASSERT_EQ(res, -1);
}