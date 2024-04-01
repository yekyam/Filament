#pragma once

#include "Components.hpp"
#include "GameState.hpp"

#include <algorithm>
#include <deque>
#include <optional>
#include <unordered_map>

using EntityHandle = uint32_t;

class EntityManager
{
	uint32_t num_entities;
	uint32_t max_entities;
	std::deque<EntityHandle> available_handles;

	GameState game_state;

    public:
	enum class EntityManagerErrors {
		Success = 0,
		EntityAlreadyHasThisComponent,
		EntityDoesNotExist,
		ComponentDoesNotExist
	};

	EntityManager(uint32_t max_entities);

	std::optional<EntityHandle> get_new_entity();

	uint32_t get_num_entities();

	uint32_t get_max_entities();

	template <typename T>
	EntityManagerErrors add_component_to_entity(EntityHandle e, const T &component);

	void destroy_entity(EntityHandle e);

	bool entity_available(EntityHandle e);
};

// templates
template <typename T>
EntityManager::EntityManagerErrors EntityManager::add_component_to_entity(EntityHandle e, const T &component)
{

	/* Steps to check if can add componnts to entity
		1) Entity must exist
		2) Component must exist
		3) Entity must not already have component
		4) If 1-3 are true, add component to entity
	 */

	// 1
	if (this->entity_available(e))
	{
		return EntityManager::EntityManagerErrors::EntityDoesNotExist;
	}

	auto component_key = typeid(component).name();
	// 2
	if (!this->game_state.components.contains(component_key))
	{
		return EntityManager::EntityManagerErrors::ComponentDoesNotExist;
	}

	// 3
	auto &opt = this->game_state.components[component_key].at(e);
	if (opt.has_value())
	{
		return EntityManager::EntityManagerErrors::EntityAlreadyHasThisComponent;
	}

	opt = component;

	return EntityManager::EntityManagerErrors::Success;
}
