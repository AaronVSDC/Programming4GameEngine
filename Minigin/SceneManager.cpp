#include "SceneManager.h"

#include "Minigin.h"
#include "Scene.h"

void dae::SceneManager::update(float deltaTime)
{
	for(auto& scene : m_pScenes)
	{
		scene->update(deltaTime);
	}
}

void dae::SceneManager::fixedUpdate(float fixedTimeStep)
{
	for (auto& scene : m_pScenes)
	{
		scene->fixedUpdate(fixedTimeStep);
	}
}

void dae::SceneManager::render() const
{
	for (const auto& scene : m_pScenes)
	{
		scene->render();
	}
}

dae::Scene* dae::SceneManager::createScene(const std::string& name)
{
	m_pScenes.push_back(std::unique_ptr<Scene>(new Scene(name)));
	return m_pScenes.back().get();
}
