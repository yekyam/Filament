#pragma once

#include "Components.hpp"
#include "Macros.hpp"

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

	GameState(uint32_t num_entities)
	{
		components[typeid(Mesh).name()] = std::vector<std::optional<Component>>(num_entities);
	}
};
