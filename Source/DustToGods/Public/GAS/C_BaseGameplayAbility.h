// Designed by Lu Xiaomi

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "C_BaseGameplayAbility.generated.h"




UENUM(BlueprintType)
enum class ECostType : uint8
{
	
	HP,MP,Strength
	
  };

USTRUCT(BlueprintType)
struct FGameplayAbilityInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="AbilityInfo")
	float CD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="AbilityInfo")
	ECostType CostType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="AbilityInfo")
	float CostValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="AbilityInfo")
	UMaterialInstance* IconMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="AbilityInfo")
	TSubclassOf<UC_BaseGameplayAbility> AbilityClass;
	
	FGameplayAbilityInfo();
	FGameplayAbilityInfo(float CD,ECostType CostType,float CostValue,UMaterialInstance* IconMaterial,TSubclassOf<UC_BaseGameplayAbility> AbilityClass);
	
};

/**
 * 
 */
UCLASS()
class DUSTTOGODS_API UC_BaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
	UMaterialInstance* IconMaterial;
	
	UFUNCTION(blueprintCallable, Category="GameplayAbility")
	FGameplayAbilityInfo GetAbilityInfo(int lever);

	
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;
	
};
