// Designed by Lu Xiaomi


#include "GAS/C_BaseGameplayAbility.h"

FGameplayAbilityInfo::FGameplayAbilityInfo():

    CD(0),
	CostType(ECostType::MP),
	CostValue(0),
	IconMaterial(nullptr),
	AbilityClass(nullptr)
{
}

FGameplayAbilityInfo::FGameplayAbilityInfo(float CD, ECostType CostType, float CostValue,
	UMaterialInstance* IconMaterial, TSubclassOf<UC_BaseGameplayAbility> AbilityClass):
CD(CD),
CostType(CostType),
CostValue(CostValue),
IconMaterial(IconMaterial),
AbilityClass(AbilityClass)
{
}

FGameplayAbilityInfo UC_BaseGameplayAbility::GetAbilityInfo(int lever)
{
	UGameplayEffect* CDEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffect = GetCostGameplayEffect();
	float CD = 0;
	float CostValue = 0;
	ECostType CostType = ECostType::MP;
	if (CDEffect && CostEffect)
	{
		CDEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(lever,CD);
		if (CostEffect->Modifiers.Num()>0)
		{
			FGameplayModifierInfo CostEffectModifireInfo = CostEffect->Modifiers[0];
			CostEffectModifireInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(lever,CostValue);
			FString CostTypeName = CostEffectModifireInfo.Attribute.GetName();
			if (CostTypeName == "MP")
			{
				CostType = ECostType::MP;
			}
			if (CostTypeName == "HP")
			{
				CostType = ECostType::HP;
			}
			if (CostTypeName == "Strength")
			{
				CostType = ECostType::Strength;
			}
			return FGameplayAbilityInfo(CD,CostType,CostValue,IconMaterial,GetClass());
		}
	}
	return FGameplayAbilityInfo();
}

void UC_BaseGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	UE_LOG(LogTemp, Warning, TEXT("C++ ActivateAbility called: %s"), *GetClass()->GetName());
}

