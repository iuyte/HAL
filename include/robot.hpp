/*
 * @file robot.hpp
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

#ifndef ROBOT_H
#define ROBOT_H

#include "main.hpp"

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307
#define GO(func, ...) taskCreate([] (void *none) {                 \
                                   func(__VA_ARGS__);              \
                                   taskSuspend(                    \
                                     NULL);                        \
																 }, TASK_DEFAULT_STACK_SIZE, NULL, \
                                 TASK_PRIORITY_DEFAULT)

namespace sensors {
	extern Alpaca::sensors::Quad *left, *right;
}

namespace drive {
	extern Alpaca::Motor  *upperLeft, *upperRight, *lowerLeft, *lowerRight;
	extern Alpaca::System *left, *right;
	void set(int l,
	         int r);
	static const float inch = 4 * PI;
}

#endif /* end of header include guard: ROBOT_H */
