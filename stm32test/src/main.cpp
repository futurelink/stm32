#include "app.hpp"
#include "tasks.hpp"

#include "ledtask.hpp"

int main(void) {

	Application *app = new Application();
	app->init();

	// Создаем таски по морганию светодиодами
	Task *t1 = new LEDTask(GPIO_Pin_12, 100);
	Task *t2 = new LEDTask(GPIO_Pin_13, 123);
	Task *t3 = new LEDTask(GPIO_Pin_14, 321);
	Task *t4 = new LEDTask(GPIO_Pin_15, 111);

	app->attach(t1, "LED1");
	app->attach(t2, "LED2");
	app->attach(t3, "LED3");
	app->attach(t4, "LED41");

	app->start();

	return 0;
}
