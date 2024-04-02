#pragma once

#include "Common.hpp"
#include "Components.hpp"

#include <algorithm>
#include <optional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

class GameState
{
    public:
	std::unordered_map<std::string, std::vector<std::optional<Component>>> components;

	uint32_t num_entities;

	GameState(uint32_t num_entities) : num_entities(num_entities)
	{
	}

	template <typename T>
	void add_component()
	{
		components[typeid(T).name()] = std::vector<std::optional<Component>>(num_entities);
	}
};
