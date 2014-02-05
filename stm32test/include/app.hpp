/*
 * app.hpp
 *
 *  Created on: 05 февр. 2014 г.
 *      Author: pavlov
 */

#ifndef APP_HPP_
#define APP_HPP_

#include <stm32f4xx_conf.h>

#include "FreeRTOS.h"
#include "task.h"

#include "tasks.hpp"

class Application {
public:
	Application() {}

	void init();
	void start();

	void attachTask(pdTASK_CODE taskCode, char * title);
	void attach(Task *task);
};



#endif /* APP_HPP_ */
