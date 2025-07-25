// Designed by Lu Xiaomi

#include "Blueprint/UserWidget.h"
#include "GameMode/C_BasePlayerController_01.h"

void AC_BasePlayerController_01::BeginPlay()
{
	Super::BeginPlay();
	if (UI_PlayerState)
	{
		GetUIWidget = CreateWidget<UUserWidget>(this ,UI_PlayerState);
		if (GetUIWidget)
		{
			GetUIWidget->AddToViewport(100);
		}
	}
}
