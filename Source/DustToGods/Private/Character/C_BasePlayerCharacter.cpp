// Designed by Lu Xiaomi


#include "Character/C_BasePlayerCharacter.h"
#include "GAS/C_BaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


AC_BasePlayerCharacter::AC_BasePlayerCharacter()
{
 
	PrimaryActorTick.bCanEverTick = false;
	
	//先创建一个骨骼网格体子类，然后创建一个附着人物骨骼网格体插槽，最后把碰撞设置为false
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), TEXT("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    /**开始点，以下是测试鼠标控制视角移动*/
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(400.f, 400.f, 400.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}
    /**结束点*/
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
	UAbilitySystemComponent* ASC = this->FindComponentByClass<UAbilitySystemComponent>();
	UC_BaseGameplayAbility* AbilityInfomation = AbilityClass->GetDefaultObject<UC_BaseGameplayAbility>();
	if (AbilityInfomation && ASC)
	{
		return AbilityInfomation->GetAbilityInfo(lever);
		
	}
	return FGameplayAbilityInfo();
}


