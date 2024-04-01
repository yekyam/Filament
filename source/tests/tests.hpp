#pragma once

#include "../include/Components.hpp"
#include "../include/EntityManager.hpp"
#include "../include/Filament.hpp"
#include "../include/GameState.hpp"
#include "../include/Macros.hpp"

namespace Tests {
/* Tests List:
 * 	- be able to create an entity with no issues
 *	- do not be able to create over max entities
 * 	- add a component to an entity
 *  - do not be able to add two component of the same type to one entity
 *  - destory an entity
 *  - check if an entity exists
 */

bool test_null_test()
{
	return false;
}

// Should be able to create an entity with no issues
bool test_create_single_entity()
{
	EntityManager world(1);
	auto entity = world.get_new_entity();
	return entity.has_value();
}

// Should not be able to exceed entity limit
bool test_entity_limit()
{
	int max_entities = 10;
	EntityManager world(max_entities);
	std::optional<EntityHandle> e;

	for (int i = 0; i < max_entities + 1; i++)
	{
		e = world.get_max_entities();
	}
	return !e.has_value();
}

// Should be able to test if entity exists
bool test_entity_exists()
{
	int max_entities = 1;
	EntityManager world(max_entities);

	auto e = world.get_new_entity();

	if (!e.has_value())
		return false;

	return !world.entity_available(*e);
}

// Should be able to add mesh component to entity
bool test_add_mesh_component_to_entity()
{
	EntityManager world(1);
	auto e = world.get_new_entity();

	if (!e.has_value())
		return false;

	auto return_code = world.add_component_to_entity(*e, Mesh{std::vector<Vertex>{}, std::vector<GLushort>{}});
	if (return_code == EntityManager::EntityManagerErrors::Success)
	{
		return true;
	}
	return false;
}

// Should not be able to add duplicate component to entity
bool test_add_duplicate_component_to_entity()
{
	EntityManager world(1);
	auto e = world.get_new_entity();

	if (!e.has_value())
		return false;

	auto return_code = world.add_component_to_entity(*e, Mesh{std::vector<Vertex>{}, std::vector<GLushort>{}});
	if (return_code != EntityManager::EntityManagerErrors::Success)
	{
		return false;
	}

	return_code = world.add_component_to_entity(*e, Mesh{std::vector<Vertex>{}, std::vector<GLushort>{}});
	if (return_code == EntityManager::EntityManagerErrors::Success)
	{
		return false;
	}

	return true;
}

} // namespace Tests