#include "../Vic2ToHoI4/Source/HOI4World/Map/HoI4Provinces.h"
#include "gtest/gtest.h"
#include <sstream>



TEST(HoI4World_Map_ProvincesTests, MissingMapDefinitionsThrowsException)
{
	std::stringstream input;
	input << R"(HoI4directory = "./HoI4Windows")";
	const auto theConfiguration = Configuration::Factory{}.importConfiguration(input);

	ASSERT_THROW(HoI4::importProvinces(*theConfiguration), std::runtime_error);
}


TEST(HoI4World_Map_ProvincesTests, MapDefinitionsCanBeImported)
{
	std::stringstream input;
	input << R"(HoI4directory = "./HoI4Linux")";
	const auto theConfiguration = Configuration::Factory{}.importConfiguration(input);

	const auto provinces = HoI4::importProvinces(*theConfiguration);

	const std::map<int, HoI4::Province> expectedProvinces{{1, HoI4::Province{false, "lakes"}},
		 {2, HoI4::Province{true, "forest"}}};
	ASSERT_EQ(expectedProvinces, provinces);
}