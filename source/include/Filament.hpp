#pragma once

#include "EntityManager.hpp"

#include <iostream>

class Filament
{

    public:
	void run()
	{
		uint32_t max_entities = 10;
		EntityManager w(max_entities);

		std::optional<EntityHandle> e = w.get_new_entity();

		if (!e.has_value())
		{
			std::cout << "error, you messed up bro\n";
			return;
		}

		auto return_code = w.add_component_to_entity(*e, Mesh{std::vector<Vertex>{}, std::vector<GLushort>{}});
		if (return_code == EntityManager::EntityManagerErrors::Success)
		{
			std::cout << "no error, woo!\n";
		} else
		{
			std::cout << "no good:(" << (int)return_code << "\n";
		}

		return_code = w.add_component_to_entity(*e, Mesh{std::vector<Vertex>{}, std::vector<GLushort>{}});
		if (return_code == EntityManager::EntityManagerErrors::Success)
		{
			std::cout << "no error, woo?\n";
		} else
		{
			std::cout << "Expected behavior, woo!\n";
		}
	}
};