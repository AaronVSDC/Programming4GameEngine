#include <string>
#include "GameObject.h"

#include <iostream>

#include "ResourceManager.h"
#include "Renderer.h"
dae::GameObject::~GameObject() = default;

void dae::GameObject::update(float)
{

}

void dae::GameObject::fixedUpdate(float fixedTimeStep)
{
	std::cout << fixedTimeStep << std::endl; 
}

void dae::GameObject::render() const
{
	const auto& pos = m_transform.getPosition();
	Renderer::getInstance().renderTexture(*m_texture, pos.x, pos.y);
}

void dae::GameObject::setTexture(const std::string& filename)
{
	m_texture = ResourceManager::getInstance().loadTexture(filename);
}

void dae::GameObject::setPosition(float x, float y)
{
	m_transform.setPosition(x, y, 0.0f);
}
