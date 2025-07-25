// Designed by Lu Xiaomi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Abilities/GameplayAbility.h"
#include "C_BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DUSTTOGODS_API AC_BaseGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilites;
	
};
