#include "Scene.h"

#ifndef TITLESCENE_H
#define TITLESCENE_H
// The title scene
class TitleScene :
	public Scene
{
public:
	void Init() override;
	void Update(float deltaTime) override;
	void Render() override;
	void Shutdown() override;
};

#endif //TITLESCENE_H
