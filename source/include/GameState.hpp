#pragma once

#include "Components.hpp"

#include <algorithm>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

class GameState
{
    public:
	std::vector<std::optional<Mesh>> model_components;

	GameState(uint32_t num_entities)
	{
		model_components.reserve(num_entities);
	}
};
