// Zuocheng Wang

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTARPGGAME_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:

	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
	void UpdateAnimationProperties();

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement)
	float MovementSpeed;
	
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement)
	bool bIsInAir;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement)
	class APawn* Pawn;
	
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement)
	class AMain* Main;

	float OnGroundTime;

	float FallingDeadTime;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement)
	bool bIsFallingDead;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement)
	bool bIsDancing1;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement)
	bool bIsDancing2;
};
