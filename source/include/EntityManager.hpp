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
    private:
	uint32_t num_entities;
	uint32_t max_entities;
	std::deque<EntityHandle> available_handles;
	// TODO: make another queue for recently deleted ones to really avoid defrag.

	GameState game_state;

	bool entity_available(EntityHandle e);

    public:
	/** Specifies types of errors some EntityManager functions can return.
	 * Zero is success.
	 */
	enum class EntityManagerErrors {
		Success = 0,
		EntityAlreadyHasThisComponent,
		EntityDoesNotExist,
		ComponentDoesNotExist
	};

	/** Creates and sets up the EntityManager.
	 * \param max_entities The maximum number of entities this EntityManager can create.
	 */
	EntityManager(uint32_t max_entities);

	/** Attempts to get a new entity.
	 * Entities handles are pulled from a queue.
	 * \return An optional. If the optional has a value, it will hold a handle of an Entity.
	 */
	std::optional<EntityHandle> get_new_entity();

	/** Gets the current number of entities.
	 */
	uint32_t get_num_entities();

	/** Gets the maximum number of entities, set by the constructor.
	 */
	uint32_t get_max_entities();

	/** Adds a component to a given entity.
	 * \param e The handle of an entity to add a component.
	 * \param component The component to add to the entity.
	 * \return Zero is success, other errors are detailed in the `EntityManagerErrors` enum class.
	 */
	template <typename T>
	EntityManagerErrors add_component_to_entity(EntityHandle e, const T &component);

	/** Destroys an entity.
	 * Destuction of an entity removes all of its components and adds the handle to the front of the entity handle
	 * queue.
	 * \param e The handle to the entity to destroy.
	 */
	void destroy_entity(EntityHandle e);
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
