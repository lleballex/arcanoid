﻿#include "App/App.h"

int main() {
	App* app = new App;
	app->run();
	delete app;
}