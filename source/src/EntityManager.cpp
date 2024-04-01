#include "../include/EntityManager.hpp"

EntityManager::EntityManager(uint32_t max_entities) : max_entities(max_entities), game_state(max_entities)
{

	for (uint32_t i = 0; i < max_entities; i++)
	{
		available_handles.push_back(i);
	}
	num_entities = 0;
}

std::optional<EntityHandle> EntityManager::get_new_entity()
{
	if (this->num_entities == this->max_entities)
		return {};
	this->num_entities++;
	EntityHandle new_entity = this->available_handles.front();
	this->available_handles.pop_front();
	return new_entity;
}

uint32_t EntityManager::get_num_entities()
{
	return num_entities;
}

uint32_t EntityManager::get_max_entities()
{
	return this->max_entities;
}

bool EntityManager::entity_available(EntityHandle e)
{
	return std::find(this->available_handles.begin(), this->available_handles.end(), e) !=
	       this->available_handles.end();
}

void EntityManager::destroy_entity(EntityHandle e)
{
#ifdef DEBUG
	this->game_state.model_components.at(e) = std::nullopt;
#else

	this->game_state.model_components[e] = std::nullopt;
#endif

	this->available_handles.push_front(e);
	num_entities--;
}