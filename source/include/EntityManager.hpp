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
	if (this->entity_available(e))
	{
		return EntityManager::EntityManagerErrors::EntityDoesNotExist;
	}

	if (typeid(T).name() == typeid(Mesh).name())
	{

#ifdef DEBUG
		auto &m = this->game_state.model_components.at(e);
#else
		auto &m = this->game_state.model_components[e];
#endif
		if (m.has_value())
		{
			return EntityManager::EntityManagerErrors::EntityAlreadyHasThisComponent;
		}

		m = component;

	} else
	{
		return EntityManager::EntityManagerErrors::ComponentDoesNotExist;
	}

	return EntityManager::EntityManagerErrors::Success;
}
