// Designed by Lu Xiaomi

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "C_BaseAttributeSet.generated.h"

/**
 * 
 */

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class DUSTTOGODS_API UC_BaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attribute_BaseData")
	FGameplayAttributeData HP;
	ATTRIBUTE_ACCESSORS(UC_BaseAttributeSet, HP);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attribute_BaseData")
	FGameplayAttributeData MP;
	ATTRIBUTE_ACCESSORS(UC_BaseAttributeSet, MP);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Attribute_BaseData")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UC_BaseAttributeSet, Strength);

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;
};

