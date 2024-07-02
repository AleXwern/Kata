// Copyright (c) Suunto Oy 2023
#pragma once

#include <stdexcept>
#include <string>

namespace kata
{

class Cell
{
	std::string value;
	bool		marked;

public:
	Cell(void)
	{
		value = "";
		marked = false;
	}

	void setValue(std::string str)
	{
		if (value != "") {
			throw std::runtime_error("cell already defined");
		}
		value = str;
	}

	void setMarked(void)
	{
		marked = true;
	}

	std::string getValue(void)
	{
		return value;
	}

	bool getMark(void)
	{
		return marked;
	}
};

struct Coordinate
{
	int x;
	int y;
};

class BingoBoard
{
	int width;
	int height;

	Cell** newCells;

public:
	BingoBoard(int width, int height) :
		width(width), height(height){
		newCells = new Cell*[width];

		for (int c = 0; c < width; c++) {
			newCells[c] = new Cell[height];
		}
	}

	void defineCell(Coordinate coord, std::string value) {
		for (int c = 0; c < width; c++) {
			for (int r = 0; r < height; r++) {
				if (value == newCells[c][r].getValue())
					throw std::runtime_error(value + " already present at " + std::to_string(c) + "," + std::to_string(r));
			}
		}
		newCells[coord.x][coord.y].setValue(value);
	}

	void markCell(Coordinate coord) {
		if (!isInitialzed()) {
			throw std::runtime_error("board not initialized");
		}
		newCells[coord.x][coord.y].setMarked();
	}

	bool isMarked(Coordinate coord) {
		return newCells[coord.x][coord.y].getMark();
	}

	bool isInitialzed() {
		for (int c = 0; c < width; c++) {
			for (int r = 0; r < height; r++) {
				if (newCells[c][r].getValue() == "")
					return false;
			}
		}

		return true;
	}
};

} /* namespace kata */
