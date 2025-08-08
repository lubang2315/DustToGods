// Designed by Lu Xiaomi


#include "Controller/C_BasePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"



AC_BasePlayerController::AC_BasePlayerController()
{
	/**把控制器数据复制到服务器端*/
	bReplicates = true;
}

void AC_BasePlayerController::BeginPlay()
{
	Super::BeginPlay();
    /**添加输入映射上下文*/
	check(InputMappingContext);
	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(EnhancedInputSystem);
	EnhancedInputSystem->AddMappingContext(InputMappingContext,0);
	EnhancedInputSystem->AddMappingContext(MouseInputMappingContext,0);
	EnhancedInputSystem->AddMappingContext(JumpInputMappingContext,0);
}

void AC_BasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	/**获取输入组件转换成增强输入组件*/
	UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(InputComponent);
	/**当输入动作函数触发时激发回调函数*/
	EnhancedInput->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AC_BasePlayerController::Move);
	EnhancedInput->BindAction(MouseRotateAction,ETriggerEvent::Triggered,this,&AC_BasePlayerController::MouseRotate);
	EnhancedInput->BindAction(JumpAction,ETriggerEvent::Triggered,this,&AC_BasePlayerController::Jump);
	EnhancedInput->BindAction(JumpAction,ETriggerEvent::Completed,this,&AC_BasePlayerController::EndJump);
}

void AC_BasePlayerController::Move(const struct FInputActionValue& InputActionValue)
{
	/**回调函数获取相关移动参数*/
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotator = GetControlRotation();

	const FVector ForwardDirection = FRotationMatrix(Rotator).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(Rotator).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		/**把移动参数传到Character Movement组件里面去，在动画蓝图直接从人物运动组件中调用就行*/
		ControllerPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControllerPawn->AddMovementInput(RightDirection,InputAxisVector.X);
		
	}
}

inline void AC_BasePlayerController::MouseRotate(const struct FInputActionValue& RotateInputActionValue)
{
	const FVector2D Rotator = RotateInputActionValue.Get<FVector2D>();

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddControllerPitchInput(Rotator.Y*-1.f);
		ControllerPawn->AddControllerYawInput(Rotator.X);
	}
	
}

inline void AC_BasePlayerController::Jump(const struct FInputActionValue& InputActionValue)
{
	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		if (ACharacter* Characters = Cast<ACharacter>(ControllerPawn))
		{
			Characters->Jump();
		}
	}
}
inline void AC_BasePlayerController::EndJump(const struct FInputActionValue& InputActionValue)
{
	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		if (ACharacter* Characters = Cast<ACharacter>(ControllerPawn))
		{
			Characters->StopJumping();
		}
	}
}
