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
	
};
