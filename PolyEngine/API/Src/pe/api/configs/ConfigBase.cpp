#include <EnginePCH.hpp>

#include <pe/api/configs/ConfigBase.hpp>
#include <pe/api/resources/ResourceManager.hpp>

using namespace pe::api::configs;

RTTI_DEFINE_TYPE(pe::api::configs::ConfigBase)

ConfigBase::ConfigBase(const String& displayName, eResourceSource location)
	: DisplayName(displayName), Location(location)
{
}

void ConfigBase::Save()
{
	SerializeToFile(EvaluateFullResourcePath(Location, GetFileName()));
}

void ConfigBase::Load()
{
	DeserializeFromFile(EvaluateFullResourcePath(Location, GetFileName()));
	// For now, ensure newest state of config file.
	Save(); 
}

const String& ConfigBase::GetFileName() const
{
	if (FileName.GetLength() == 0)
	{
		if(Location == eResourceSource::NONE)
			FileName = String(GetTypeInfo().GetTypeName()) + String(".json");
		else
			FileName = String("Configs/") + String(GetTypeInfo().GetTypeName()) + String(".json");
	}
		
	return FileName;
}
