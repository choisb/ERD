#include "ERDDevice.h"
#include "ERDItem.h"

AERDDevice::AERDDevice()
{
	bEnableSelect = true;
}

void AERDDevice::Operate(AERDItem* UsedItem)
{
	if (!UsedItem)
		return;

	if (UsedItem == CorrectEffect.Item)
	{
		if (CorrectEffect.PlayEffect.IsBound())
			CorrectEffect.PlayEffect.Execute();
	}
	else
	{
		for (const FDeviceItemEffect& WrongEffect : WrongEffects)
		{
			if (UsedItem == WrongEffect.Item && WrongEffect.PlayEffect.IsBound())
			{
				WrongEffect.PlayEffect.Execute();
				return;
			}
		}
	}
}
