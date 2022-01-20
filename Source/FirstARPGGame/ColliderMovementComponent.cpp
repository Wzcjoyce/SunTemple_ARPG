// Zuocheng Wang


#include "ColliderMovementComponent.h"

void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}


	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f);

	//Change movement speed!!!!!!!!!!!!!!!!
	DesiredMovementThisFrame *= Speed;
	
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		//this pass into SafeMovementUpdatedComponent function
		// Hit will be filled in with other component when collider hit some other component
		FHitResult Hit;
		SafeMoveUpdatedComponent(
			DesiredMovementThisFrame,
			UpdatedComponent->GetComponentRotation(),
			true,
			Hit
		);

		//If we bump into somthing, slide along the side of it
		//important **************************************
		// allow pawn to slide along a surface
		if (Hit.IsValidBlockingHit())
		{
			UE_LOG(LogTemp, Warning, TEXT("TEST"));
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
		}
	}
}