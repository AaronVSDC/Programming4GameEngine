#include "Scene.h"
#include "GameObject.h"

#include <algorithm>
#include <memory>

using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(const std::string& name) : m_name(name) {}

Scene::~Scene() = default;

void Scene::add( std::unique_ptr<GameObject> object)
{
	m_pObjects.emplace_back(std::move(object));
}

void Scene::remove(std::unique_ptr<GameObject> object)
{
	m_pObjects.erase(std::remove(m_pObjects.begin(), m_pObjects.end(), object), m_pObjects.end());
}

void Scene::removeAll()
{
	m_pObjects.clear();
}

void Scene::update(float deltaTime)
{
	for(auto& object : m_pObjects)
	{
		object->update(deltaTime);
	}
}

void Scene::fixedUpdate(float fixedTimeStep)
{
	for (auto& object : m_pObjects)
	{
		object->fixedUpdate(fixedTimeStep);
	}
}

void Scene::render() const
{
	for (const auto& object : m_pObjects)
	{
		object->render();
	}
}

