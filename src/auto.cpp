/*
 * @file auto.cpp
 * @brief Source file of autonomous
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

#define L 0
#define R 1

Alpaca::Pid::Settings *settings[2];
TaskHandle tasks[2];

void autonomous() {
	settings[L] = new Alpaca::Pid::Settings(1.5, 0.2, 0.18, *drive::left);
	settings[R] = new Alpaca::Pid::Settings(1.5, 0.2, 0.18, *drive::right);

	tasks[L] = GO(Alpaca::Pid, settings[L], 12 * drive::inch);
	tasks[R] = GO(Alpaca::Pid, settings[R], 12 * drive::inch);

	waitUntil([] () {
	            return taskGetState(tasks[L]) == TASK_SUSPENDED &&
	            taskGetState(tasks[R]) == TASK_SUSPENDED;
						});
} /* autonomous */
