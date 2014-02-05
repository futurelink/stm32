/*
 * app.cpp
 *
 *  Created on: 05 февр. 2014 г.
 *      Author: pavlov
 */

#include "app.hpp"

void Application::init() {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin =
			GPIO_Pin_12 |
			GPIO_Pin_13 |
			GPIO_Pin_14 |
			GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void Application::start() {
	vTaskStartScheduler();
}

void Application::attach(Task *task) {
	FNMETHOD impl = &Task::impl;

	pdTASK_CODE proc = ((pdTASK_CODE)(task->*impl));
	xTaskCreate(
		proc,
		(signed char *) "test",
		configMINIMAL_STACK_SIZE,
		task,
		2,
		(xTaskHandle *) 0);

}

void Application::attachTask(pdTASK_CODE task, char *title) {
	xTaskCreate(
		task,
		(signed char *) title,
		configMINIMAL_STACK_SIZE,
		NULL,
		2,
		(xTaskHandle *) 0);

}

