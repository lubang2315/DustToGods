// Designed by Lu Xiaomi


#include "Character/C_BasePlayerCharacter.h"
#include "GAS/C_BaseAttributeSet.h"
#include "AbilitySystemComponent.h"


AC_BasePlayerCharacter::AC_BasePlayerCharacter()
{
 
	PrimaryActorTick.bCanEverTick = true;
	
	//先创建一个骨骼网格体子类，然后创建一个附着人物骨骼网格体插槽，最后把碰撞设置为false
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), TEXT("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AC_BasePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	UAbilitySystemComponent* MyAbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	if (MyAbilitySystemComponent)
	{
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UC_BaseAttributeSet::GetHPAttribute()).AddUObject(this,&AC_BasePlayerCharacter::OnHPDataChangedDeclare);
 
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UC_BaseAttributeSet::GetMPAttribute()).AddUObject(this,&AC_BasePlayerCharacter::OnMPDataChangedDeclare);

		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UC_BaseAttributeSet::GetStrengthAttribute()).AddUObject(this,&AC_BasePlayerCharacter::OnStrengthChangedDeclare);
	}
	
}


void AC_BasePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AC_BasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AC_BasePlayerCharacter::OnHPDataChangedDeclare(const FOnAttributeChangeData& Data)
{
	OnHPDataChangedEvent.Broadcast(Data.NewValue);
}

void AC_BasePlayerCharacter::OnMPDataChangedDeclare(const FOnAttributeChangeData& Data)
{
	OnMPDataChangedEvent.Broadcast(Data.NewValue);
}

void AC_BasePlayerCharacter::OnStrengthChangedDeclare(const FOnAttributeChangeData& Data)
{
	OnStrengthChangedEvent.Broadcast(Data.NewValue);
}

FGameplayAbilityInfo AC_BasePlayerCharacter::GameplayAbilityInfo(TSubclassOf<UC_BaseGameplayAbility> AbilityClass,
	int lever)
{
	UAbilitySystemComponent* AbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	UC_BaseGameplayAbility* AbilityInfomation = AbilityClass->GetDefaultObject<UC_BaseGameplayAbility>();
	if (AbilityInfomation && AbilitySystemComponent)
	{
		return AbilityInfomation->GetAbilityInfo(lever);
		
	}
	return FGameplayAbilityInfo();
}


