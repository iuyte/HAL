/*
 * @file robot.cpp
 * @brief Where the robot comes together
 *
 * Copyright (C) 2017 Ethan Wells
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

namespace sensors {
	Alpaca::sensors::Quad *left, *right, *lift;
}

namespace drive {
	Alpaca::Motor  *upperLeft, *upperRight, *lowerLeft, *lowerRight;
	Alpaca::System *left, *right;
	void set(int l, int r) {
		left->set(l);
		right->set(r);
	} /* set */
}
