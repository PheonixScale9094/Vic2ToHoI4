#ifndef HOI4_REGIONS_H
#define HOI4_REGIONS_H



#include <optional>
#include <string>
#include <unordered_map>



namespace HoI4
{

class Regions
{
  public:
	class Factory;
	[[nodiscard]] std::optional<std::string> getRegion(int provinceNumber) const;
	[[nodiscard]] std::optional<std::string> getRegionName(const std::string& region) const;
	[[nodiscard]] std::optional<std::string> getRegionAdjective(const std::string& region) const;

  private:
	std::unordered_map<int, std::string> regionsMap;
	std::unordered_map<std::string, std::string> regionNames;
	std::unordered_map<std::string, std::string> regionAdjectives;
};

} // namespace HoI4



#endif // HOI4_REGIONS_H