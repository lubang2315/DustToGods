// Designed by Lu Xiaomi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "C_BasePlayerController_01.generated.h"

/**
 * 
 */
UCLASS()
class DUSTTOGODS_API AC_BasePlayerController_01 : public APlayerController
{
	GENERATED_BODY()
	
virtual void BeginPlay() override;
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="UI")
	TSubclassOf<UUserWidget> UI_PlayerState;
	
private:
	UPROPERTY()
	UUserWidget* GetUIWidget;
};
