/*
 * @file init.cpp
 * @brief Source file of initialization
 *
 * Copyright (C) 2017 Contributors to Alpaca Tech
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../include/robot.hpp"

/*
 * Fix a linking issue
 */
extern "C" {
void __libc_init_array();
void *__dso_handle;
}

void initializeIO() {
	__libc_init_array();
} /* initializeIO */

void initialize() {
	drive::upperLeft  = new Alpaca::Motor(1, 2);
	drive::upperRight = new Alpaca::Motor(-1);
	drive::lowerLeft  = new Alpaca::Motor();
	drive::lowerRight = new Alpaca::Motor(-1);

	sensors::left  = new Alpaca::sensors::Quad(1, false, 2);
	sensors::right = new Alpaca::sensors::Quad(5, true, 6);

	drive::left = new Alpaca::System(sensors::left,
	                                 { drive::upperLeft, drive::lowerLeft });
	drive::right = new Alpaca::System(sensors::right,
	                                  { drive::upperRight, drive::lowerRight });

	Alpaca::init();
} /* initialize */
