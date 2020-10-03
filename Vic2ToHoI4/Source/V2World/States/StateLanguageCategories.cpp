#include "StateLanguageCategories.h"



std::optional<std::string> Vic2::StateLanguageCategories::getStateCategory(const std::string& stateName) const
{
	if (!categories.count(stateName))
	{
		return std::nullopt;
	}

	return categories.at(stateName);
}