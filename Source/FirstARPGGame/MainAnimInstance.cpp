// Zuocheng Wang


#include "MainAnimInstance.h"
#include "GameFrameWork/CharacterMovementComponent.h"
#include "Main.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	FallingDeadTime = 2.f;
	bIsFallingDead = false;
	bIsDancing1 = false;
	bIsDancing2 = false;

	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			Main = Cast<AMain>(Pawn);
		}
	}
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}

	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);

		MovementSpeed = LateralSpeed.Size();

		bIsInAir = Pawn->GetMovementComponent()->IsFalling();

		// main pointer protection
		if (Main == nullptr)
		{
			Main = Cast<AMain>(Pawn);
		}


		// handling dancing1 animation
		if (Main->bDance1KeyDown)
		{
			bIsDancing1 = true;
		}
		if (!Main->bDance1KeyDown)
		{
			bIsDancing1 = false;
		}

		// handling dancing2 animation
		if (Main->bDance2KeyDown)
		{
			bIsDancing2 = true;
		}
		if (!Main->bDance2KeyDown)
		{
			bIsDancing2 = false;
		}


		// handling falling death
		if (!bIsInAir)
		{
			OnGroundTime = GetWorld()->GetTimeSeconds();
		}
		if (bIsInAir)
		{
			if (GetWorld()->GetTimeSeconds() - OnGroundTime > FallingDeadTime)
			{
				bIsFallingDead = true;
				Main->DecrementHealth(Main->MaxHealth);
				Main->Die();
			}
		}


	}
}