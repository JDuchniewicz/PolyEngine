#include <EnginePCH.hpp>

#include <pe/api/input/InputWorldComponent.hpp>

RTTI_DEFINE_COMPONENT(::pe::api::input::InputWorldComponent)

bool pe::api::input::InputWorldComponent::IsPressed(const std::initializer_list<eKey>& list) const
{
	bool result = true;
	for (const eKey& i : list)
		result = result && CurrKey[i];
	return result;
}

bool pe::api::input::InputWorldComponent::IsPressed(const std::initializer_list<eMouseButton >& list) const
{
	bool result = true;
	for (const eMouseButton& i : list)
		result = result && CurrMouseButton[i];
	return result;
}

bool pe::api::input::InputWorldComponent::IsPressed(size_t playerID, eControllerButton button) const
{
	ASSERTE(IsControllerConnected(playerID), "Controller not connected!");
	size_t joystickID = PlayerIDToJoystickID[playerID].Value();
	return Controllers.at(joystickID).CurrButton[button];
}

bool pe::api::input::InputWorldComponent::IsClicked(size_t playerID, eControllerButton button) const
{
	ASSERTE(IsControllerConnected(playerID), "Controller not connected!");
	size_t joystickID = PlayerIDToJoystickID[playerID].Value();
	const ControllerState& controller = Controllers.at(joystickID);
	return controller.CurrButton[button] && !controller.PrevButton[button];
}

bool pe::api::input::InputWorldComponent::IsReleased(size_t playerID, eControllerButton button) const
{
	ASSERTE(IsControllerConnected(playerID), "Controller not connected!");
	size_t joystickID = PlayerIDToJoystickID[playerID].Value();
	const ControllerState& controller = Controllers.at(joystickID);
	return !controller.CurrButton[button] && controller.PrevButton[button];
}

float pe::api::input::InputWorldComponent::GetControllerAxis(size_t playerID, eControllerAxis axis) const
{
	ASSERTE(IsControllerConnected(playerID), "Controller not connected!");
	size_t joystickID = PlayerIDToJoystickID[playerID].Value();
	return Controllers.at(joystickID).CurrAxis[axis];
}

float pe::api::input::InputWorldComponent::GetControllerAxisDelta(size_t playerID, eControllerAxis axis) const
{
	ASSERTE(IsControllerConnected(playerID), "Controller not connected!");
	size_t joystickID = PlayerIDToJoystickID[playerID].Value();
	const ControllerState& controller = Controllers.at(joystickID);
	return controller.CurrAxis[axis] && !controller.PrevAxis[axis];
}

Poly::Dynarray<size_t> pe::api::input::InputWorldComponent::GetConnectedControllersIDs() const
{
	size_t arraySize = GetConnectedControllersCount();
	Poly::Dynarray<size_t> controllersIDs(arraySize);
	for(size_t i = 0; i < PlayerIDToJoystickID.GetSize(); ++i)
	{
		if(PlayerIDToJoystickID[i].HasValue())
		{
			controllersIDs.PushBack(i);
		}
	}
	return controllersIDs;
}

bool pe::api::input::InputWorldComponent::IsControllerConnected(size_t idx) const
{
	return PlayerIDToJoystickID.GetSize() > idx && PlayerIDToJoystickID[idx].HasValue();
}