// Copyright (c) Suunto Oy 2023

#include <bingoboard.hpp>
#include "catch_amalgamated.hpp"

namespace kata
{
namespace
{

TEST_CASE("anNewlyCreatedBoardIsNotInitialized", "[require]") {
	auto board = BingoBoard(1, 1);
	REQUIRE_FALSE(board.isInitialzed());
}

TEST_CASE("whenAllFieldsAreSetTheBoarIsInitialized", "[require]") {
	std::string anyValue = "42";
	auto board = BingoBoard(1, 1);
	board.defineCell({0, 0}, anyValue);
	REQUIRE(board.isInitialzed());
}

TEST_CASE("whenAllFieldsOnRectangularBoardAreSetItIsInitialized", "[require]") {
	std::string one = "0, 0";
	std::string two = "0, 1";
	auto board = BingoBoard(1, 2);
	board.defineCell({0, 0}, one);
	board.defineCell({0, 1}, two);
	REQUIRE(board.isInitialzed());
}

TEST_CASE("aDefinedCellCantBeRedefinedEvenIfItsTheSameValue", "[require]") {
	std::string anyValue = "42";
	auto board = BingoBoard(1, 1);
	board.defineCell({0, 0}, anyValue);
	REQUIRE_NOTHROW([&]{ board.defineCell({0, 0}, anyValue); });
}

TEST_CASE("duplicateCellsAreNotAllowed", "[require]") {
	std::string anyValue = "42";
	auto board = BingoBoard(2, 2);
	board.defineCell({0, 1}, anyValue);
	REQUIRE_NOTHROW([&]{ board.defineCell({1, 0}, anyValue); });
}

TEST_CASE("aNonInitializedBoardCannotBeMarked", "[require]") {
	auto board = BingoBoard(1, 1);
	REQUIRE_NOTHROW([&]{ board.markCell({0, 0}); });
}

TEST_CASE("whenAllCellGetsMarkedItIsMarked", "[require]") {
	std::string anyValue = "42";
	auto board = BingoBoard(1, 1);
	board.defineCell({0, 0}, anyValue);
	board.markCell({0, 0});
	REQUIRE(board.isMarked({0, 0}));
}

} /* namespace */
} /* namespace kata */
