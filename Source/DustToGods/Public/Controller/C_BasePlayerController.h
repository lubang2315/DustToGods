// Designed by Lu Xiaomi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/PlayerController.h"
#include "C_BasePlayerController.generated.h"

class UInputAction;
class UInputMappingContext;
/**
 * 
 */



UCLASS(Abstract)
class DUSTTOGODS_API AC_BasePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	
	AC_BasePlayerController();

protected:
	
	virtual  void BeginPlay() override;
	virtual  void SetupInputComponent() override;

private:
    UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> MouseInputMappingContext;
	
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> MouseRotateAction;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> JumpInputMappingContext;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> JumpAction;

	void Move(const struct FInputActionValue& InputActionValue);

	void MouseRotate(const struct FInputActionValue& RotateInputActionValue);

	void Jump(const struct FInputActionValue& InputActionValue);
	void EndJump(const struct FInputActionValue& InputActionValue);
};





