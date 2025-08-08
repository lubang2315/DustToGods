// Designed by Lu Xiaomi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "GAS/C_BaseGameplayAbility.h"
#include "C_BasePlayerCharacter.generated.h"

class AbilitySystemComponent;

//声明_动态_多播_委托_一个参数
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataChangedEvent,float,NewValue);

UCLASS(Abstract)
class DUSTTOGODS_API AC_BasePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AC_BasePlayerCharacter();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintAssignable,Category="Ability")
	FOnDataChangedEvent	OnHPDataChangedEvent;

	UPROPERTY(BlueprintAssignable,Category="Ability")
	FOnDataChangedEvent	OnMPDataChangedEvent;

	UPROPERTY(BlueprintAssignable,Category="Ability")
	FOnDataChangedEvent OnStrengthChangedEvent;

	void OnHPDataChangedDeclare(const FOnAttributeChangeData& Data);

	void OnMPDataChangedDeclare(const FOnAttributeChangeData& Data);

	void OnStrengthChangedDeclare(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintPure,Category="BaseCharacter")
	FGameplayAbilityInfo GameplayAbilityInfo(TSubclassOf<UC_BaseGameplayAbility>AbilityClass,int lever);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Combot")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
    	

};
