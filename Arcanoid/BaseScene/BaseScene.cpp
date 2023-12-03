#include "BaseScene.h"

BaseScene::~BaseScene() {
	eventManager.unsubscribe(this);
}