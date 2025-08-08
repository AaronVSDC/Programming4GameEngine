#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <vector>
#include <string>
#include <memory>
#include "Singleton.h"
#include "Scene.h"
namespace dae
{
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene* createScene(const std::string& name);

		void update(float deltaTime);
		void fixedUpdate(float fixedTimeStep); 
		void render() const;
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::unique_ptr<Scene>> m_pScenes;
	};
}
#endif