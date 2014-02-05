/*
 * tasks.hpp
 *
 *  Created on: 05 февр. 2014 г.
 *      Author: pavlov
 */

#ifndef TASKS_HPP_
#define TASKS_HPP_

#include <stm32f4xx_conf.h>

#include "FreeRTOS.h"
#include "task.h"

class Task {
public:
	Task() {};
	virtual ~Task() {};
	virtual void init() {};
	virtual void impl(void *pvParameters) {};
};

typedef void (Task::*FNMETHOD) (void *);

#endif /* TASKS_HPP_ */
